#pragma once
#include "ISubscriber.h"

#include <list>

class IPublisher {
public:
	virtual void addSubscriber(ISubscriber* sub) {
		subs.push_back(sub);
	}

	virtual void removeSubscriber(ISubscriber* sub) {
		subs.remove(sub);
	}

protected:
	virtual void publish() {
		for (auto& sub : subs) {
			sub->handleEvent();
		}
	}

	std::list<ISubscriber*> subs;
};