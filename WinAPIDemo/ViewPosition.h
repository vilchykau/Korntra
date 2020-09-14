#pragma once
struct ViewPosition
{
	int x;
	int y;

	ViewPosition operator+(const ViewPosition& r) const;
};