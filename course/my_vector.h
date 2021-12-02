#pragma once
#include <iostream>
using namespace std;
template<typename T> class MyVector
{
private:
	T* arr;
	int capacity;
	int size;
public:
	MyVector()
	{
		arr = new T[1];
		capacity = 1;
		size = 0;
	}
	MyVector& operator=(MyVector& v)
	{
		this->arr = new char[v.length];
		for (int i = 0; i < v.length; i++)
		{
			this->arr[i] = v.arr[i];
		}
		this->size = v.size;
		return *this;
	}
	T& operator[](int index)
	{
		return arr[index];
	}
	T& front()
	{
		return arr[0];
	}
	T& back()
	{
		return arr[size - 1];
	}
	T* begin()
	{
		return arr;
	}
	T* end()
	{
		return arr + size;
	}
	void clear()
	{
		delete[] arr;
		arr = nullptr;
		size = 0;
		capacity = 0;
	}
	void resize(int new_size)
	{
		capacity *= 2 * new_size;
		T* temp = new T[capacity];

		for (int i = 0; i != min(size, new_size); i++)
			temp[i] = arr[i];

		delete[] arr;
		size = new_size;
		arr = temp;
	}
	T* insert(T* pos, const T& x)
	{
		int tmp = pos - begin();
		if (size + 1 > capacity)
			resize(size + 1);
		else
			++size;
		pos = begin() + tmp;
		for (auto i = end() - 1; i != pos; --i)
			*i = *(i - 1);
		*pos = x;
		return pos;
	}
	T* erase(T* pos)
	{
		for (auto i = pos; i != end(); ++i)
			*i = *(i + 1);
		--size;
		return pos;
	}
	void push_back(const T& val)
	{
		if (size == capacity)
		{
			T* temp = new T[2 * capacity];
			for (int i = 0; i < size; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			capacity *= 2;
			arr = temp;
		}
		arr[size] = val;
		size++;
	}
	void pop_back()
	{
		if (size > 0)
		{
			size--;
		}
	}
	bool empty() const
	{
		return size == 0;
	}
	void reserve(int new_capacity)
	{
		if (new_capacity > capacity)
		{
			T* new_vector = new T[new_capacity];
			for (int i = 0; i < size; ++i)
			{
				new_vector[i] = arr[i];
				delete[] arr;
			}
			arr = new_vector;
			capacity = new_capacity;
		}
	}
	T get(int index)
	{
		if (index < size)
		{
			return arr[index];
		}
	}
	int get_size()
	{
		return size;
	}
	int get_capacity()
	{
		return capacity;
	}
	void shrink_to_fit()
	{
		capacity = size;
	}
	void show()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << endl;
		}
	}
};
