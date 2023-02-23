#pragma warning( disable : 4482 )

#include<d3d9.h>
#include<dsound.h>
#include<Game.h>
#include<MessageWrapper.h>

//#include<fstream>  // DEBUG
//std::ofstream logwriter;

int HORIG;
int WORIG;
int W;
int H;

HHOOK KeyboardHook;
bool WindowActive = true;  // je to vùbec potøeba?
STICKYKEYS StartupStickyKeys = {sizeof(STICKYKEYS), 0};
TOGGLEKEYS StartupToggleKeys = {sizeof(TOGGLEKEYS), 0};
FILTERKEYS StartupFilterKeys = {sizeof(FILTERKEYS), 0};

#ifdef _DEBUG 
bool windowed = true;
#else
bool windowed = false;
#endif

#ifdef _LINUX
DWORD auxtime;
#endif

HWND hWnd;
LPDIRECT3D9 D3D = NULL;
LPDIRECT3DDEVICE9 Device = NULL;
LPDIRECTSOUND8 DSound = NULL;
Game * game;
MessageWrapper * mw;

void GetNewResolution()
{
	int aux = (int)(float(WORIG) * 3.0f / 4.0f);  // 4:3
	if (aux == HORIG)
	{
		if (WORIG > 1024)
		{
			W = 1280;
			H = 960;
			return;
		}
		else
		{
			W = 1024;
			H = 768;
			return;
		}
	}

	aux = (int)(float(WORIG) * 10.0f / 16.0f);  // 16:10
	if (aux == HORIG)
	{
		W = 1280;
		H = 800;
		return;
	}

	aux = (int)(float(WORIG) * 9.0f / 16.0f);  // 16:9
	if (aux == HORIG)
	{
		W = 1280;
		H = 720;
		return;
	}

	MessageBox(NULL, "Non-standard resolution, defaulting to 1024 x 768. If you experience any problems, it is your fault for having a weird screen." , "", NULL);
	W = 1024;
	H = 768;
}

HRESULT InitD3D(HWND hWnd)
{
	//if(NULL == (D3D = Direct3DCreate9(D3D_SDK_VERSION)))  // TOTO JE POTØEBA ZMÌNIT (ASI NA 31) ABY TO BÌHALO I NA D3DX9 !!
	//	return E_FAIL;
	if(NULL == (D3D = Direct3DCreate9(31)))  // 31 == D3D9b_SDK_VERSION
		return E_FAIL;

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	//d3dpp.Windowed = FALSE;
	d3dpp.Windowed = windowed;
	//d3dpp.FullScreen_RefreshRateInHz = 60;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWnd;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferWidth = W;
	d3dpp.BackBufferHeight = H;

	// Create the Direct3D device. Here we are using the default adapter (most
	// systems only have one, unless they have multiple graphics hardware cards
	// installed) and requesting the HAL (which is saying we want the hardware
	// device rather than a software one). Software vertex processing is 
	// specified since we know it will work on all cards. On cards that support 
	// hardware vertex processing, though, we would see a big performance gain 
	// by specifying hardware vertex processing.
	if(FAILED(D3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &Device)))
		return E_FAIL;

	// Device state would normally be set here

	return S_OK;
}

HRESULT RestoreOriginal(HWND hwnd)  // je tohle vùbec potøeba?
{
	if (D3D == NULL)
	{
		//if(NULL == (D3D = Direct3DCreate9(D3D_SDK_VERSION)))
		//	return E_FAIL;
		if(NULL == (D3D = Direct3DCreate9(31)))
			return E_FAIL;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = FALSE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWnd;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferWidth = WORIG;
	d3dpp.BackBufferHeight = HORIG;

	if(FAILED(D3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &Device)))
		return E_FAIL;

	Device->Release();
	D3D->Release();
	return S_OK;
}

void Cleanup()
{
	if (DSound) DSound->Release();
	if (Device) Device->Release();
	if (windowed) D3D->Release();
	else RestoreOriginal(hWnd);
}

void Render()
{
#ifdef _LINUX
	if (GetTickCount() - auxtime < 16) return;
	else auxtime = GetTickCount();
#endif

	if (!WindowActive)
	{
		if (game->State == Game::GameState::Running) game->Pause();
		return;  // opravdu nebudeme kreslit?
	}
	mw->Step();

	if (game->devicelost)
	{
		HRESULT result = Device->TestCooperativeLevel();
		switch (result)
		{
		case D3D_OK:
			game->devicelost = false;
			break;

		case D3DERR_DEVICELOST:
			Sleep(100);  // ?
			return;

		case D3DERR_DEVICENOTRESET:
		{
			D3DPRESENT_PARAMETERS d3dpp;
			ZeroMemory(&d3dpp, sizeof(d3dpp));
			d3dpp.Windowed = windowed;
			d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
			d3dpp.hDeviceWindow = hWnd;
			d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
			//d3dpp.FullScreen_RefreshRateInHz = 60;
			d3dpp.BackBufferWidth = W;
			d3dpp.BackBufferHeight = H;

			game->ReleaseTextures();

			if (SUCCEEDED(Device->Reset(&d3dpp)))
			{
				game->ReloadTextures();
				game->devicelost = false;
				break;
			}
			else return;
		}

		default:
			PostQuitMessage(0);
			return;
		}
	}
	game->Render(Device);
}

bool InitDSound(HWND hwnd)
{
	if (FAILED(DirectSoundCreate8(NULL, &DSound, NULL))) return false;
	if (FAILED(DSound->SetCooperativeLevel(hWnd, DSSCL_NORMAL))) return false;
	return true;
}

LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		//case WM_PAINT:
		//	//ValidateRect(hWnd, NULL);
		//	return 0;

			// https://docs.microsoft.com/en-us/windows/win32/inputdev/wm-activate - whenever a window is being activated/deactivated
			// https://docs.microsoft.com/en-us/windows/win32/winmsg/wm-activateapp - when a window belonging to another app is activated/deactivated
		case WM_ACTIVATEAPP:
			if (wParam == TRUE) WindowActive = true;           
			else WindowActive = false;           
			return 0;

		case WM_KEYDOWN:
			mw->AddMessage(wParam);
			return 0;

		case WM_KEYUP:
			mw->RemoveMessage(wParam);
			return 0;

		case WM_LBUTTONDOWN:
			{
				int x = (short)lParam;
				int y = lParam >> 16;
				game->LMBdown(x, y);
				return 0;
			}

		case WM_MOUSEMOVE:
			{
				int x = (short)lParam;
				int y = lParam >> 16;
				game->MouseMove(x, y);
				return 0;
			}

		case WM_LBUTTONUP:
			{
				int x = (short)lParam;
				int y = lParam >> 16;
				game->LMBup(x, y);
				return 0;
			}

		case WM_RBUTTONDOWN:
			{
				int x = (short)lParam;
				int y = lParam >> 16;
				game->RMBdown(x, y);
				return 0;
			}

		case WM_RBUTTONUP:
			{
				int x = (short)lParam;
				int y = lParam >> 16;
				game->RMBup(x, y);
				return 0;
			}
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK KeyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode < 0 || nCode != HC_ACTION)
		return CallNextHookEx(KeyboardHook, nCode, wParam, lParam); 
 
	KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)lParam;
	switch (wParam) 
	{
		case WM_KEYDOWN:  
		case WM_KEYUP:    
		{
			if ((p->vkCode == VK_LWIN) || (p->vkCode == VK_RWIN)) return 1;
		}
	}

	return CallNextHookEx(KeyboardHook, nCode, wParam, lParam);
}

void DisableAccessibility()
{
	SystemParametersInfo(SPI_GETSTICKYKEYS, sizeof(STICKYKEYS), &StartupStickyKeys, 0);
	SystemParametersInfo(SPI_GETTOGGLEKEYS, sizeof(TOGGLEKEYS), &StartupToggleKeys, 0);
	SystemParametersInfo(SPI_GETFILTERKEYS, sizeof(FILTERKEYS), &StartupFilterKeys, 0);

	STICKYKEYS skOff = StartupStickyKeys;
	if ((skOff.dwFlags & SKF_STICKYKEYSON) == 0)
	{
		// Disable the hotkey and the confirmation
		skOff.dwFlags &= ~SKF_HOTKEYACTIVE;
		skOff.dwFlags &= ~SKF_CONFIRMHOTKEY;
 
		SystemParametersInfo(SPI_SETSTICKYKEYS, sizeof(STICKYKEYS), &skOff, 0);
	}
 
	TOGGLEKEYS tkOff = StartupToggleKeys;
	if ((tkOff.dwFlags & TKF_TOGGLEKEYSON) == 0)
	{
		// Disable the hotkey and the confirmation
		tkOff.dwFlags &= ~TKF_HOTKEYACTIVE;
		tkOff.dwFlags &= ~TKF_CONFIRMHOTKEY;
 
		SystemParametersInfo(SPI_SETTOGGLEKEYS, sizeof(TOGGLEKEYS), &tkOff, 0);
	}
 
	FILTERKEYS fkOff = StartupFilterKeys;
	if ((fkOff.dwFlags & FKF_FILTERKEYSON) == 0)
	{
		// Disable the hotkey and the confirmation
		fkOff.dwFlags &= ~FKF_HOTKEYACTIVE;
		fkOff.dwFlags &= ~FKF_CONFIRMHOTKEY;
 
		SystemParametersInfo(SPI_SETFILTERKEYS, sizeof(FILTERKEYS), &fkOff, 0);
	}
}

void EnableAccessibility()
{
	SystemParametersInfo(SPI_SETSTICKYKEYS, sizeof(STICKYKEYS), &StartupStickyKeys, 0);
	SystemParametersInfo(SPI_SETTOGGLEKEYS, sizeof(TOGGLEKEYS), &StartupToggleKeys, 0);
	SystemParametersInfo(SPI_SETFILTERKEYS, sizeof(FILTERKEYS), &StartupFilterKeys, 0);
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR args, INT)
{
	//parse args
	if (args)
	{
		int argpos = 0;
		while (args[argpos])
		{
			if ((args[argpos] == '-') && (args[argpos + 1] == 'w'))
			{
				windowed = true;
				argpos += 2;
				continue;
			}

			++argpos;
		}
	}

#ifndef _LINUX
	KeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL,  KeyboardHookProc, GetModuleHandle(NULL), 0);
	DisableAccessibility();
#endif

	HORIG = GetSystemMetrics(SM_CYSCREEN);
	WORIG = GetSystemMetrics(SM_CXSCREEN);
	if (windowed)
	{
		W = 1024;
		H = 768;
	}
	else GetNewResolution();
	game = new Game(W, H);
	mw = new MessageWrapper(game);
	srand((unsigned int)GetTickCount());

#ifdef _LINUX
	auxtime = GetTickCount() - 100;
#endif

	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = MsgProc;
	wc.hInstance = hInst;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszClassName = "TrilightClass";
	RegisterClassEx(&wc);

	DWORD style = windowed ? WS_OVERLAPPEDWINDOW : (WS_EX_TOPMOST | WS_POPUP);
	hWnd = CreateWindow(LPCSTR("TrilightClass"), LPCSTR("Trilight"), style, 0, 0, W, H, NULL, NULL, hInst, NULL);

	if (hWnd && InitDSound(hWnd) && SUCCEEDED(InitD3D(hWnd)))
	{
		game->InitGame(Device, DSound);
		ShowWindow(hWnd, SW_SHOWDEFAULT);

		MSG msg;
		ZeroMemory(&msg, sizeof(msg));
		while(msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
			{
				//TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				if (game->State == Game::GameState::Quit) break;
				else Render();
			}
		}
		Cleanup();
	}

	delete game;
	delete mw;
	EnableAccessibility();
	UnhookWindowsHookEx(KeyboardHook);
	UnregisterClass("TrilightClass", wc.hInstance);
	return 0;
}