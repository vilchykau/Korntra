#pragma once
#include "IModel.h"

#include <string>
#include "list.h"

class Model : public IModel
{
public:
	Model(){};
	void firstPushFront(const std::wstring& element);
	void firstPushBack(const std::wstring& element);
	void firstPopBack();
	void firstPopFront();

	std::wstring getArrayLabel();
	std::wstring getTop();
	std::wstring getBack();
private:
	List<std::wstring> list;
};

