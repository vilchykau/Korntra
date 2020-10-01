#pragma once
#include "IVisitor.h"
#include "list.h"

#include <string>
#include <sstream>

template<typename T, typename String = std::string, typename StringStream = std::stringstream>
class ToStringVisitor : public IVisitor<T> {
public:
	ToStringVisitor(const String& fill):fill(fill){}

	void visit(List<T>& list) override {
		auto it = list.getConstIterator();
		bool isFirst = true;
		while (it.hasNext()) {
			if (!isFirst) {
				out << fill;
			}
			out << it.getNext();
			isFirst = false;
		}
	}

	String getString() const {
		return out.str();
	}
private:
	StringStream out;
	String fill;
};