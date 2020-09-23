#include "Controller.h"

LRESULT Controller::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        
        switch (wmId)
        {
        case View::H_ADD_BUTTON:
            onAddButtonClick(hWnd, message, wParam, lParam);
            break;
        default:
            break;
        }

    }
    break;
    case WM_CREATE:
        view->initElements(hWnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }

    return 0;
}

void Controller::setView(View* view)
{
	this->view = view;
}

void Controller::onAddButtonClick(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    MessageBox(hWnd, L"Add button has been clicked.", L"Message", MB_OK);
}
