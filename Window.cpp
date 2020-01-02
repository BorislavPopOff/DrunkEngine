#include "Window.h"

Window* window = nullptr;

Window::Window()
{

}

LRESULT CALLBACK WindProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) 
{
	switch(msg)
	{
	case WM_CREATE:
	{
		window->OnCreate();
		break;
	}

	case WM_DESTROY:
	{
		window->OnDestroy();
		::PostQuitMessage(0);
		break;
	}

	default:
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}

	return NULL;
}
bool Window::init()
{
	WNDCLASSEX wc;
	wc.cbClsExtra = NULL;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = NULL;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.hInstance = NULL;
	wc.lpszClassName = "MyWindowClass";
	wc.lpszMenuName = "";
	wc.style = NULL;
	wc.lpfnWndProc = WindProc;

	if (!::RegisterClassEx(&wc))
		return false;

	if (!window)
		window = this;
	
		m_hwnd=::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MyWindowClass", "DirectX Application", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720,
		NULL, NULL, NULL, NULL);
	if (!m_hwnd) 
		return false;
						
		::ShowWindow(m_hwnd, SW_SHOW);
		::UpdateWindow(m_hwnd);
		
		m_is_run = true;
	return true;
}

bool Window::broadcast()
{
	MSG msg;

	while (::PeekMessageA(&msg, NULL, 0, 0 , PM_REMOVE)>0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	window->OnUpdate();

	Sleep(0);

	return true;
}

bool Window::release()
{
	if (!::DestroyWindow(m_hwnd))
	{
		return false;
	}
	return true;
}

bool Window::isRun()
{
	return m_is_run;
}

void Window::OnDestroy()
{
	m_is_run = false;
}

Window::~Window()
{

}
