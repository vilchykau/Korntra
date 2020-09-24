// Another_MVC.cpp : Определяет точку входа для приложения.
//


#include "framework.h"
#include "Another_MVC.h"

#include "MVC.h"

void setupMVC(Model& model, View& view, Controller& controller);
int handleLoop(HINSTANCE& hInst);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    View view;
    Controller cont;
    Model model;

    setupMVC(model, view, cont);

    std::wstring title = L"some title";
    view.initWindow(hInstance, title);

	return handleLoop(hInstance);
}

void setupMVC(Model& model, View& view, Controller& controller) {
    controller.setView(&view); // Нужно для WM_CREATE
    controller.setModel(&model);
	model.addSubscriber(&view);
	view.setController(&controller);
	view.setModel(&model);
}

int handleLoop(HINSTANCE& hInst) {
	HACCEL hAccelTable = LoadAccelerators(hInst, MAKEINTRESOURCE(IDC_ANOTHERMVC));
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
    return (int)msg.wParam;
}