#pragma once
#include "Figure.h"
class Triangle : public Figure
{
private:
	int a, b, c;
public:
	Triangle(string name = "tr", string type = "triangle", int a = 3, int b = 2, int c = 1);
	double get_per() override;
	double get_area() override;
};
