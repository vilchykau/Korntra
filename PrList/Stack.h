#pragma once
#include "List.h"

template<typename T>
class Stack : private List<T>
{
public:
	Stack() :List<T>() {}
	Stack(const Stack<T>& other): List<T>(other){}
	Stack(std::initializer_list<T>& other): List<T>(other){}

	T& top() {
		return List<T>::back();
	}

	const T& top() const{
		return List<T>::back();
	}

	void pop() {
		List<T>::popBack();
	}

	bool isEmpty() const{
		return List<T>::isEmpty();
	}

	size_t getSize() const {
		return List<T>::getSize();
	}

	void push(const T* element) {
		List<T>::pushBack(element);
	}
};

