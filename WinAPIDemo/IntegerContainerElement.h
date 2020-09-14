#pragma once
#include "IContainerElement.h"
#include "framework.h"

#include <string>

class IntegerContainerElement :
    public IContainerElement
{
public:
    IntegerContainerElement(int value);
    void setSize(int size) override;
    void setColor(int color) override;
    void render(const HDC& hdc, const ViewPosition& offset) override;
    std::list<std::shared_ptr<IView>>& getChilds() override;
private:
    void drawChildren(const HDC& hdc, const ViewPosition& offset) const;

    int value;
    int size;
    int color;

    std::list<std::shared_ptr<IView>> children;
};

