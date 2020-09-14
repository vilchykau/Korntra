#include "ViewPosition.h"

ViewPosition ViewPosition::operator+(const ViewPosition& r) const {
	return ViewPosition{ x + r.x, y + r.y };
}