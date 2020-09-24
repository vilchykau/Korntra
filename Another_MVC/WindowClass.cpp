#include "WindowClass.h"
#include "IController.h"
#include "Resource.h"

WindowClass* WindowClass::inst = nullptr;

WindowClass* WindowClass::getInstance(HINSTANCE hInst)
{
    if (!inst) {
        inst = new WindowClass(hInst);
    }
    return inst;
}

WCHAR* WindowClass::getClass()
{
    return szWindowClass;
}

WindowClass::WindowClass(HINSTANCE hInst)
{
    LoadStringW(hInst, IDC_ANOTHERMVC, szWindowClass, MAX_LOADSTRING);

    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
  //  wcex.lpfnWndProc = WindowClass::commonWndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInst;
    wcex.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ANOTHERMVC));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_ANOTHERMVC);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&wcex);
}

BOOL WindowClass::commonWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	IController* self;
	if (message == WM_INITDIALOG) {
		self = (IController*)lParam;
		SetWindowLongPtr(hWnd, DWLP_USER, lParam);
	}
	else
		self = (IController*)GetWindowLongPtr(hWnd, GWLP_USERDATA);

    if (self)
        return self->callback(hWnd, message, wParam, lParam);

	return 0;
}

