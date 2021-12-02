#include "Cube.h"
double Cube::get_area()
{
	return Square::get_area() * 6;
}
double Cube::get_per()
{
	return Square::get_per() * 6;
}
double Cube::get_volume()
{
	return a * a* a;
}