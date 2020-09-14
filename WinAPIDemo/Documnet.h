#pragma once
#include "IView.h"

class Documnet :
    public IView
{
public:
    void render(const HDC& hdc);
    void render(const HDC& hdc, const ViewPosition& offset) override;
    std::list<std::shared_ptr<IView>>& getChilds() override;
private:
    std::list<std::shared_ptr<IView>> childs;
};

