#pragma once
#include <Windows.h>
class Window
{

public:
	Window();

	bool init();
	bool broadcast();
	bool release();
	bool isRun();

	virtual void OnCreate();
	virtual void OnUpdate();
	virtual void OnDestroy();

	~Window();
protected:
	HWND m_hwnd;
	bool m_is_run;
};

