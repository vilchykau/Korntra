#pragma once

#include "ContainerVisior.h"

template<typename T, typename FUN>
class ForAll : public ContainerVisitor<T>
{
public:
	ForAll<T>(FUN fun) : fun(fun) {};
	void visitList(List<T>& list) {
		auto it = list.getIterator();
		while (it->hasNext()) {
			fun(it->getNext());
		}
	}
	void visitDeque(Deque<T>& d){
		auto it = d.getIterator();
		while (it->hasNext()) {
			fun(it->getNext());
		}
	}
private:
	FUN fun;
};

