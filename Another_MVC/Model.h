#pragma once
#include "IPublisher.h"

#include <string>
#include <list>

class Model : public IPublisher
{
public:
	Model(){};
	void firstPushFront(const std::wstring& element);
	void firstPushBack(const std::wstring& element);
	void firstPopBack();
	void firstPopFront();
	std::wstring getArrayLabel();
private:
	std::list<std::wstring> list;
};

