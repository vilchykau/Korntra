#pragma once
#include "framework.h"

class IController {
public:
	virtual BOOL CALLBACK callback(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;
};