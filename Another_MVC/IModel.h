#pragma once
#include "IView.h"

#include <list>

class IModel {
public:
	virtual void addView(IView* sub) {
		views.push_back(sub);
	}

	virtual void removeView(IView* sub) {
		views.remove(sub);
	}

protected:
	virtual void refreshView() {
		for (auto& view : views) {
			view->refreshView();
		}
	}

	std::list<IView*> views;
};