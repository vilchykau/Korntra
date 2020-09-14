#pragma once

#include "framework.h"
#include <list>
#include <memory>

#include "ViewPosition.h"
#include "ViewSize.h"

class IView {
public:
	virtual void render(const HDC& hdc, const ViewPosition& offset) = 0;
	virtual std::list<std::shared_ptr<IView>>& getChilds() = 0;
};