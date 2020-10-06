#pragma once

#include "framework.h"

class IView
{
public:
	virtual void refreshView() = 0;
	virtual void initElements(HWND) = 0;
};

