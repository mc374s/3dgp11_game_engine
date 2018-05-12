#include "framework.h"
#include "blend.h"
#include "sprite_string.h"
#include "mf_audio.h"

#include "Scene.h"

Scene* framework::s_pScene = nullptr;

ID3D11Device*           framework::s_pDevice = NULL;
ID3D11DeviceContext*    framework::s_pDeviceContext = NULL;

ID3D11RenderTargetView*	framework::s_pRenderTargetView = NULL;
ID3D11DepthStencilView*	framework::s_pDepthStencilView = NULL;

CameraData e_camera;
int renderTargetWidth = SCREEN_WIDTH;
int renderTargetHeight = SCREEN_HEIGHT;

//ID3D11RenderTargetView* framework::s_pRenderTargetView = NULL;

bool framework::initialize(HWND hwnd)
{
	//MessageBox(0, L"Initializer called", L"framework", MB_OK);
	m_hWnd = hwnd;
	DXGI_SWAP_CHAIN_DESC descSwapChain;
	ZeroMemory(&descSwapChain, sizeof(descSwapChain));
	descSwapChain.BufferCount = 1;
	descSwapChain.BufferDesc.Width = SCREEN_WIDTH;
	descSwapChain.BufferDesc.Height = SCREEN_HEIGHT;
	descSwapChain.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	descSwapChain.BufferDesc.RefreshRate.Numerator = 60;
	descSwapChain.BufferDesc.RefreshRate.Denominator = 1;
	descSwapChain.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	descSwapChain.OutputWindow = m_hWnd;
	descSwapChain.SampleDesc.Count = 1;
	descSwapChain.SampleDesc.Quality = 0;
	descSwapChain.Windowed = TRUE;

#ifdef _DEBUG
	//createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE,
	};
	UINT numDriverTypes = ARRAYSIZE(driverTypes);

	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0
		/*D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1*/
	};
	UINT numFeatureLevels = ARRAYSIZE(featureLevels);

	for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
	{
		m_driverType = driverTypes[driverTypeIndex];
		hr = D3D11CreateDeviceAndSwapChain(NULL, m_driverType, NULL, createDeviceFlags, featureLevels, numFeatureLevels,
			D3D11_SDK_VERSION, &descSwapChain, &m_pSwapChain, &s_pDevice, &m_featureLevel, &s_pDeviceContext);
		if (SUCCEEDED(hr))
			break;
	}
	if (FAILED(hr)){
		MessageBox(0, L"D3D11CreateDevice Failed.", L"framework", MB_OK);
		exit(-1);
	}
	if (m_featureLevel!=D3D_FEATURE_LEVEL_11_0){
		//MessageBox(0, L"Direct3D Feature Level 11 unsupported.", 0, 0);
		return false;
	}

	// Create a render target view
	ID3D11Texture2D* pBackBuffer = NULL;
	hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	if (FAILED(hr)) {
		MessageBox(0, L"GetBuffer Failed.", L"framework", MB_OK);
		return false;
	}

	//D3D11_RENDER_TARGET_VIEW_DESC descRenderTargetView;

	hr = s_pDevice->CreateRenderTargetView(pBackBuffer, NULL, &s_pRenderTargetView);
	if (pBackBuffer){
		pBackBuffer->Release();
	}
	if (FAILED(hr)) {
		MessageBox(0, L"CreateRenderTargetView Failed.", L"framework", MB_OK);
		return false;
	}

	// Create depth stencil texture
	D3D11_TEXTURE2D_DESC descDepthStencil;
	descDepthStencil.Width = SCREEN_WIDTH;
	descDepthStencil.Height = SCREEN_HEIGHT;
	descDepthStencil.MipLevels = 1;
	descDepthStencil.ArraySize = 1;
	descDepthStencil.Format = DXGI_FORMAT_D24_UNORM_S8_UINT/*DXGI_FORMAT_R32G32B32A32_FLOAT*//*DXGI_FORMAT_R8G8B8A8_UNORM*/;
	descDepthStencil.SampleDesc.Count = 1;
	descDepthStencil.SampleDesc.Quality = 0;
	descDepthStencil.Usage = D3D11_USAGE_DEFAULT;
	descDepthStencil.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	descDepthStencil.CPUAccessFlags = 0;
	descDepthStencil.MiscFlags = 0;

	hr = s_pDevice->CreateTexture2D(&descDepthStencil, NULL, &m_pDepthStencilResource);
	if (FAILED(hr)) {
		MessageBox(0, L"CreateTexture2D Failed.", L"framework", MB_OK);
		exit(-1);
	}

	// Create the depth stencil view
	D3D11_DEPTH_STENCIL_VIEW_DESC descDepthStencilView;
	ZeroMemory(&descDepthStencilView, sizeof(descDepthStencilView));
	descDepthStencilView.Format = descDepthStencil.Format;
	descDepthStencilView.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	descDepthStencilView.Texture2D.MipSlice = 0;
	hr = s_pDevice->CreateDepthStencilView(m_pDepthStencilResource, &descDepthStencilView, &s_pDepthStencilView);
	if (FAILED(hr)) {
		MessageBox(0, L"CreateTexture2DResource Failed.", L"framework", MB_OK);
		return false;
	}
	s_pDeviceContext->OMSetRenderTargets(1, &s_pRenderTargetView, s_pDepthStencilView);

	// Setup the viewport
	D3D11_VIEWPORT vp;
	vp.Width = (FLOAT)SCREEN_WIDTH;
	vp.Height = (FLOAT)SCREEN_HEIGHT;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	s_pDeviceContext->RSSetViewports(1, &vp);


	UINT m4xMsaaQuality;
	s_pDevice->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM/*DXGI_FORMAT_R32G32B32A32_FLOAT*//*DXGI_FORMAT_R8G8B8A8_UNORM*/, 4, &m4xMsaaQuality);

	// Initialzie the blending
	MyBlending::Initialize(s_pDevice);	

	m_pPrimitive3D[0] = new Primitive3D(s_pDevice);
	m_pPrimitive3D[0]->initialize(s_pDevice, GEOMETRY_CUBE);
	m_pPrimitive3D[1] = new Primitive3D(s_pDevice);
	m_pPrimitive3D[1]->initialize(s_pDevice, GEOMETRY_CYLINDER);

	for (auto &p : m_pRenderTargets) {
		p = new RenderTarget(s_pDevice, 900, 950);
	}

	initSprString(s_pDevice);


	return true;
}


void framework::update(float elapsed_time/*Elapsed seconds from last frame*/)
{
	if (s_pScene)
	{
		s_pScene->update(/*elapsed_time*/);
		if (s_pScene->m_pNextScene)
		{
			s_pScene = s_pScene->m_pNextScene;
			s_pScene->update(/*elapsed_time*/);
		}
	}
}

void framework::render(float elapsed_time/*Elapsed seconds from last frame*/)
{
	using namespace DirectX;

	// Test variables
	static double time;
	static CUSTOM3D custom3DTemp;
	static float mX = 0, mY = 0, mZ = 0;
	static float aXY = 0.0f, aZY = 0.0f;
	static float d = 0.65f;
	static float hClosed = -2.0f;
	static XMFLOAT3 focusPos = { 0,0/* + 310 / (float)SCREEN_WIDTH*/,0 };
	/*if (GetAsyncKeyState(VK_LEFT) < 0) {
		aXY -= 0.01f;
	}
	if (GetAsyncKeyState(VK_RIGHT) < 0) {
		aXY += 0.01f;
	}
	if (GetAsyncKeyState(VK_UP) < 0) {
		aZY += 0.01f;
	}
	if (GetAsyncKeyState(VK_DOWN) < 0) {
		aZY -= 0.01f;
	}*/
	if (GetAsyncKeyState('J') < 0) {
		aXY -= 0.01f;
	}
	if (GetAsyncKeyState('L') < 0) {
		aXY += 0.01f;
	}
	if (GetAsyncKeyState('I') < 0) {
		aZY += 0.01f;
	}
	if (GetAsyncKeyState('K') < 0 || GetAsyncKeyState('Y') < 0) {
		aZY -= 0.01f;
	}
	if (GetAsyncKeyState('N') < 0) {
		d += 0.01f;
	}
	if (GetAsyncKeyState('M') < 0) {
		d -= 0.01f;
	}
	//e_camera.upDirection = { sinf(aZY)*sinf(aXY), cosf(aZY), sinf(aZY)*cosf(aXY), 0 };
	//e_camera.eyePosition = { -fabs(d)*cosf(aZY)*sinf(aXY), fabs(d)*sinf(aZY)/* + 310 / (float)SCREEN_WIDTH*/, -fabs(d)*cosf(aZY)*cosf(aXY),0 };

	if (GetAsyncKeyState('1') < 0) {
		e_camera.eyePosition = { 1, 0, 0, 0 };
	}
	if (GetAsyncKeyState('2') < 0) {
		e_camera.upDirection = { 0, 0, 1, 0 };
		e_camera.eyePosition = { 0, 1, 0, 0 };
	}
	if (GetAsyncKeyState('3') < 0) {
		e_camera.eyePosition = { 0, 0, 1, 0 };
	}
	if (GetAsyncKeyState('4') < 0) {
		e_camera.eyePosition = { 0.5f, 0.5f, -0.5f, 0 };
	}

	if (GetAsyncKeyState('0') < 0) {
		mX = mY = mZ = 0;
		aXY = aZY = 0;
		custom3DTemp.clear();
	}
	if (GetAsyncKeyState('R') < 0) {
		custom3DTemp.angleYawPitchRoll = { 0,0,0 };
	}

	if (GetAsyncKeyState('W') < 0) {
		custom3DTemp.angleYawPitchRoll.y += 1;
	}
	if (GetAsyncKeyState('S') < 0) {
		custom3DTemp.angleYawPitchRoll.y -= 1;
	}
	if (GetAsyncKeyState('A') < 0) {
		custom3DTemp.angleYawPitchRoll.x += 1;
	}
	if (GetAsyncKeyState('D') < 0) {
		custom3DTemp.angleYawPitchRoll.x -= 1;
	}
	if (GetAsyncKeyState('Q') < 0) {
		custom3DTemp.angleYawPitchRoll.z += 1;
	}
	if (GetAsyncKeyState('E') < 0) {
		custom3DTemp.angleYawPitchRoll.z -= 1;
	}
	//if (GetAsyncKeyState('Z') < 0) {
	//	mX += 2;
	//	//custom3DTemp.position.z += 6;
	//}
	//if (GetAsyncKeyState('X') < 0) {
	//	mX -= 2;
	//	//custom3DTemp.position.z -= 6;
	//}
	//if (GetAsyncKeyState('C') < 0) {
	//	custom3DTemp.position.y += 6;
	//}
	//if (GetAsyncKeyState('V') < 0) {
	//	custom3DTemp.position.y -= 6;
	//}

	//e_camera.focusPosition = { focusPos.x,focusPos.y,focusPos.z,0 };

	// Change the blending mode 
	if (GetAsyncKeyState(VK_SPACE) < 0)
	{
		blendMode++;
		blendMode %= 9;
	}

	s_pDeviceContext->OMSetRenderTargets(1, &s_pRenderTargetView, s_pDepthStencilView);

	e_camera.viewPort.Width = SCREEN_WIDTH;
	e_camera.viewPort.Height = SCREEN_HEIGHT;
	s_pDeviceContext->RSSetViewports(1, &e_camera.viewPort);

	// Just clear the backbuffer
	float ClearColor[4] = { 0.0f / 255.0f, 111.0f / 255.0f, 129.0f / 255.0f, 1.0f }; //red,green,blue,alpha
	//float ClearColor[4] = { 255.0f / 255.0f, 255.0f / 255.0f, 255.0f / 255.0f, 1.0f }; //red,green,blue,alpha
	s_pDeviceContext->ClearRenderTargetView(s_pRenderTargetView, ClearColor);
	s_pDeviceContext->ClearDepthStencilView(s_pDepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);


	MyBlending::setMode(s_pDeviceContext, BLEND_ALPHA);
	if (s_pScene)
	{
		s_pScene->draw(/*elapsed_time*/);
	}


	// draw XYZ Rectangle Coordinates
	//MyBlending::setMode(s_pDeviceContext, BLEND_NONE);
	//m_pPrimitive3D[0]->drawCube(s_pDeviceContext, XMFLOAT3(1024, 0, 0), XMFLOAT3(2048, 2, 2));
	//m_pPrimitive3D[0]->drawCube(s_pDeviceContext, XMFLOAT3(0, 1024, 0), XMFLOAT3(2, 2048, 2));
	//m_pPrimitive3D[0]->drawCube(s_pDeviceContext, XMFLOAT3(0, 0, 1024), XMFLOAT3(2, 2, 2048));

	//m_pPrimitive3D[1]->drawCylinder(s_pDeviceContext, XMFLOAT3(-100, mY, 10 + mZ), XMFLOAT3(100, 100, 100), &custom3DTemp);


	
	// set02:Just Change the RenderTargetView. TODO: apply multi-RenderTargetView
	//{
	//	MyBlending::setMode(s_pDeviceContext, BLEND_ALPHA);

	//	m_pRenderTargets[0]->render3D(s_pDeviceContext, -900, -950 / 2, 900, 950, 0, 0, 900, 950, 0, 0xFFFFFFFF, &custom3DTemp);

	//	//m_pPrimitive3D[1]->drawCylinder(s_pDeviceContext, XMFLOAT3(-310, mY, 10 + mZ), XMFLOAT3(620, 700, 20), &custom3DTemp);
	//	if (s_pScene)
	//	{
	//		s_pScene->draw(/*elapsed_time*/);
	//	}

	//	s_pDeviceContext->OMSetRenderTargets(1, &s_pRenderTargetView, s_pDepthStencilView);

	//	e_camera.viewPort.Width = SCREEN_WIDTH;
	//	e_camera.viewPort.Height = SCREEN_HEIGHT;
	//	s_pDeviceContext->RSSetViewports(1, &e_camera.viewPort);

	//	custom3DTemp.angleYawPitchRoll.x = -custom3DTemp.angleYawPitchRoll.x;
	//	m_pRenderTargets[1]->render3D(s_pDeviceContext, 0, -950 / 2, 900, 950, 0, 0, 900, 950, 0, 0xFFFFFFFF, &custom3DTemp);
	//	custom3DTemp.angleYawPitchRoll.x = -custom3DTemp.angleYawPitchRoll.x;
	//	if (s_pScene)
	//	{
	//		s_pScene->draw(/*elapsed_time*/);
	//	}
	//	m_pSwapChain->Present(0, 0);
	//}
	//MyBlending::setMode(s_pDeviceContext, BLEND_ALPHA);
	//char buf[256];
	//sprintf_s(buf, "CameraDistance: %lf", d);
	//drawSprString(s_pDeviceContext, 0, 0, buf);

	m_pSwapChain->Present(0, 0);
}

void framework::release()
{

	if (m_pBlendState) m_pBlendState->Release();

	if (s_pDepthStencilView)
	{
		s_pDepthStencilView->Release();
		//MessageBox(0, L"DepthStencilView Released", L"framework", MB_OK);
	}
	if (s_pRenderTargetView) {
		s_pRenderTargetView->Release();
		//MessageBox(0, L"RenderTargetView Released", L"framework", MB_OK);
	}
	if (m_pDepthStencilResource)
	{
		m_pDepthStencilResource->Release();
	}
	if (m_pSwapChain) {
		m_pSwapChain->Release();
		//MessageBox(0, L"SwapChain Released", L"framework", MB_OK);
	}
	if (s_pDeviceContext) {
		s_pDeviceContext->ClearState();
		//MessageBox(0, L"DeviceContext Cleared", L"framework", MB_OK);
		s_pDeviceContext->Release();
		//MessageBox(0, L"DeviceContext Released", L"framework", MB_OK);
	}
	if (s_pDevice) {
		s_pDevice->Release();
		//MessageBox(0, L"Device Released", L"framework", MB_OK);
	}


	if (m_pDepthStencilResource) {
		m_pDepthStencilResource->Release();
	}

	MyBlending::Release();

	releaseSprString();

	for (auto &p : m_pPrimitive3D)
	{
		delete p;
		p = NULL;
	}
	for (auto &p : m_pRenderTargets) {
		delete p;
		p = NULL;
	}
}
