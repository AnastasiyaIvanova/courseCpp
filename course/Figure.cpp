#include "Figure.h"
#include <iostream>
Figure::Figure(string name, string type)
{
	this->name = name;
	this->type = type;
}
string Figure::get_name()
{
	return name;
}
string Figure::get_type()
{
	return type;
}
void Figure::show()
{
	cout << get_name() << " " << get_type() << endl;
}