#ifndef _FRAMEWORK_H_
#define _FRAMEWORK_H_

#include "3dgp_system.h"

#include "sprite.h"

#include "primitive3d.h"
#include <ctime>

#include "render_target.h"

#pragma comment(lib, "winmm")

#define N 60

class Scene;

class framework
{
private:
	static Scene* s_pScene;

public:
	static void changeScene(Scene* a_pNextScene) {
		if (a_pNextScene)
		{
			s_pScene = a_pNextScene;
		}
	};

	

public:
	HWND m_hWnd = NULL;
	/*static CONST LONG SCREEN_WIDTH = SCREEN_WIDTH;
	static CONST LONG SCREEN_HEIGHT = SCREEN_HEIGHT;*/

	HRESULT hr;

	UINT createDeviceFlags = 0;

	static ID3D11Device*			s_pDevice;
	static ID3D11DeviceContext*		s_pDeviceContext;

	static ID3D11RenderTargetView*	s_pRenderTargetView;
	static ID3D11DepthStencilView*	s_pDepthStencilView;

	D3D_DRIVER_TYPE					m_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL				m_featureLevel = D3D_FEATURE_LEVEL_11_0;
	IDXGISwapChain*					m_pSwapChain = NULL;
	ID3D11Texture2D*				m_pDepthStencilResource = NULL;
	ID3D11BlendState*				m_pBlendState = NULL;

	Primitive3D *m_pPrimitive3D[20];

	RenderTarget *m_pRenderTargets[20];

	int blendMode = 1;
	float m_alpha = 255.0f;
	const char strBlendMode[16][16] = {
		"NONE",
		"ALPHA",
		"ADD",
		"SUBTRACT",
		"REPLACE",
		"MULTIPLY",
		"LIGHTEN",
		"DARKEN",
		"SCREEN"
	};

	framework(HWND hwnd) /*: hwnd(hwnd)*/
	{
		//MessageBox(0, L"Constructor called", L"framework", MB_OK);
		if (!initialize(hwnd))
		{
			MessageBox(0, L"run: Iniialize FAILED", 0, 0);
			return;
		}
	}
	~framework()
	{
		release();
	}
	int run()
	{
		MSG msg = {};

		/*if (!initialize(m_hWnd))
		{
		MessageBox(0, L"run: Iniialize FAILED", 0, 0);
		return 0;
		}*/
		srand((unsigned int)time(NULL));

		DWORD preTime;
		while (WM_QUIT != msg.message)
		{
			KEY_TRACKER.Reset();
			KEY_BOARD = e_pKeyboard->GetState();
			KEY_TRACKER.Update(KEY_BOARD);
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			} else
			{
				
				preTime = timeGetTime();
				m_timer.tick();
				calculate_frame_stats();

				update(m_timer.time_interval());
				render(m_timer.time_interval());

				//Sleep(1000.0 / 60.0 - GetCurrentTime() + preTime);

				//lastTime = GetTickCount()*6;
				while ((timeGetTime() - preTime) * 6 < 100 /*0.0 / 60.0*/) {
					Sleep(1);		// ƒtƒŒ[ƒ€ŽžŠÔ‚ð‰z‚¦‚é‚Ü‚Å‘Ò‚Â
				}

				//preTime += 100;
			}
		}
		return static_cast<int>(msg.wParam);
	}

	LRESULT CALLBACK handle_message(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		switch (msg)
		{
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc;
			hdc = BeginPaint(hwnd, &ps);
			EndPaint(hwnd, &ps);
			break;
		}
		case WM_ACTIVATEAPP:
			Keyboard::ProcessMessage(msg, wparam, lparam);
			break;
		case WM_KEYDOWN:
			if (wparam == VK_ESCAPE) PostMessage(hwnd, WM_CLOSE, 0, 0);
		case WM_SYSKEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYUP:
			Keyboard::ProcessMessage(msg, wparam, lparam);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_CREATE:
			break;
		case WM_ENTERSIZEMOVE:
			// WM_EXITSIZEMOVE is sent when the user grabs the resize bars.
			m_timer.stop();
			break;
		case WM_EXITSIZEMOVE:
			// WM_EXITSIZEMOVE is sent when the user releases the resize bars.
			// Here we reset everything based on the new window dimensions.
			m_timer.start();
			break;
		default:
			return DefWindowProc(hwnd, msg, wparam, lparam);
		}
		return 0;
	}

private:

	bool initialize(HWND hwnd);
	void update(float elapsed_time = .0f/*Elapsed seconds from last frame*/);
	void render(float elapsed_time = .0f/*Elapsed seconds from last frame*/);
	void release();

private:
	high_resolution_timer m_timer;
	void calculate_frame_stats()
	{
		// Code computes the average frames per second, and also the 
		// average time it takes to render one frame.  These stats 
		// are appended to the window caption bar.
		static int frames = 0;
		static float time_tlapsed = 0.0f;

		frames++;

		// Compute averages over one second period.
		if ((m_timer.time_stamp() - time_tlapsed) >= 1.0f)
		{
			float fps = static_cast<float>(frames); // fps = frameCnt / 1
			float mspf = 1000.0f / fps;
			std::ostringstream outs;
			outs.precision(6);
			outs << "FPS : " << fps << " / " << "Frame Time : " << mspf << " (ms)";

			/*outs.precision(4);
			outs<< " #Blending Mode: " << strBlendMode[blendMode] << " #Alpha: " << alpha << " / 255.0f ( " << alpha / 255.0f * 100 << "% )";*/
			SetWindowTextA(m_hWnd, outs.str().c_str());

			// Reset for next average.
			frames = 0;
			time_tlapsed += 1.0f;
		}
	}
};


#endif // !_FRAMEWORK_H_