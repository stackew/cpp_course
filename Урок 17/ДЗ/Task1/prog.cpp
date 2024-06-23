#define INTEGER
//#define CHAR
//#define DOUBLE

#include <iostream>
#include <vector>
#include "function.h"

#define ARR_SIZE 10


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RU");

	std::vector<int> arr;

#ifdef INTEGER
	InputArr(arr);
#endif

	return 0;
}

