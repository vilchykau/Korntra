#pragma once
#include "framework.h"

#include "IView.h"

class RoundedPanel : public IView
{
public:
	RoundedPanel() :size({ 0,0 }), position({ 0,0 }), color(0), radius(0) {}

	void setRadius(int radius);
	const int& getRadius() const;

	void setSize(const ViewSize& size);
	const ViewSize& getSize() const;

	void setPosition(const ViewPosition& position);
	const ViewPosition& getPosition() const;

	void setColor(INT32 color);
	INT32 getColor() const;

	void render(const HDC& hdc, const ViewPosition& offset) override;

	std::list<std::shared_ptr<IView>>& getChilds() override;
private:

	void drawChildren(const HDC& hdc, const ViewPosition& offset);
	void drawCricles(const HDC& hdc, const ViewPosition& offset) const;
	void drawRects(const HDC& hdc, const ViewPosition& offset) const;
	
	ViewSize size;
	ViewPosition position;
	int radius;
	INT32 color;
	std::list<std::shared_ptr<IView>> children;
};

