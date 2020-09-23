#include "IController.h"

LRESULT IController::commonWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    IController* con;

    if (message == WM_NCCREATE) {
        con = static_cast<IController*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
        SetLastError(0);
        if (!SetWindowLongPtr(hWnd, GWL_USERDATA, reinterpret_cast<LONG_PTR>(con))) {
            if (GetLastError() != 0) {
                return FALSE;
            }
        }
    }
    else {
        con = reinterpret_cast<IController*>(GetWindowLongPtr(hWnd, GWL_USERDATA));
    }

    if (con) {
        con->callback(hWnd, message, wParam, lParam);
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}
