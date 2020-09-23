#pragma once
#include "framework.h"

class IController {
public:
	static LRESULT CALLBACK commonWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	virtual LRESULT CALLBACK callback(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;
};