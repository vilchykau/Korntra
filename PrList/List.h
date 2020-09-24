#pragma once

#include <cstring>
#include <memory>
#include <exception>
#include <initializer_list>

#include "Iterator.h"
#include "ContainerVisior.h"

template<typename T>
class List;

template<typename T>
class ListIterator : public Iterator<T> {
public:
	ListIterator(List<T>* list);
    bool hasNext() override;
	T& getNext() override;
private:
	List<T>* list;
	size_t pos;
};

template<typename T>
class List
{
public:
	friend class ListIterator<T>;

	List() : cap(1), size(0), start(0)
	{
		arr = new T[1];
	}

	List(std::initializer_list<T> list) {
		cap = list.size() > 1 ? list.size() : 1;
		size = 0;
		start = 0;
		arr = new T[cap];
		for (const auto& element : list) {
			PushBack(element);
		}
	}

	List(const List<T>& other) {
		cap = other.cap;
		size = other.size;
		start = other.start;
		arr = new T[cap];
		memcpy(arr, other.arr, sizeof(T) * cap);
	}

	List(List<T>&& other):List() {
		swap(other);
	}

	void pushBack(const T& element) {
		if (start + size >= cap) {
			T* new_arr = new T[cap * 2+1];
			memcpy(new_arr, arr, sizeof(T) * cap);
			cap = cap * 2 + 1;
			delete[] arr;
			arr = new_arr;
		}

		arr[start + size] = element;
		++size;
	}

	void pushFront(const T& elemnt) {
		if (start <= 0) {
			if (size == cap) {
				const int new_cap = cap * 2 + 1;
				T* new_arr = new T[new_cap];
				memcpy(new_arr + 1, arr, sizeof(T)*cap);
				cap = new_cap;
				delete[] arr;
				arr = new_arr;
				start = 1;
			}
			else {
				shiftRight();
			}
		}

		arr[start - 1] = elemnt;
		++size;
		--start;
	}

	List<T>& operator=(const List<T>& other) {
		if (*other != this) {
			List<T> temp(other);
			swap(temp);
		}
		return *this;
	}

	List<T>& operator=(List<T>&& other) {
		if (*other != this) {
			clear();
			swap(other);
		}
		return *this;
	}

	const T& front() const {
		return arr[start];
	}

	T& front() {
		return arr[start];
	}

	const T& back() const {
		return arr[start + size];
	}

	T& back() {
		return arr[start + size];
	}

	size_t getSize() const {
		return size;
	}

	bool isEmpty() const {
		return !size;
	}

	const T& operator[](size_t index) const {
		return arr[start + index];
	}

	T& operator[](size_t index) {
		return arr[start + index];
	}

	void popFront() {
		if (size) {
			++start;
			--size;
		}
		else {
			throw std::exception("Can't pop front. List is empty!");
		}

		if (start > (cap - size) * 0.5) {
			shiftLeftToBorder();
		}
	}

	void popBack() {
		if (size) {
			--size;
		}
		else {
			throw std::exception("Can't pop back. List is empty!");
		}
	}

	void popElement(size_t index) {
		for (size_t i = start+index+1; i < start + size; ++i) {
			arr[i - 1] = arr[i];
		}
		--size;
	}

	std::shared_ptr<Iterator<T>> getIterator() {
		return std::shared_ptr<ListIterator<T>>(new ListIterator<T>(this));
	}

	void clear() {
		delete[] arr;
		arr = new T[1];
		start = size = 0;
		cap = 1;
	}

	void swap(List<T>& other) {
		std::swap(arr, other.arr);
		std::swap(size, other.size);
		std::swap(cap, other.cap);
		std::swap(start, other.start);
	}

	void accept(ContainerVisitor<T>& visitor) {
		visitor.visitList(*this);
	}

	virtual ~List() {
		delete[] arr;
	}
private:

	void shiftRight() {
		for (size_t i = size; i != 0; --i) {
			arr[i] = arr[i - 1];
		}
		start = 1;
	}

	void shiftLeftToBorder() {
		for (size_t i = 0; i < size; ++i) {
			arr[i] = arr[i + start];
		}
		start = 0;
	}

	size_t cap;
	size_t start;
	size_t size;
	T* arr;
};

template<typename T>
inline ListIterator<T>::ListIterator(List<T>* list):
	list(list), pos(list->start)
{
}

template<typename T>
inline bool ListIterator<T>::hasNext()
{
	return pos < list->start + list->size;
}

template<typename T>
inline T& ListIterator<T>::getNext()
{
	T* element = &list->arr[pos];
	++pos;
	return *element;
}
