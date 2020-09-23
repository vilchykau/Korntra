#pragma once
#include "framework.h"

#include "IController.h"
#include "View.h"

class Controller : public IController
{
public:
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
	void setView(View* view);
private:
	void onAddButtonClick(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    View* view;
};

