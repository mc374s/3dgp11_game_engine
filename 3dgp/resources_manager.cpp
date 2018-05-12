#include "resources_manager.h"
#include <cstdio>

using namespace MyResourcesManager;

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// 画像データの管理
int ResourcesManager::s_imgFileCounter = 0;
D3D11_RESOURCES<ID3D11ShaderResourceView*> ResourcesManager::s_SRVResources[FILE_NUM_MAX];

int MyResourcesManager::loadShaderResourceView(ID3D11Device* a_pDevice, char* a_pFilename, ID3D11Resource** a_ppOutResource, ID3D11ShaderResourceView** a_ppOutSRV) {
	int fileNO = 0;

	// すでに存在しているリソース
	for (fileNO = 0; fileNO < ResourcesManager::s_imgFileCounter; fileNO++)
	{
		if (ResourcesManager::s_SRVResources[fileNO].pFileName == a_pFilename)
		{
			//　リソースを _resource に返す
			ResourcesManager::s_SRVResources[fileNO].pData->GetResource(a_ppOutResource);
			ResourcesManager::s_SRVResources[fileNO].fileRefNum++;
			break;
		}
	}

	//　新規リソース
	if (fileNO == ResourcesManager::s_imgFileCounter)
	{
		const size_t cSize = strlen(a_pFilename) + 1;
		wchar_t *wcFileName = new wchar_t[cSize];
		size_t temp;
		mbstowcs_s(&temp, wcFileName, cSize, a_pFilename, cSize);
		HRESULT hr = DirectX::CreateWICTextureFromFile(a_pDevice, wcFileName, a_ppOutResource, &ResourcesManager::s_SRVResources[fileNO].pData);
		delete[] wcFileName;
		if (FAILED(hr))
		{
			MessageBox(0, L"CreateWICTextureFromFile Filed!", L"MyResourceManager::loadResource()", MB_OK);
			return -1;
		}
		ResourcesManager::s_SRVResources[fileNO].pFileName = a_pFilename;
		ResourcesManager::s_SRVResources[fileNO].fileRefNum++;

		ResourcesManager::s_imgFileCounter++;

	}
	// SRV出力
	*a_ppOutSRV = ResourcesManager::s_SRVResources[fileNO].pData;

	//　リソースの番号を返す
	return fileNO;
}
// リソースを解放
void MyResourcesManager::releaseShaderResourceView(ID3D11ShaderResourceView* a_pInSRV) {
	if (a_pInSRV)
	{
		for (int i = 0; i < ResourcesManager::s_imgFileCounter; i++)
		{
			if (ResourcesManager::s_SRVResources[i].pData == a_pInSRV)
			{
				ResourcesManager::s_SRVResources[i].release();
				break;
			}
		}
	}
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// バーティクスシェーダーソースの管理
int ResourcesManager::s_vsFileCounter = 0;
D3D11_RESOURCES<ID3D11VertexShader*> ResourcesManager::s_vertexShaderResources[FILE_NUM_MAX];
ID3D11InputLayout* ResourcesManager::s_inputLayoutResources[FILE_NUM_MAX];

int MyResourcesManager::loadVertexShader(ID3D11Device* a_pDevice, char* a_pFilename, D3D11_INPUT_ELEMENT_DESC* a_pInLayoutDesc, int a_elementsNum, ID3D11VertexShader** a_ppOutVertexShader, ID3D11InputLayout** a_ppOutInputLayout)
{
	int fileNo = 0;

	// すでに存在しているリソース
	for (fileNo = 0; fileNo < ResourcesManager::s_vsFileCounter; fileNo++)
	{
		if (ResourcesManager::s_vertexShaderResources[fileNo].pFileName == a_pFilename)
		{
			ResourcesManager::s_vertexShaderResources[fileNo].fileRefNum++;
			break;
		}
	}

	//　新規リソース
	if (fileNo == ResourcesManager::s_vsFileCounter)
	{
		unsigned char *cso_data = NULL;
		UINT cso_sz;

		FILE *fp = NULL;
		if (fopen_s(&fp, a_pFilename, "rb") != 0)
			MessageBox(0, L"sprite: Initialize open vs file failed", 0, 0);
		fseek(fp, 0, SEEK_END);
		cso_sz = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		cso_data = new unsigned char[cso_sz];
		fread(cso_data, cso_sz, 1, fp);
		fclose(fp);
		// Create the vertex shader
		HRESULT hr = a_pDevice->CreateVertexShader(cso_data, cso_sz, NULL, &ResourcesManager::s_vertexShaderResources[fileNo].pData);
		if (FAILED(hr))
		{
			MessageBox(0, L"CreateVertexShader failed", L"ResourceManager::loadVertexShader()", MB_OK);
			return -1;
		}

		// Create the input layout
		hr = a_pDevice->CreateInputLayout(a_pInLayoutDesc, a_elementsNum, cso_data, cso_sz, &ResourcesManager::s_inputLayoutResources[fileNo]);
		if (FAILED(hr))
		{
			MessageBox(0, L"CreateInputLayout failed", L"ResourceManager::loadVertexShader()", MB_OK);
			return -1;
		}
		delete[] cso_data;

		ResourcesManager::s_vertexShaderResources[fileNo].pFileName = a_pFilename;
		ResourcesManager::s_vertexShaderResources[fileNo].fileRefNum++;
		ResourcesManager::s_vsFileCounter++;
	}

	// VertexShaderとInputLayoutの出力
	*a_ppOutVertexShader = ResourcesManager::s_vertexShaderResources[fileNo].pData;
	*a_ppOutInputLayout = ResourcesManager::s_inputLayoutResources[fileNo];

	//　リソースの番号を返す
	return fileNo;
};


void MyResourcesManager::releaseVertexShader(ID3D11VertexShader* a_pInVertexShader, ID3D11InputLayout* a_pInInputLayout) {
	if (a_pInVertexShader)
	{
		for (int i = 0; i < ResourcesManager::s_vsFileCounter; i++)
		{
			if (ResourcesManager::s_vertexShaderResources[i].pData == a_pInVertexShader)
			{
				ResourcesManager::s_vertexShaderResources[i].release();
				if (ResourcesManager::s_vertexShaderResources[i].fileRefNum <= 0)
				{
					SAFE_RELEASE(ResourcesManager::s_inputLayoutResources[i]);
				}
				break;
			}
		}
	}
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
// ピクセルシェーダーソースの管理
int ResourcesManager::s_psFileCounter = 0;
D3D11_RESOURCES<ID3D11PixelShader*> ResourcesManager::s_pixelShaderResources[FILE_NUM_MAX];

int MyResourcesManager::loadPixelShader(ID3D11Device* a_pDevice, char* a_pFilename, ID3D11PixelShader** a_ppOut)
{
	int fileNo = 0;

	// すでに存在しているリソース
	for (fileNo = 0; fileNo < ResourcesManager::s_psFileCounter; fileNo++)
	{
		if (ResourcesManager::s_pixelShaderResources[fileNo].pFileName == a_pFilename)
		{
			ResourcesManager::s_pixelShaderResources[fileNo].fileRefNum++;
			break;
		}
	}

	//　新規リソース
	if (fileNo == ResourcesManager::s_psFileCounter)
	{
		unsigned char *cso_data = NULL;
		UINT cso_sz;

		FILE *fp = NULL;
		if (fopen_s(&fp, a_pFilename, "rb") != 0)
			MessageBox(0, L"sprite: Initialize open vs file failed", 0, 0);
		fseek(fp, 0, SEEK_END);
		cso_sz = ftell(fp);
		fseek(fp, 0, SEEK_SET);

		cso_data = new unsigned char[cso_sz];
		fread(cso_data, cso_sz, 1, fp);
		fclose(fp);
		// Create the pixel shader
		HRESULT hr = a_pDevice->CreatePixelShader(cso_data, cso_sz, NULL, &ResourcesManager::s_pixelShaderResources[fileNo].pData);
		if (FAILED(hr))
		{
			MessageBox(0, L"sprite: CreatePixelShader failed", 0, 0);
			return false;
		}
		delete[] cso_data;

		// リソースカウンタアップ
		ResourcesManager::s_pixelShaderResources[fileNo].pFileName = a_pFilename;
		ResourcesManager::s_pixelShaderResources[fileNo].fileRefNum++;
		ResourcesManager::s_psFileCounter++;
	}
	// PixelShader Data出力
	*a_ppOut = ResourcesManager::s_pixelShaderResources[fileNo].pData;
	//　リソースの番号を返す
	return fileNo;

}

void MyResourcesManager::releasePixelShader(ID3D11PixelShader* a_pIn) {
	if (a_pIn)
	{
		for (int i = 0; i < ResourcesManager::s_psFileCounter; i++)
		{
			if (ResourcesManager::s_pixelShaderResources[i].pData == a_pIn)
			{
				ResourcesManager::s_pixelShaderResources[i].release();
				break;
			}
		}
	}
}