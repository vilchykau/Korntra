#pragma once

#include <iostream>
#include <initializer_list>

//#define IS_LOG

template<typename T> 
class List;

template<typename T>
class ListIterator {
public:
	ListIterator(List<T>* list);
	bool hasNext() const;
	T& getNext();
private:
	List<T>* list;
	int pos;
};

template<typename T>
class ConstListIterator {
public:
	ConstListIterator(const List<T>* list);
	bool hasNext() const;
	const T& getNext();
private:
	const List<T>* list;
	int pos;
};

template<typename T>
class List
{
public:
	friend ListIterator<T>;
	friend ConstListIterator<T>;

	List(): head(0), tail(0), cap(0), a(nullptr){}

	List(std::initializer_list<T>& init_list) {
		for (const auto& e : init_list) {
			push_back(e);
		}
	}

	List(const List& other) {
		head = 0;
		tail = other.size()-1;
		cap = other.cap;
		a = new T[cap];
		auto it = other.getConstIterator();
		while (it.hasNext()) {
			push_back(it.getNext());
		}
	}

	List(List&& other):List() {
		swap(other);
	}


	~List() {
		if (a) {
			delete[] a;
		}
	}

	List& operator=(const List& other) {
		if (this != &other) {
			List temp(other);
			swap(temp);
		}
		return *this;
	}

	List& operator=(List&& other) {
		if (this != &other) {
			List temp(other);
			swap(temp);
		}
		return *this;
	}

	void push_back(const T& new_element) {
		if (a) {
			if (head == tail) {
				expand();
			}
			a[head] = new_element;
			head++;
			head = head % cap;
		}
		else {
			initNew(new_element);
		}
		log();
	}

	void push_front(const T& new_element) {
		if (a) {
			if (head == tail) {
				expand();
			}
			tail--;
			if (tail < 0) {
				tail = cap - 1;
			}
			a[tail] = new_element;
		}
		else {
			initNew(new_element);
		}
		log();
	}

	void pop_back() {
		--head;
		if (head < 0) {
			head = cap - 1;
		}
	}

	void pop_front() {
		tail = (tail + 1) % cap;
	}

	const T& front() const {
		int i = head-1;
		if (i < 0) {
			i = cap - 1;
		}
		return a[i];
	}

	const T& back() const {
		return a[tail];
	}

	auto getIterator() {
		return ListIterator<T>(this);
	}

	auto getConstIterator() const{
		return ConstListIterator<T>(this);
	}

	void swap(List& other) {
		std::swap(a, other.a);
		std::swap(cap, other.cap);
		std::swap(tail, other.tail);
		std::swap(head, other.head);
	}

	void log() {
#ifdef IS_LOG
		std::cout << "Log: ";
		for (int i = 0; i < cap; ++i) {
			std::cout << a[i] << "  ";
		}
		std::cout << std::endl;
#endif // IS_LOG
	}

	T& operator[](int i) {
		i = (tail + i) % cap;
		return a[i];
	}

	int size() const {
		if (head > tail) {
			return head - tail;
		}
		else {
			return cap - (tail - head);
		}
	}
private:
	void initNew(const T& new_element) {
		a = new T[1];
		cap = 1;
		a[0] = new_element;
	}

	void expand() {
		const int new_cap = static_cast<int>(cap * 1.5) + 2;
		T* new_a = new T[new_cap];

		int new_i = 0;
		auto it = getIterator();
		while (it.hasNext()){
			new_a[new_i] = it.getNext();
			new_i++;
		}

		tail = 0;
		head = cap;
		cap = new_cap;
		delete[] a;
		a = new_a;
	}

	T* a;
	int head, tail, cap;
};

template<typename T>
inline ListIterator<T>::ListIterator(List<T>* list) :list(list), pos(0) {
	
}

template<typename T>
inline bool ListIterator<T>::hasNext() const {
	return pos < list->size();
}

template<typename T>
inline T& ListIterator<T>::getNext() {
	T& element = list->a[pos];
	++pos;
	return element;
}

template<typename T>
inline ConstListIterator<T>::ConstListIterator(const List<T>* list) :list(list), pos(0) {

}

template<typename T>
inline bool ConstListIterator<T>::hasNext() const {
	return pos < list->size();
}

template<typename T>
inline const T& ConstListIterator<T>::getNext() {
	T& element = list->a[pos];
	++pos;
	return element;
}

