

#include "stdafx.h"
#include "iostream"
template <typename T>
void print(T& a)
{
	std::cout << a << ' ';
	if (a == 100)
	{
		return;
	}
	a++;
	print(a);
}
int _tmain(int argc, _TCHAR* argv[])
{
	double a = 0;
	print<double>(a);
	system("pause");
	return 0;
}

