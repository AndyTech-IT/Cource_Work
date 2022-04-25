#include "Point2.h"

Point2::Point2(int x, int y)
{
	X = x;
	Y = y;
}

Point2::Point2(const Point2& copy)
{
	X = copy.X;
	Y = copy.Y;
}

Point2::Point2(const Point2* copy)
{
	X = copy->X;
	Y = copy->Y;
}
