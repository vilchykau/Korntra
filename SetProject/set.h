#pragma once

#include <cstring>
#include <algorithm>
#include <iostream>
#include <initializer_list>

template<typename T>
class Set;

template<typename T>
class SetIterator {
public:
	SetIterator(Set<T>* set);
	T& getNext();
	bool hasNext();
private:
	Set<T>* set;
	size_t pos;
};

template<typename T>
class ConstSetIterator {
public:
	ConstSetIterator(const Set<T>* set);
	const T& getNext();
	bool hasNext();
private:
	const Set<T>* set;
	size_t pos;
};

template<typename T>
class Set
{
	friend SetIterator<T>;
	friend ConstSetIterator<T>;
public:
	Set():a(new T[1]), cap(1), size(0)
	{}

	Set(const Set& other) {
		auto it =other.getConstIterator();
		while (it.hasNext()){
			inset(it.getNext());
		}
	}

	Set(std::initializer_list<T> inlist): Set() {
		for (const auto& e : inlist) {
			inset(e);
		}
	}

	~Set() {
		delete[] a;
	}

	void inset(const T& element) {
		if (size == 0) {
			insetBefore(element, 0);
		}
		else {
			auto p = std::lower_bound(a, a + size, element);
			size_t index = p - a;
			if (index == size) {
				insetBefore(element, size);
			}
			else if (element < a[index]) {
				insetBefore(element, index);
			}
		}
	}

	SetIterator<T> getIterator() {
		return SetIterator<T>(this);
	}

	ConstSetIterator<T> getConstIterator() const{
		return ConstSetIterator<T>(this);
	}
private:
	void insetBefore(const T& element, size_t i) {
		if (size != cap) {
			shiftAfter(i);
		}
		else {
			expandAfter(i);
		}
		a[i] = element;
		++size;
	}

	void shiftAfter(size_t index) {
		for (size_t i = size+1; i > index; --i) {
			a[i - 1] = a[i - 2];
		}
	}

	void expandAfter(size_t index) {
		//const size_t new_cap = cap * 1.5 + 2;
		//T* new_array = new T[new_cap];
		//memcpy(new_array, a, sizeof(T) * i);
		//memcpy(new_array + sizeof(T) * (i + 1), a + sizeof(T) * i, size - i);

		const size_t new_cap = static_cast<size_t>(cap * 1.5 + 2);
		T* new_array = new T[new_cap];
		memcpy(new_array, a, sizeof(T) * index);
		memcpy(new_array + (index + 1), a + index, sizeof(T) * (cap - index));

		delete[] a;
		a = new_array;
		cap = new_cap;
	}

	T* a;
	size_t cap;
	size_t size;
};

template<typename T>
inline SetIterator<T>::SetIterator(Set<T>* set):set(set)
{
}

template<typename T>
inline T& SetIterator<T>::getNext()
{
	T* element = &set->a[pos];
	++pos;
	return *element;
}

template<typename T>
inline bool SetIterator<T>::hasNext()
{
	return pos < set->size;
}

template<typename T>
inline ConstSetIterator<T>::ConstSetIterator(const Set<T>* set) :set(set)
{
}

template<typename T>
inline const T& ConstSetIterator<T>::getNext()
{
	T* element = &set->a[pos];
	++pos;
	return *element;
}

template<typename T>
inline bool ConstSetIterator<T>::hasNext()
{
	return pos < set->size;
}
