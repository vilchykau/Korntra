// Another_MVC.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Another_MVC.h"

#include "Controller.h"
#include "View.h"
#include "Model.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка

// Отправить объявления функций, включенных в этот модуль кода:
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    View view;
    Controller cont;
    Model model;

    std::wstring title = L"some title";

    cont.setView(&view);
    cont.setModel(&model);
    model.addView(&view);
    view.setController(&cont);
    view.setModel(&model);

    view.initWindow(hInstance, title);


    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ANOTHERMVC));
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}