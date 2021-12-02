#include "Rectangle.h"
Rectangle::Rectangle(string name, string type, int a, int b) : Figure(name, type)
{
	this->a = a;
	this->b = b;
}
double Rectangle::get_per()
{
	return (a + b) * 2;
}
double Rectangle::get_area()
{
	return a * b;
}