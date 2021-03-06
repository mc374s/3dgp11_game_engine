﻿#include "3dgp_system.h"


#include "framework.h"
#include "../game.h"
#include "../sound_data.h"
#include "../sprite_data.h"
#include "../scene_main.h"
#include <thread>


void loadTextureProgress()
{
	pTextureManager->loadTextures(e_loadTexture);		// 2D画像の一括ロード
}

//void loadTextureProgressLarge()
//{
//	pTextureManager->loadTexture(e_loadTexture,TEX_PLAYER_LARGE);		// 2D画像ロード
//}

LRESULT CALLBACK fnWndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	framework *f = reinterpret_cast<framework*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	return f ? f->handle_message(hwnd, msg, wparam, lparam) : DefWindowProc(hwnd, msg, wparam, lparam);
}

INT WINAPI wWinMain(HINSTANCE instance, HINSTANCE prev_instance, LPWSTR cmd_line, INT cmd_show)
{
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
//#endiferdc
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = fnWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = instance;
	wcex.hIcon = 0;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	//wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = _T("3dgp");
	wcex.hIconSm = 0;
	RegisterClassEx(&wcex);

	//MessageBox(0, L"main.cpp run", L"main", MB_OK);
	pMFAudioManager->loadAudios(audio_data);

	RECT rc = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	HWND hwnd = CreateWindow(_T("3dgp"), _T(""), WS_OVERLAPPEDWINDOW ^ WS_MAXIMIZEBOX ^ WS_THICKFRAME | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, instance, NULL);

	framework f(hwnd);

	srand(unsigned int(time(NULL)));
	pTextureManager->loadTextures(e_loadTexture);		// 2D画像の一括ロード

	//std::thread loadThread_1(loadTextureProgress);
	//std::thread loadThread_2(loadTextureProgressLarge);
	//loadThread_1.join();
	//loadThread_1.detach();
	//loadThread_2.detach();
	//pTextureManager->loadTextures(e_loadTexture);
	//pMFAudioManager->loadAudios(audio_data);
	// Set the Init Scene
	framework::changeScene(SCENE_MAIN);


	ShowWindow(hwnd, cmd_show);
	SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(&f));
	return f.run();
}
