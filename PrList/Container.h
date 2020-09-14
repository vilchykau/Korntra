#pragma once

#include "ContainerVisior.h"
#include "Iterator.h"

template<typename T>
class Container {
public:
	virtual void accept(ContainerVisitor<T>& visiotor) = 0;
};