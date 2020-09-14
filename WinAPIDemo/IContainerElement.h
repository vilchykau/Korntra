#pragma once

#include "IView.h"

class IContainerElement : public IView
{
public:
	virtual void setSize(int size) = 0;
	virtual void setColor(int color) = 0;
};

