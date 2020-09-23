#include "Model.h"

#include <sstream>
#include <iterator>
#include <iostream>


void Model::firstPushFront(const std::wstring& element)
{
	list.push_front(element);
	publish();
}

void Model::firstPushBack(const std::wstring& element)
{
	list.push_back(element);
	publish();
}

void Model::firstPopBack()
{
	list.pop_back();
	publish();
}

void Model::firstPopFront()
{
	list.pop_front();
	publish();
}

std::wstring Model::getArrayLabel()
{
	std::wstringstream ss;;
	for (const auto& el : list) {
		ss << el << "  ";
	}
	return ss.str().c_str();
}
