#pragma once
#include "framework.h"

#include "IController.h"
#include "View.h"
#include "Model.h"

class Controller : public IController
{
public:
	BOOL CALLBACK callback(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) override;
	void setView(View* view);
	void setModel(Model* model);
private:
	void onFirstPFButtonClick(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void onFirstPBButtonClick(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void onFirstPopFButtonClick(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void onFirstPopBButtonClick(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

    View* view = nullptr;
	Model* model = nullptr;
};

