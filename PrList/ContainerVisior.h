#pragma once

template<typename T>
class List;

template<typename T>
class Deque;

template<typename T>
class ContainerVisitor {
public:
	virtual void visitList(List<T>& list) = 0;
	virtual void visitDeque(Deque<T>& deque) = 0;
};