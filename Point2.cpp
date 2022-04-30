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

Point2 Point2::operator+(Point2 value)
{
	return Point2(X + value.X, Y + value.Y);
}

Point2 Point2::operator-(Point2 value)
{
	return Point2(X - value.X, Y - value.Y);
}

Point2 Point2::operator-()
{
	return Point2(-X, -Y);
}

bool Point2::operator==(Point2 value)
{
	return value.X == X && value.Y == Y;
}

bool Point2::operator!=(Point2 value)
{
	return value.X != X && value.Y != Y;
}
