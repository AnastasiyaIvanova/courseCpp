#pragma once
#include "Square.h"
class Cube : public Square
{
public:
	Cube(string name = "cb", string type = "cube", int a = 2) : Square(name, type, a) {}
	double get_area() override;
	double get_per() override;
	double get_volume();
};