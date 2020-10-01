#include "Model.h"

#include <sstream>
#include <iterator>
#include <iostream>


void Model::firstPushFront(const std::wstring& element)
{
	list.push_front(element);
	refreshView();
}

void Model::firstPushBack(const std::wstring& element)
{
	list.push_back(element);
	refreshView();
}

void Model::firstPopBack()
{
	list.pop_back();
	refreshView();
}

void Model::firstPopFront()
{
	list.pop_front();
	refreshView();
}

std::wstring Model::getArrayLabel()
{
	std::wstringstream ss;;
	for (const auto& el : list) {
		ss << el << "  ";
	}
	return ss.str().c_str();
}
