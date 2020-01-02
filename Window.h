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

	virtual void OnCreate()=0;
	virtual void OnUpdate()=0;
	virtual void OnDestroy();

	~Window();
protected:
	HWND m_hwnd;
	bool m_is_run;
};

