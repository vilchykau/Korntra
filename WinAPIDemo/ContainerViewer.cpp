#include "ContainerViewer.h"

#include <cmath>
#include "ContainerViewerColors.h"

void ContainerViewer::setPosition(const ViewPosition& position) {
	panel.setRadius(20);
	this->position = position;
	panel.setPosition(position);
}

const ViewPosition& ContainerViewer::getPosition() const {
	return position;
}

void ContainerViewer::setSize(const ViewSize& size) {
	this->size = size;
	panel.setSize(size);
}

const ViewSize& ContainerViewer::getSize() const {
	return size;
}

void ContainerViewer::setElementSize(int elementSize) {
	this->elementSize = elementSize;
}

int ContainerViewer::getElementSize() const {
	return elementSize;
}

void ContainerViewer::setColor(int color) {
	panel.setColor(color);
}

int ContainerViewer::getColor() const {
	return panel.getColor();
}

void ContainerViewer::render(const HDC& hdc, const ViewPosition& offset) {
	panel.render(hdc, offset);
	drawElements(hdc, offset);
	drawChildren(hdc, offset);
}

std::list<std::shared_ptr<IView>>& ContainerViewer::getChilds() {
	return children;
}

std::list<std::shared_ptr<IContainerElement>>& ContainerViewer::getElements() {
	return elements;
}

void ContainerViewer::drawChildren(const HDC& hdc, const ViewPosition& offset) {
	for (const auto& c : children) {
		return c->render(hdc, position + offset);
	}
}

void ContainerViewer::drawElements(const HDC& hdc, const ViewPosition& offset) {
	ContainerViewerColors colors;
	const int spaceSize = elementSize * 0.5;
	int yPos = calcAllColumnStartPosition() + spaceSize;
	const int maxRow = calcRowMax();

	auto printList = elements;

	while (!printList.empty()) {
		int rowSize = min(maxRow, printList.size());
		int xPos = calcAllRowStartPosition(rowSize) + spaceSize;
		for (int i = 0; i < rowSize; ++i) {
			printList.front()->setSize(elementSize);
			printList.front()->setColor(colors.color());
			printList.front()->render(hdc, position + offset + ViewPosition{ xPos, yPos });
			printList.pop_front();
			xPos += elementSize + spaceSize;
		}
		yPos += elementSize + spaceSize;
	}
}

int ContainerViewer::calcAllColumnStartPosition() const {
	const int columnHeight = calcColumnHeigth();
	return (size.h - columnHeight) / 2;
}

int ContainerViewer::calcColumnHeigth() const {
	const int spaceLength = elementSize * 0.5;
	const int rowsCount = calcRowsCount();
	return spaceLength * (rowsCount + 1) + rowsCount * elementSize;
}

int ContainerViewer::calcRowsCount() const {
	return std::ceil((double)elements.size() / calcRowMax());
}

int ContainerViewer::calcAllRowStartPosition(int elementCount) const {
	const int rowLength = calcRowLength(elementCount);
	return (size.w - rowLength) / 2;
}

int ContainerViewer::calcRowLength(int elementCount) const {
	const int spaceLength = elementSize * 0.5;
	return spaceLength * (elementCount + 1) + elementCount * elementSize;
}

int ContainerViewer::calcRowMax() const {
	return std::floor((double)size.w / (elementSize + elementSize * 0.5));
}