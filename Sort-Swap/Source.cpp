#include "stdafx.h"
#include "iostream"
#include "vector"
template <typename T>
//swap//
void swap(T &a, T &b)
{
	T buf = a;
	a = b;
	b = buf;
}
template <class IT>
//sort//
void sort(IT beg, IT end)
{
	for (IT i = beg; i != end; ++i)
	{
		for (IT j = beg; j != end; ++j)
		{
			if (*i < *j)
			{
				swap(*i, *j);
			}
		}
	}
}
template <class IT>
//print//
void print(IT beg, IT end)
{
	for (IT i = beg; i != end; ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	char* a = "  asdf";
	char *b = "  neasdf";
	std::cout << a << b << std::endl;
	swap <char*>(a, b);
	std::cout << a << b << std::endl;
	int arr[] = { 123, 3, 0, 13212, -100 };
	sort(&arr[0], &arr[3]); // arr: 0, 3, 123, 13212, -100
	print(arr, &arr[5]);
	sort(&arr[2], &arr[5]); // arr: 0, 3, -100, 123, 13212
	print(arr, &arr[5]);

	std::vector<double> vec = { 123.0, 3.0, 0.0, 13212.0, -100.0 };
	sort(vec.begin(), vec.end()); // vec: -100.0, 0.0, 3.0, 123.0, 13212.0
	print(vec.begin(), vec.end());
	system("pause");
	return 0;
}
