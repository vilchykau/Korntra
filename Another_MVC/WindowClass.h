#pragma once

#include "framework.h"

#define MAX_LOADSTRING 100

class WindowClass
{
public:
	static WindowClass* getInstance(HINSTANCE hInst);
private:
	static WindowClass* inst;


public:
	WCHAR* getClass();
	static LRESULT CALLBACK commonWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
private:
	WindowClass(HINSTANCE hInst);
	WCHAR szWindowClass[MAX_LOADSTRING];
};


