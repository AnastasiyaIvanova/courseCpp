#pragma once
#include "Figure.h"
class Circle : public Figure
{
protected:
	int r;
public:
	Circle(string name = "cr", string type = " circle", int r = 3);
	double get_area() override;
	double get_per() override;
};