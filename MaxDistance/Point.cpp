#include "Point.h"

Point::Point():Point(0,0)
{
}

Point::Point(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Point::GetX()
{
	return x;
}

int Point::Gety()
{
	return y;
}

void Point::SetX(int x)
{
	this->x = x;
}

void Point::SetY(int y)
{
	this->y = y;
}

double Point::GetDistance(const Point& other)
{
	return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
}
