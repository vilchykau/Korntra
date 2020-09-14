#pragma once
#include "IView.h"

#include "framework.h"
#include <string>

class TextView :
    public IView
{
public:
	void setPosition(const ViewPosition& position) {
		this->position = position;
	}

	const ViewPosition& getPosition() const {
		return position;
	}

	void setSize(const ViewSize& size) {
		this->size = size;
	}

	const ViewSize& getSize() const {
		return size;
	}

	void setTextSize(int textSize) {
		this->textSize = textSize;
	}

	const int& getTextSize() const {
		return textSize;
	}

	void setColor(int color) {
		this->color = color;
	}

	const int& getColor() const {
		return color;
	}

	void setText(const std::wstring& str) {
		text = str;
	}

	void render(const HDC& hdc, const ViewPosition& offset) override {
		HFONT font = CreateFont(-textSize, 0, 0, 0, 0, ANSI_CHARSET, 0U, 0U, 0U, 0U, 0U, 0U, 0U, TEXT("Arial"));
		SelectFont(hdc, font);
		SetTextColor(hdc, color); 
		RECT rect = { position.x, position.y, position.x + size.w, position.y + size.h };
		SetBkMode(hdc, TRANSPARENT);
		DrawText(hdc, text.c_str(), text.length(), &rect, DT_VCENTER | DT_SINGLELINE | DT_CENTER);

		for (auto& c : children) {
			c->render(hdc, position + offset);
		}
	};

	std::list<std::shared_ptr<IView>>& getChilds() override {
		return children;
	};
private:
	ViewPosition position;
	ViewSize size;

	std::wstring text;
	int color;
	int textSize;

	std::list<std::shared_ptr<IView>> children;
};

