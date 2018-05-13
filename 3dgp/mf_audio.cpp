#include "mf_audio.h"

IMFPMediaPlayer* MFAudioManager::pMFPlayer[AUDIO_MAX_NUM] = { nullptr };
bool MFAudioManager::doLoop[AUDIO_MAX_NUM] = { false };
bool MFAudioManager::isLoaded = false;

MFAudioManager::MFAudioManager()
{

}

MFAudioManager::~MFAudioManager()
{
	MFAudiosRelease();
}

void MFAudioManager::loadAudios(const RESOURCE_DATA a_pData[])
{
	if (!MFAudioManager::isLoaded)
	{
		for (int i = 0; i < AUDIO_MAX_NUM; i++) {
			if (a_pData[i].fileNO >= 0 && a_pData[i].fileName) {
				MFAudioLoad(a_pData[i].fileNO, a_pData[i].fileName);
			}
			if (a_pData[i].fileNO < 0 || a_pData[i].fileName == nullptr) {
				break;
			}
		}
		MFAudioManager::isLoaded = true;
	}
}

void MFAudiosRelease()
{
	for (int i = 0; i < AUDIO_MAX_NUM; i++) {
		if (MFAudioManager::pMFPlayer[i]) {
			MFAudioManager::pMFPlayer[i]->Release();
		}
	}
	//ZeroMemory(data, sizeof(AUDIO_DATA)*AUDIO_MAX_NUM);
}

void MFAudioCheckLoops()
{
	MFP_MEDIAPLAYER_STATE m_state = MFP_MEDIAPLAYER_STATE_EMPTY;
	
	for (int i = 0; i < AUDIO_MAX_NUM; i++) {
		if (MFAudioManager::pMFPlayer[i]) {
			MFAudioManager::pMFPlayer[i]->GetState(&m_state);
			if (m_state == MFP_MEDIAPLAYER_STATE_STOPPED && MFAudioManager::doLoop[i]){
				MFAudioManager::pMFPlayer[i]->Play();
			}
		}
	}
}

void MFAudioLoad(const int a_fileNO, const char* a_pFileName)
{
	const size_t cSize = strlen(a_pFileName) + 1;
	wchar_t *wcFileName = new wchar_t[cSize];

	size_t temp;
	mbstowcs_s(&temp, wcFileName, cSize, a_pFileName, cSize);

	HRESULT hr = MFPCreateMediaPlayer(wcFileName, FALSE, 0, NULL,/* m_hWnd*/NULL, &MFAudioManager::pMFPlayer[a_fileNO]);
	delete[] wcFileName;
	if (FAILED(hr)){
		MessageBox(0, L"MFPCreateMediaPlayer Failed.", L"framework", MB_OK);
		exit(-1);
	}
}

void MFAudioPlay(const int a_fileNO, const bool a_doLoop)
{
	if (MFAudioManager::pMFPlayer[a_fileNO]) {
		MFAudioManager::pMFPlayer[a_fileNO]->Stop();
		MFAudioManager::pMFPlayer[a_fileNO]->Play();
		MFAudioManager::doLoop[a_fileNO] = a_doLoop;
	}
}

void MFAudioContinue(const int a_fileNO)
{
	if (MFAudioManager::pMFPlayer[a_fileNO]) {
		MFAudioManager::pMFPlayer[a_fileNO]->Play();
	}
}

void MFAudioStop(const int a_fileNO)
{
	if (MFAudioManager::pMFPlayer[a_fileNO]) {
		MFAudioManager::pMFPlayer[a_fileNO]->Stop();
		MFAudioManager::doLoop[a_fileNO] = false;
	}
}

void MFAudioPause(const int a_fileNO)
{
	if (MFAudioManager::pMFPlayer[a_fileNO]){
		MFAudioManager::pMFPlayer[a_fileNO]->Pause();
	}
}

bool isMFAudioPlaying(const int a_fileNO)
{
	if (MFAudioManager::pMFPlayer[a_fileNO]) {
		MFP_MEDIAPLAYER_STATE m_state = MFP_MEDIAPLAYER_STATE_EMPTY;
		MFAudioManager::pMFPlayer[a_fileNO]->GetState(&m_state);
		if (m_state == MFP_MEDIAPLAYER_STATE_PLAYING)
		{
			return true;
		}
	}
	return false;
}