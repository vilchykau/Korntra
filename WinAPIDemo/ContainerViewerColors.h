#pragma once
#include "framework.h"
#include <vector>

class ContainerViewerColors
{
public:
	ContainerViewerColors();
	int color();
private:
	std::vector<int> c;
	size_t counter;
};

