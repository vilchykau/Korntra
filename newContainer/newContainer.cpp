// newContainer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "list.h"

int main()
{
    List<int> list;
    
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
    list.push_front(4);
    //list.push_front(35);
	//list.push_back(233);
    //list.pop_front();
	List<int> list2(list);

    auto it = list2.getConstIterator();
    while (it.hasNext()) {
        std::cout << it.getNext() << "  ";
    }
}

