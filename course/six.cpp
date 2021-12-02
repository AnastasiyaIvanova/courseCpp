#include <iostream>
#include <string>
#include "my_vector.h"
using namespace std;

int main()
{
	MyVector<int> v;
	v.push_back(2);
	v.push_back(6);
	v.push_back(10);
	v.show();
	MyVector<int> two = v;
	two[3] = 3;
	two.show();
	cout << two.back() << endl;
	v.clear();
	cout << v.get_size() << endl;
	MyVector<int> l;
	l.insert(l.begin(), 11);
	l.push_back(99);
	//l.resize(3);
	l.erase(l.begin());
	//l.pop_back();
	l.show();
	cout << l.empty() << endl;
}