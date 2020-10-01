#pragma once
#include "framework.h"
#include <string>

#include "IView.h"
#include "IController.h"

class Model;

class View : public IView
{
public:
	void setController(IController* cont);
	void initWindow(HINSTANCE hInst, std::wstring& windowName);
	void initElements(HWND hWnd);
	void refreshView() override;
	HWND getMainHwnd();
	void setModel(Model* model);
private:

	void initFirstPFButton(HWND hWnd);
	void initFirstInTextbox(HWND hWdn);
	void initFirstArrayLabel(HWND hWnd);
	void initFirstPBButton(HWND hWnd);
	void initFirstPOPFButton(HWND hWnd);
	void initFirstPOPBButton(HWND hWnd);

	void refreshArrayLable(HWND hWnd);

	IController* cont;
	Model* model;
	HWND mainHwnd;

public:
	const static int ID_FIRST_PF_BUTTON = 1001;
	const static int ID_FIRST_NEW_ELEMENT_TEXTBOX = 1002;
	const static int ID_FIRST_ARRAY_LABEL = 1003;
	const static int ID_FIRST_PB_BUTTON = 1004;
	const static int ID_FIRST_POPF_BUTTON = 1005;
	const static int ID_FIRST_POPB_BUTTON = 1006;

};

