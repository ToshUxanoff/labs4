
#include "stdafx.h"
#include "TVector.h"
#include <iostream>
#include <stdint.h>
template <typename T>
void printVector(const TVector<T>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

int main()
{
	{
		TVector <double>vec;
		for (float i = 0; i < 32; ++i)
		{
			vec.push_back(i);
		}
		printVector(vec);
		std::cout << "Insert pered 10 1 elementa" << std::endl;
		vec.insert(vec.begin() + 10, 1000);
		printVector(vec);
		std::cout << "insert pered 6 5 elementov" << std::endl;
		vec.insert(vec.begin()+6, 5, 666);
		printVector(vec);
		std::cout << "ERASE 0-10" << std::endl;
		vec.erase(vec.begin(), vec.begin() + 10);
		printVector(vec);
		std::cout << "ERASE begin" << std::endl;
		vec.erase(vec.begin());
		printVector(vec);

		std::cout << vec.front() << std::endl;
		std::cout << vec.back() << std::endl;

		vec.pop_back();
		std::cout << vec.back() << std::endl;

		size_t oldSize = vec.size();
		vec.resize(44);
		printVector(vec);

		vec.resize(oldSize);
		printVector(vec);

		TVector <double>vec2;
		for (int i = 0; i < 2; ++i)
		{
			vec2.push_back(i);
		}

		vec2.swap(vec);
		printVector(vec2);
		printVector(vec);

		vec2 = vec;
		printVector(vec2);
		printVector(vec);

		try
		{
			TVector<double>::value_type item = vec2.at(1000000);
		}
		catch (const std::exception & e)
		{
			std::cout << e.what();
		}

		try
		{
			vec2.resize(UINT64_MAX);
		}
		catch (const std::exception & e)
		{
			std::cout << e.what();
		}
	}
	
	system("pause");
}
