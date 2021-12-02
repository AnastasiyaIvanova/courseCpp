#pragma once
#include "Figure.h"
class Rectangle : public Figure
{
private:
	int a, b;
public:
	Rectangle(string name = "rec", string type = "rectangle", int a = 2, int b = 3);
	double get_per() override;
	double get_area() override;
};