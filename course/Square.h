#pragma once
#include "Figure.h"
//#include <string>
class Square : public Figure
{
protected:
	int a;
public:
	Square(string name = "sq", string type = "square", int a = 2);
	double get_area() override;
	double get_per() override;
	friend istream& operator>>(istream&, Square&);
	friend ostream& operator<<(istream&, Square&);
};