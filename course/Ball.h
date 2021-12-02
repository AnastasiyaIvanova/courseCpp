#pragma once
#include "Circle.h"
class Ball : public Circle
{
public:
	Ball(string name = "ball", string type = "ball", int r = 2) : Circle(name, type, r) {}
	double get_area() override;
	double get_volume();
};