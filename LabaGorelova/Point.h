#pragma once
#include <math.h>
class Point
{
private:
	int x, y;
public:
	Point();
	Point(int x, int y);
	int GetX();
	int Gety();
	void SetX(int x);
	void SetY(int y);
	double GetDistance(const Point& other);
};

