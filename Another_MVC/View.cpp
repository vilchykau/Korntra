#include "View.h"

#include "WindowClass.h"

void View::initWindow(HINSTANCE hInst, std::wstring& windowName)
{
	HWND hWnd = CreateWindowW(WindowClass::getInstance(hInst)->getClass(), windowName.c_str(), 
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInst, cont);

	ShowWindow(hWnd, 1);
	UpdateWindow(hWnd);
}

void View::initElements(HWND hWnd)
{
	initAddButton(hWnd);
    initTextIn(hWnd);
}

void View::handleEvent()
{	
}

void View::initAddButton(HWND hWnd)
{
    CreateWindow(
        L"BUTTON",  
        L"Add",     
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
        10,         
        10,         
        100,        
        30,        
        hWnd,
        (HMENU) H_ADD_BUTTON,      
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        cont);     
}

void View::initTextIn(HWND hWnd)
{
    CreateWindow(
        L"EDIT",
        L"",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_AUTOHSCROLL | ES_WANTRETURN, 
        120, 
        10, 
        140, 
        30, 
        hWnd, 
        (HMENU) H_ADD_TEXT_BOX,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        cont);
}

void View::setController(IController* cont)
{
	this->cont = cont;
}
