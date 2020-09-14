#pragma once

#include "framework.h"
#include "IView.h"
#include "RoundedPanel.h"
#include "IContainerElement.h"

class ContainerViewer : public IView
{
public:
	void setPosition(const ViewPosition& position);
	const ViewPosition& getPosition() const;

	void setSize(const ViewSize& size);
	const ViewSize& getSize() const;

	void setElementSize(int elementSize);
	int getElementSize() const;

	void setColor(int color);
	int getColor() const;

	void render(const HDC& hdc, const ViewPosition& offset) override;

	std::list<std::shared_ptr<IView>>& getChilds();
	std::list<std::shared_ptr<IContainerElement>>& getElements();
private:

	void drawChildren(const HDC& hdc, const ViewPosition& offset);
	void drawElements(const HDC& hdc, const ViewPosition& offset);

	int calcAllColumnStartPosition() const;
	int calcColumnHeigth() const;
	int calcRowsCount() const;
	int calcAllRowStartPosition(int elementCount) const;
	int calcRowLength(int elementCount) const;
	int calcRowMax() const;

	ViewPosition position;
	ViewSize size;
	RoundedPanel panel;
	std::list<std::shared_ptr<IView>> children;
	std::list<std::shared_ptr<IContainerElement>> elements;
	int elementSize;
};

