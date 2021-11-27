//#include <iostream>
//#include <string>
//using namespace std;
// class Example
//{
//public:
//	int length;
//	char* data;
//	Example() {};
//	Example(const char* data, int length)
//	{
//		this->data = new char[length];
//		for (int i = 0; i < length; i++)
//		{
//			this->data[i] = data[i];
//		}
//		this->length = length;
//	}
//	~Example()
//	{
//		delete[] data;
//	}
//	Example& operator=(Example& c)
//	{
//		cout << "=overloading" << endl;
//		this->data = new char[c.length];
//		for (int i = 0; i < c.length; i++)
//		{
//			this->data[i] = c.data[i];
//		}
//		this->length = c.length;
//		return *this;
//	}
//};
//class Numb
//{
//private:
//	int num, den;
//public:
//	Numb(int _num = 0, int _den = 0)
//	{
//		set_num(_num);
//		set_den(_den);
//	}
//	int get_num()
//	{
//		return num;
//	}
//	void set_num(int _num)
//	{
//		num = _num;
//	}
//	int get_den()
//	{
//		return den;
//	}
//	void set_den(int _den)
//	{
//		den = _den;
//	}
//	Numb sum(Numb n)
//	{
//		if (den == n.den)
//			return Numb(num + n.num, den);
//		else
//		{
//			int num1 = num * n.den + n.num * den;
//			int den1 = den * n.den;
//			return Numb(num1, den1);
//		}
//	}
//	Numb sub(Numb n)
//	{
//		if (den == n.den)
//			return Numb(num - n.num, den);
//		else
//		{
//			int num1 = num * n.den - n.num * den;
//			int den1 = den * n.den;
//			return Numb(num1, den1);
//		}
//	}
//	Numb mult(Numb n)
//	{
//		return Numb(num * n.num, den * n.den);
//	}
//	Numb div(Numb n)
//	{
//		return Numb(num * n.den, den * n.num);
//	}
//	bool is_equal(Numb n)
//	{
//		return num == n.num && den == n.den;
//	}
//	string show()
//	{
//		if (num % den == 0) return to_string(num / den);
//		else return to_string(num) + "/" + to_string(den);
//	}
//};
//int main()
//{
//	Numb one(3, 2);
//	Numb two(4, 3);
//	Numb sum = one.sum(two);
//	Numb sub = one.sub(two);
//	Numb mult = one.mult(two);
//	Numb div = one.div(two);
//	double eq = one.is_equal(two);
//	cout << sum.show() << endl;
//	cout << sub.show() << endl;
//	cout << mult.show() << endl;
//	cout << div.show() << endl;
//	string s = eq ? "true" : "false";
//	cout << s << endl;
//}