#include "RoundedPanel.h"
#include "framework.h"

void RoundedPanel::setRadius(int radius) {
	this->radius = radius;
}

const int& RoundedPanel::getRadius() const {
	return radius;
}

void RoundedPanel::setSize(const ViewSize& size) {
	this->size = size;
}

const ViewSize& RoundedPanel::getSize() const {
	return size;
}

void RoundedPanel::setPosition(const ViewPosition& position) {
	this->position = position;
}

const ViewPosition& RoundedPanel::getPosition() const {
	return position;
}

void RoundedPanel::setColor(INT32 color) {
	this->color = color;
}

INT32 RoundedPanel::getColor() const {
	return color;
}

void RoundedPanel::render(const HDC& hdc, const ViewPosition& offset){
	//BeginPath(hdc);
	HPEN hPen = CreatePen(PS_SOLID, 1, color);
	SelectPen(hdc, hPen);
	HBRUSH hBrush = CreateSolidBrush(color);
	SelectBrush(hdc, hBrush);

	drawCricles(hdc, offset);
	drawRects(hdc, offset);
	//EndPath(hdc);
}

std::list<std::shared_ptr<IView>>& RoundedPanel::getChilds(){
	return children;
}

void RoundedPanel::drawChildren(const HDC& hdc, const ViewPosition& offset) {
	for (const auto& c : children) {
		return c->render(hdc, position + offset);
	}
}

void RoundedPanel::drawCricles(const HDC& hdc, const ViewPosition& offset) const {
	Ellipse(hdc,
		position.x + offset.x, position.y + offset.y,
		position.x + radius * 2 + offset.x, position.y + radius * 2 + offset.y
	);
	Ellipse(hdc,
		position.x + size.w - radius * 2 + offset.x, position.y + offset.y,
		position.x + size.w + offset.x, position.y + radius * 2 + offset.y
	);
	Ellipse(hdc,
		position.x + size.w - radius * 2 + offset.x, position.y + size.h - radius * 2 + offset.y,
		position.x + size.w + offset.x, position.y + size.h + offset.y
	);
	Ellipse(hdc,
		position.x + offset.x, position.y + size.h - radius * 2 + offset.y,
		position.x + radius * 2 + offset.x, position.y + size.h + offset.y
	);
}

void RoundedPanel::drawRects(const HDC& hdc, const ViewPosition& offset) const {
	Rectangle(hdc,
		position.x + offset.x, position.y + radius + offset.y,
		position.x + size.w + offset.x, position.y + size.h - radius + offset.y
	);

	Rectangle(hdc,
		position.x + radius + offset.x, position.y + offset.y,
		position.x + size.w - radius + offset.x, position.y + size.h + offset.y
	);
}