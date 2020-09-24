#pragma once

#include "List.h"

template<typename T>
class Deque : protected List<T>
{
public:
	Deque(): List<T>(){}
	Deque(const Deque& other): List<T>(other){}
	
	void pushFront(const T& element) {
		List<T>::pushFront(element);
	}

	void pushBack(const T& element) {
		List<T>::pushBack(element);
	}

	size_t getSize() const {
		return List<T>::getSize();
	}

	bool isEmpty() const {
		return List<T>::isEmpty();
	}

	const T& front() const {
		return List<T>::front();
	}

	T& front(){
		return List<T>::front();
	}

	const T& back() const {
		return List<T>::back();
	}

	T& back() {
		return List<T>::back();
	}
	
	void accept(ContainerVisitor<T>& visitor) {
		visitor.visitDeque(*this);
	}

	std::shared_ptr<Iterator<T>> getIterator() {
		return std::shared_ptr<ListIterator<T>>(new ListIterator<T>(this));
	}
};

