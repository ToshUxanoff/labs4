#include "stdafx.h"
#include "TArrayStruct.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int For_Fill = 666;
	Array <int, 5> a = { 1, 2, 3, 4, 5 };
	std::cout<< "Check at" <<a.at(4) << std::endl;
	std::cout << "Check front " << a.front() << std::endl;
	std::cout << "Check back " << a.back() << std::endl;
	std::cout << "Check empty " << a.empty() << std::endl;
	std::cout << "Check [] " << a[3] << std::endl;
	std::cout << "Check size " << a.size() << std::endl;
	a.fill(For_Fill);
	std::cout << "Check fill (third elem)" << a[3] <<std::endl;
	Array<int, 5> b = { 6, 6, 6, 6, 6 };
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "\nA: " << a[i] << ' ';
	}
	Array<int, 5> x(a);
	x.swap(b);
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "\nX: " << x[i] << ' ';
	}
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "\nB: " << b[i] << ' ';
	}
	system("pause");
	return 0;
}
