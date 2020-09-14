// PrList.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "List.h"
#include "Printer.h"
#include "Deque.h"
#include "ForAll.h"

int main()
{
	/*
	List<int> l{ 1, 5, 7 };
	l.PushBack(44);
	l.PushFront(33);
	l.PushBack(55);
	
	Printer<int> printer(std::cout);
	l.accept(printer);
	*/
	Deque<int> deq;
	deq.pushBack(55);
	deq.pushFront(33);

	ForAll<int> forAll([](int& element) {
		element *= element;
		}
	);

	Printer<int> printer(std::cout);
	deq.accept(printer);


	return 0;
}