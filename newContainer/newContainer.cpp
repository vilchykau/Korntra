// newContainer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "list.h"

int main()
{
    List<double> list;

    list.push_front(5);
    list.push_front(35);
	list.push_back(233);
    list.pop_front();
	List<double> list2(list);

    

    for (int i = 0; i < list2.size(); ++i) {
        std::cout << list2[i] << "  ";
    }
}

