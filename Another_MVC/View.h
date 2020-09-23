#pragma once
#include "framework.h"
#include <string>

#include "ISubscriber.h"
#include "IController.h"

class View : public ISubscriber
{
public:
	void setController(IController* cont);
	void initWindow(HINSTANCE hInst, std::wstring& windowName);
	void initElements(HWND hWnd);
	void handleEvent() override;
private:
	void initAddButton(HWND hWnd);
	void initTextIn(HWND hWdn);
	IController* cont;

public:
	const static int H_ADD_BUTTON = 1001;
	const static int H_ADD_TEXT_BOX = 1002;
};

