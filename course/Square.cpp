#include "Square.h"
#include <iostream>
Square::Square(string name, string type, int a) : Figure(name, type)
{
	this->a = a;
}
double Square::get_area()
{
	return a * a;
}
double Square::get_per()
{
	return a * 2;
}
ostream& operator<<(ostream& s, Square& sq)
{
	s << sq.get_name() << " " << sq.get_type() << " " << endl;
	return s;
}
istream& operator>>(istream& s, Square& sq)
{
	cout << "Enter square" << endl;
	cout << "Name: ";
	s >> sq.name;
	cout << "Type: ";
	s >> sq.type;
	cout << "Width: "; 
	s >> sq.a;
	return s;
}