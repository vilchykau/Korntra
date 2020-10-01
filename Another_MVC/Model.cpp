#include "Model.h"

#include <sstream>
#include <iterator>
#include <iostream>

#include "ToStringVisitor.h"


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
	ToStringVisitor<std::wstring, std::wstring, std::wstringstream> visitor(L";  ");
	list.visit(visitor);
	return visitor.getString();
}

std::wstring Model::getTop()
{
	return list.size() ? list.front() : L"!Empty!";
}

std::wstring Model::getBack()
{
	return list.size() ? list.back() : L"!Empty!";
}
