#include "IntegerContainerElement.h"

IntegerContainerElement::IntegerContainerElement(int value) :value(value), size(0), color(0)
{}

void IntegerContainerElement::setSize(int size){
    this->size = size;
}

void IntegerContainerElement::setColor(int color){
    this->color = color;
}

void IntegerContainerElement::render(const HDC& hdc, const ViewPosition& offset){
    HPEN hPen = CreatePen(PS_SOLID, 1, color);
    SelectPen(hdc, hPen);
    HBRUSH hBrush = CreateSolidBrush(color);
    SelectBrush(hdc, hBrush);

    Ellipse(hdc, offset.x, offset.y, offset.x + size, offset.y + size);

    HFONT font = CreateFont(-(size/4), 0, 0, 0, 0, ANSI_CHARSET, 0U, 0U, 0U, 0U, 0U, 0U, 0U, TEXT("Arial"));
    SelectFont(hdc, font);
    SetTextColor(hdc, 0x00000000);  // цвет текста(зелённый)
    RECT rect = { offset.x, offset.y, offset.x + size, offset.y + size };
    std::wstring str = std::to_wstring(value);
    SetBkMode(hdc, TRANSPARENT);
    DrawText(hdc, str.c_str(), str.length(), &rect, DT_VCENTER | DT_SINGLELINE | DT_CENTER);

    drawChildren(hdc, offset);
}

std::list<std::shared_ptr<IView>>& IntegerContainerElement::getChilds(){
    return children;
}

void IntegerContainerElement::drawChildren(const HDC& hdc, const ViewPosition& offset) const {
    for (const auto& c : children) {
        return c->render(hdc, offset);
    }
}