#include <iostream>
#include <string>
using namespace std;
class Numb
{
private:
	int num, den;//int _num = 0, int _den = 0
public:
	Numb(int _num = 0, int _den = 0)
	{
		set_num(_num);
		set_den(_den);
	}
	int get_num()
	{
		return num;
	}
	void set_num(int _num)
	{
		num = _num;
	}
	int get_den()
	{
		return den;
	}
	void set_den(int _den)
	{
		den = _den;
	}
	Numb operator+(Numb n)
	{
		if (den == n.den)
			return Numb(num + n.num, den);
		else
		{
			int num1 = num * n.den + n.num * den;
			int den1 = den * n.den;
			return Numb(num1, den1);
		}
	}
	Numb operator-(Numb n)
	{
		if (den == n.den)
			return Numb(num - n.num, den);
		else
		{
			int num1 = num * n.den - n.num * den;
			int den1 = den * n.den;
			return Numb(num1, den1);
		}
	}
	Numb operator*(Numb n)
	{
		return Numb(num * n.num, den * n.den);
	}
	Numb operator/(Numb n)
	{
		return Numb(num * n.den, den * n.num);
	}
	bool operator==(Numb n)
	{
		return num == n.num && den == n.den;
	}
	bool operator!=(Numb n)
	{
		return !(num == n.num && den == n.den);
	}
	bool operator>(Numb n)
	{
		if (den == n.den)
			return num > n.num;
		else
			return num * n.den > n.num * den;
	}
	bool operator>=(Numb n)
	{
		if (den == n.den)
			return num >= n.num;
		else
			return num * n.den >= n.num * den;
	}
	bool operator<(Numb n)
	{
		if (den == n.den)
			return num < n.num;
		else
			return num * n.den < n.num * den;
	}
	bool operator<=(Numb n)
	{
		if (den == n.den)
			return num <= n.num;
		else
			return num * n.den <= n.num * den;
	}
	void operator+=(Numb n)
	{
		if (den == n.den)
			num += n.num;
		else
		{
			num *= n.den;
			num += n.num * den;
			den *= n.den;
		}
	}
	void operator-=(Numb n)
	{
		if (den == n.den)
			num -= n.num;
		else
		{
			num *= n.den;
			num -= n.num * den;
			den *= n.den;
		}
	}
	void operator*=(Numb n)
	{
		num *= n.num;
		den *= n.den;
	}
	void operator/=(Numb n)
	{
		num *= n.den;
		den *= n.num;
	}

	string show()
	{
		if (num % den == 0) return to_string(num / den);
		else return to_string(num) + "/" + to_string(den);
	}
};
class Example 
{
public:
	int length;
	char* data;
	Example() {};
	Example(const char* data, int length)
	{
		this->data = new char[length];
		for (int i = 0; i < length; i++)
		{
			this->data[i] = data[i];
		}
		this->length = length;
	}
	~Example()
	{
		delete[] data;
	}
	Example& operator=(Example& c)
	{
		cout << "=overloading" << endl;
		this->data = new char[c.length];
		for (int i = 0; i < c.length; i++)
		{
			this->data[i] = c.data[i];
		}
		this->length = c.length;
		return *this;
	}
};
int main()
{



	Numb one(3, 2);
	Numb two(4, 3);
	Numb sum = one + two;
	Numb sub = one - two;
	Numb mult = one * two;
	Numb div = one / two;
	double eq = one==two;
	cout << sum.show() << endl;
	cout << sub.show() << endl;
	cout << mult.show() << endl;
	cout << div.show() << endl;
	string s = eq ? "true" : "false";
	cout << s << endl;
	s = (one >= two) ? "true" : "false";
	cout << s << endl;
	one /= two;
	cout << one.show();
}