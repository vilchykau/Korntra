// newContainer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iostream>

#include "list.h"
#include "ToStringVisitor.h"

int main()
{
    List<int> list;
    std::stringstream ss;
    
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.push_back(8);
    list.push_front(4);
    
    ToStringVisitor<int, std::string, std::stringstream> visitor("  ");
    list.visit(visitor);
    std::cout << "%  " << visitor.getString() << "   %" << std::endl;
}

