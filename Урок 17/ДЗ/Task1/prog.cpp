#define INTEGER
//#define DOUBLE
//#define CHAR

#include <iostream>
#include <vector>
#include <ctime>
#include "function.h"


#define ARR_SIZE 10


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RU");
#ifdef INTEGER
	std::vector<int> arr(ARR_SIZE);
#elif defined DOUBLE
	std::vector<double> arr(ARR_SIZE);
#else
	std::vector<char> arr(ARR_SIZE);
#endif
	InputArr(arr);

	OutputArr(arr);

	MinArrEl(arr);
	MaxArrEl(arr);

	SortArr(arr);
	OutputArr(arr);

	EditArrEl(arr);
	OutputArr(arr);
	return 0;
}
