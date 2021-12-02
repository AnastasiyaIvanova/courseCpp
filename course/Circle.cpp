#include "Circle.h"
Circle::Circle(string name, string type, int r) : Figure(name, type)
{
	this->r = r;
}
double Circle::get_area()
{
	return 2 * 3.14* r;
}
double Circle::get_per()
{
	return 3.14* r* r;
}