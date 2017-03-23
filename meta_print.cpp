
#include "stdafx.h"
#include "iostream"
template <class T>
void print()
{
	static T a = 0;
	if (a == 100)
	{
		return;
	}
	a++;
	std::cout << a << ' ';
	print<T>();
}
int _tmain(int argc, _TCHAR* argv[])
{
	print<int>();
	system("pause");
	return 0;
}
