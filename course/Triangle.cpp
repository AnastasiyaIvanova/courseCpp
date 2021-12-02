#include "Triangle.h"
Triangle::Triangle(string name, string type, int a, int b, int c) : Figure(name, type)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
double Triangle::get_per()
{
	return a + b + c;
}
double Triangle::get_area()
{
	int p = get_per() / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}