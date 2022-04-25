#pragma once
#include "Define.h"

struct Point2
{
	int X;
	int Y;
	Point2(int x = 0, int y = 0);
	Point2(const Point2& copy);
	Point2(const Point2* copy);
	operator COORD()
	{
		return COORD{ (short)X, (short)Y };
	}
};

