#pragma once

template<typename T>
class List;

template<typename T>
class IVisitor {
public:
	virtual void visit(List<T>& list) = 0;
};