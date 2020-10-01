#include "View.h"

#include "WindowClass.h"
#include "Model.h"

void View::initWindow(HINSTANCE hInst, std::wstring& windowName)
{
    mainHwnd = CreateWindowW(WindowClass::getInstance(hInst)->getClass(), windowName.c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInst, cont);

	ShowWindow(mainHwnd, 1);
	UpdateWindow(mainHwnd);
}

void View::initElements(HWND hWnd)
{
	initFirstPFButton(hWnd);
    initFirstInTextbox(hWnd);
    initFirstArrayLabel(hWnd);
    initFirstPBButton(hWnd);
    initFirstPOPFButton(hWnd);
	initFirstPOPBButton(hWnd);

    refreshView();
}

void View::refreshView()
{	
    refreshArrayLable(mainHwnd);
}

HWND View::getMainHwnd()
{
    return mainHwnd;
}

void View::setModel(Model* model)
{
    this->model = model;
}

void View::initFirstPFButton(HWND hWnd)
{
    CreateWindow(
        L"BUTTON",  
        L"Push forward",     
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 
        10,         
        10,         
        100,        
        30,        
        hWnd,
        (HMENU) ID_FIRST_PF_BUTTON,      
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        cont);     
}

void View::initFirstInTextbox(HWND hWnd)
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
        (HMENU) ID_FIRST_NEW_ELEMENT_TEXTBOX,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        cont);
}

void View::initFirstArrayLabel(HWND hWnd)
{
    CreateWindow(L"static", L"",
        WS_CHILD | WS_VISIBLE | WS_TABSTOP,
        10, 100, 360, 50,
        hWnd, (HMENU)ID_FIRST_ARRAY_LABEL,
        (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), cont);
}

void View::initFirstPBButton(HWND hWnd)
{
	CreateWindow(
		L"BUTTON",
		L"Push backward",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		270,
		10,
		100,
		30,
		hWnd,
		(HMENU)ID_FIRST_PB_BUTTON,
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		cont);
}

void View::initFirstPOPFButton(HWND hWnd)
{
	CreateWindow(
		L"BUTTON",
		L"Pop forward",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		10,
		50,
		100,
		30,
		hWnd,
		(HMENU)ID_FIRST_POPF_BUTTON,
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		cont);
}

void View::initFirstPOPBButton(HWND hWnd)
{
	CreateWindow(
		L"BUTTON",
		L"Pop back",
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		270,
		50,
		100,
		30,
		hWnd,
		(HMENU)ID_FIRST_POPB_BUTTON,
		(HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
		cont);
}

void View::refreshArrayLable(HWND hWnd)
{
    SetDlgItemText(hWnd, ID_FIRST_ARRAY_LABEL, model->getArrayLabel().c_str());
}

void View::setController(IController* cont)
{
	this->cont = cont;
}
