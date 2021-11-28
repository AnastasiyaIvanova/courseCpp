#include <iostream>
#include <string>
using namespace std;//Circle, cube, ball
class Figure
{
protected:
	string name;
	string type;
public:
	Figure(string name, string type)
	{
		this->name = name;
		this->type = type;
	}
	string get_name()
	{
		return name;
	}
	string get_type()
	{
		return type;
	}
	void show()
	{
		cout << get_name() << " " << get_type() << endl;
	}
};
class Square : public Figure
{
protected:
	int a;
public:
	Square(string name, string type, int a) : Figure(name, type)
	{
		this->a = a;
	}
	int get_area()
	{
		return a * a;
	}
	int get_per()
	{
		return a * 2;
	}

};
class Rectangle : public Figure
{
private:
	int a, b;
public:
	Rectangle(string name, string type, int a, int b) : Figure(name, type)
	{
		this->a = a;
		this->b = b;
	}
	int get_per()
	{
		return (a + b) * 2;
	}
	int get_area()
	{
		return a * b;
	}

};
class Triangle : public Figure
{
private:
	int a, b, c;
public:
	Triangle(string name, string type, int a, int b, int c) : Figure(name, type)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	int get_per()
	{
		return a + b + c;
	}
	double get_area()
	{
		int p = get_per() / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
};
class Circle : public Figure
{
protected:
	int r;
public:
	Circle(string name, string type, int r) : Figure(name, type)
	{
		this->r = r;
	}
	double get_area()
	{
		return 2 * 3.14 * r;
	}
	double get_per()
	{
		return 3.14 * r * r;
	}

};
class Cube : public Square
{
public:
	Cube(string name, string type, int a) : Square(name, type, a) {}
	int get_area()
	{
		return Square::get_area() * 6;
	}
	int get_per()
	{
		return Square::get_per() * 6;
	}
	int get_volume()
	{
		return a * a * a;
	}
};
class Ball : public Circle
{
public:
	Ball(string name, string type, int r) : Circle(name, type, r) {}
	double get_area()
	{
		return 4 * 3.14 * r * r;
	}
	int get_volume()
	{
		return 4 / 3 * 3.14 * r * r * r;
	}
};
int main()
{
	Square s("Sq1", "square", 2);
	s.show();
	cout << "S= " << s.get_area() << endl;
	cout << "P= " << s.get_per() << endl;
	Rectangle r("Rec1", "rectangle", 2, 3);
	r.show();
	cout << "S= " << r.get_area() << endl;
	cout << "P= " << r.get_per() << endl;
	Triangle t("Tri1", "triangle", 2, 3, 1);
	t.show();
	cout << "S= " << t.get_area() << endl;
	cout << "P= " << t.get_per() << endl;
	Circle cr("Cr1", "circle", 3);
	cr.show();
	cout << "S= " << cr.get_area() << endl;
	cout << "P= " << cr.get_per() << endl;
	Cube c("cub1", "cube", 2);
	c.show();
	cout << "S= " << c.get_area() << endl;
	cout << "P= " << c.get_per() << endl;
	cout << "V= " << c.get_volume() << endl;
	Ball b("ball1", "ball", 2);
	b.show();
	cout << "S= " << b.get_area() << endl;
	cout << "V= " << b.get_volume() << endl;
}