#include "Ball.h"
double Ball::get_area()
	{
		return 4 * 3.14* r* r;
	}
	double Ball::get_volume()
	{
		return 4 / 3 * 3.14 * r * r * r;
	}