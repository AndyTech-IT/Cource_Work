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
	operator const SMALL_RECT*()
	{
		const SMALL_RECT* result = new SMALL_RECT{ 0, 0, (short)X, (short)Y };
		return result;
	}
	Point2 operator +(Point2 value);
	Point2 operator -(Point2 value);
	Point2 operator -();
	bool operator ==(Point2 value);
	bool operator !=(Point2 value);
};

