#include <iostream>
#include <string>
using namespace std;
class Numb
{
private:
	int num, den;
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
			return num * n.den < n.num* den;
	}
	bool operator<=(Numb n)
	{
		if (den == n.den)
			return num <= n.num;
		else
			return num * n.den <= n.num * den;
	}
	Numb& operator+=(Numb n)
	{
		if (den == n.den)
			num += n.num;
		else
		{
			num *= n.den;
			num += n.num * den;
			den *= n.den;
		}
		return *this;
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

struct Link
{
	int data;
	Link* next;
};
class List
{
private:
	Link* current;
	int count;
public:
	List()
	{
		current = nullptr;
		count = 0;
	}
	void add_item(int);//Добавление элементов в конец списка
	void add_item_s(int);//Добавление элементов в начало списка
	void show();//Вывод элементов списка
	int length();//Получение количества элементов списка
	void insert_item(int, int);//Вставление элемента на указанную позицию
	void remove_all();//Удаление всех элементов
	void remove_first();//Удаление первого элемента списка
	void remove_last();//Удаление последнего элемента списка
	void remove_item(int);//Удаление элемента на указанной позиции
	void remove_between(int, int);//Удаление элементов в диапозоне между двумя указанными позициями
};
void List::add_item(int val)
{
	Link* new_link = new Link;
	new_link->data = val;
	new_link->next = current;
	current = new_link;
	count++;
}
void List::add_item_s(int val)
{
	Link* temp = current;
	while (temp)
	{
		if (!temp->next)
		{
			Link* new_link = new Link;
			new_link->data = val;
			new_link->next = temp->next;
			temp->next = new_link;
			count++;
			break;
		}
		temp = temp->next;
	}
}
void List::insert_item(int val, int pos)
{
	if (pos <= 0 && !(current))
	{
		add_item(val);
		return;
	}
	Link* temp = current;
	for (int i = 1; i < pos && temp->next; ++i)
		temp = temp->next;
	Link* new_link = new Link;
	new_link->data = val;
	new_link->next = temp->next;
	temp->next = new_link;
	count++;
}
void List::remove_first()
{
	if (!current) return;
	Link* temp = current;
	current = temp->next;
	delete temp;
	--count;
}
void List::remove_last()
{
	if (!current) return;
	if (!current->next) {
		remove_first();
		return;
	}
	Link* temp = current;
	while (temp->next->next) temp = temp->next;
	temp->next = nullptr;
	delete temp->next;
	--count;
}
void List::remove_item(int ind)
{
	if (!current) return;
	if (count - 1 == ind) {
		remove_first();
		return;
	}
	else if (ind == 0) {
		remove_last();
		return;
	}
	Link* temp = current;
	Link* temp_next = current->next;
	for (int i = 1; i < ind && temp->next; ++i)
	{
		temp = temp->next;
		temp_next = temp_next->next;
	}
	temp->next = temp_next->next;
	delete temp_next;
	--count;
}
void List::remove_all()
{
	while (current)
	{
		remove_first();
	}
}
void List::remove_between(int f, int l)
{
	int k = l - f + 1;
	for (int i = 1; i <= k; ++i)
		remove_item(f);
}

int List::length()
{
	return count;
}

void List::show()
{
	Link* temp = current;
	while (temp)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

int main()
{
	{
		Numb one(3, 2);
		Numb two(4, 3);
		Numb sum = one + two;
		Numb sub = one - two;
		Numb mult = one * two;
		Numb div = one / two;
		double eq = one == two;
		cout << sum.show() << endl;
		cout << sub.show() << endl;
		cout << mult.show() << endl;
		cout << div.show() << endl;
		string s = eq ? "true" : "false";
		cout << s << endl;
		s = (one >= two) ? "true" : "false";
		cout << s << endl;
		one += two;
		cout << one.show() << endl;
	}

	cout << "---------------------------" << endl;
	List list;
	list.insert_item(6, 0);
	list.add_item(3);
	list.add_item(5);
	list.add_item(9);
	list.show();
	cout << endl;
	list.add_item_s(1);
	list.show();
	cout << "count of elements: " << list.length() << endl;
	list.insert_item(6, 2);
	list.show();
	cout << endl;
	list.remove_between(2, 3);
	list.show();
	cout << "between" << endl;
	list.remove_first();
	list.show();
	cout << endl;
	list.remove_last();
	list.show();
	cout << endl;
	list.remove_item(1);
	list.show();
	cout << endl;
	list.remove_all();
	cout << "count of elements: " << list.length() << endl;
}