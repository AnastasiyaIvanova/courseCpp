#pragma once
#include <string>
#include <fstream>
using namespace std;
class Figure
{
protected:
	string name;
	string type;
public:
	Figure(string, string);
	string get_name();
	string get_type();
	void show();
	virtual double get_area() = 0;
	virtual double get_per() = 0;
	friend ostream& operator<<(ostream&, Figure*);
	//friend istream& operator>>(istream&, Figure*);
};