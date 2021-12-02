#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Square.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Ball.h"
#include "Cube.h"
using namespace std;
void Read(string& name)
{
	cout << "Name: ?" << endl;
	cin >> name;
}
ostream& operator<<(ostream& s, Figure* f)
{
	s << f->get_name() << " " << f->get_type() << " " << f->get_area() << endl;
	return s;
}
int main()
{
	ofstream out("file.txt");
	srand(time(0));
	Figure* figure[100];
	int current_numb = 0;
	while (true)
	{
		int numb;
		cout << "Numb of figures: " << endl;
		cin >> numb;
		for (int i = 0; i < numb; ++i)
		{
			string name, type;
			int width, height, a, b, c, r;
			int rnd = 1 + rand() % 6;
			switch (rnd) {
			case 1:
				cout << "Input data for Square" << endl;
				Read(name);
				type = "Square";
				width = 1 + rand() % numb;
				//width = 100; //for test max area
				figure[current_numb++] = new Square(name, type, width);
				break;
			case 2:
				cout << "Input data for Rectangle" << endl;
				Read(name);
				type = "Rectangle";
				width = 1 + rand() % numb;
				height = 1 + rand() % numb;
				figure[current_numb++] = new Rectangle(name, type, width, height);
				break;
			case 3:
				cout << "Input data for Triangle" << endl;
				Read(name);
				type = "Triangle";
				a = 1 + rand() % numb;
				b = 1 + rand() % numb;
				c = 1 + rand() % numb;
				figure[current_numb++] = new Triangle(name, type, a, b, c);
				break;
			case 4:
				cout << "Input data for Circle" << endl;
				Read(name);
				type = "Circle";
				r = 1 + rand() % numb;
				figure[current_numb++] = new Circle(name, type, r);
				break;
			case 5:
				cout << "Input data for Cube" << endl;
				Read(name);
				type = "Cube";
				a = 1 + rand() % numb;
				figure[current_numb++] = new Cube(name, type, a);
				break;
			case 6:
				cout << "Input data for Ball" << endl;
				Read(name);
				type = "Ball";
				r = 1 + rand() % numb;
				figure[current_numb++] = new Ball(name, type, r);
				break;
			default:
				cout << "ERR";
				break;
			}
		}
		break;
	}
	double max = 0;
	int n = 0;
	Figure* maxS[100];
	for (int i = 0; i < current_numb; ++i)
	{
		if (max <= figure[i]->get_area())
		{
			max = figure[i]->get_area();
			if(n > 0)
				if (max > maxS[n-1]->get_area())
				{
					memset(maxS, 0, sizeof(maxS));
					n = 0;
				}
			maxS[n] = figure[i];
			n++;
		}
	}
	cout << "max area figures:" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << maxS[i];
		out << maxS[i];
	}
	Square s;
	cin >> s;
	out.close();
}