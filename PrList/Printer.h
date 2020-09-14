#pragma once

#include <iostream>

#include "List.h"
#include "ContainerVisior.h"

template<typename T>
class Printer : public ContainerVisitor<T>
{
public:
	Printer<T>(std::ostream& os);
	void visitList(List<T>& list);
	void visitDeque(Deque<T>& list);
private:
	std::ostream& os;
};

template<typename T>
Printer<T>::Printer<T>(std::ostream& os) : os(os) {}

template<typename T>
void Printer<T>::visitList(List<T>& list) {
	auto it = list.getIterator();
	bool isFirst = true;
	while (it->hasNext()) {
		if (!isFirst) {
			os << " ";
		}
		os << it->getNext();
		isFirst = false;
	}
}

template<typename T>
void Printer<T>::visitDeque(Deque<T>& list) {
	auto it = list.getIterator();
	bool isFirst = true;
	while (it->hasNext()) {
		if (!isFirst) {
			os << " ";
		}
		os << it->getNext();
		isFirst = false;
	}
}
