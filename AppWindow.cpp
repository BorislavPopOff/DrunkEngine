#include "AppWindow.h"

AppWindow::AppWindow()
{
}

AppWindow::~AppWindow()
{
}

void AppWindow::OnCreate()
{
	Window::OnCreate();

	GraphicsEngine::get()->init();
}

void AppWindow::OnUpdate()
{

	Window::OnUpdate();

}

void AppWindow::OnDestroy()
{
	
	Window::OnDestroy();
    
	GraphicsEngine::get()->release();

}
