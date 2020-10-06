#include "Controller.h"

LRESULT Controller::callback(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        
        switch (wmId)
        {
        case View::ID_FIRST_PF_BUTTON:
            onFirstPFButtonClick(hWnd, message, wParam, lParam);
            break;
        case View::ID_FIRST_PB_BUTTON:
            onFirstPBButtonClick(hWnd, message, wParam, lParam);
            break;
        case View::ID_FIRST_POPF_BUTTON:
            onFirstPopFButtonClick(hWnd, message, wParam, lParam);
            break;
		case View::ID_FIRST_POPB_BUTTON:
			onFirstPopBButtonClick(hWnd, message, wParam, lParam);
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

void Controller::setModel(Model* model)
{
    this->model = model;
}

std::wstring Controller::readString(HWND hWnd, int id)
{
	const size_t MAX_TEXT_SIZE = 100;
	WCHAR text[MAX_TEXT_SIZE];
	GetDlgItemText(hWnd, View::ID_FIRST_NEW_ELEMENT_TEXTBOX, text, MAX_TEXT_SIZE);
    return std::wstring(text);
}

void Controller::onFirstPFButtonClick(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    const std::wstring data = readString(hWnd, View::ID_FIRST_NEW_ELEMENT_TEXTBOX);
    if (!data.empty()) {
        model->firstPushFront(data);
    }
}

void Controller::onFirstPBButtonClick(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	const std::wstring data = readString(hWnd, View::ID_FIRST_NEW_ELEMENT_TEXTBOX);
	if (!data.empty()) {
		model->firstPushBack(data);
	}
}

void Controller::onFirstPopFButtonClick(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    model->firstPopFront();
}

void Controller::onFirstPopBButtonClick(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    model->firstPopBack();
}