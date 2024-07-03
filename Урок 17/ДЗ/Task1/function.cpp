#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

void InputIntArr(std::vector<int>& arr)
{
	for (int i = 0; i != arr.size(); i++)
	{
		arr[i] = rand() % 10;
	}
}

void OutputIntArr(std::vector<int> const& arr)
{
	for (const int& el : arr)
	{
		std::cout << el << " ";
	}
}

void MinIntArrEl(std::vector<int> const& arr)
{
	int min = arr[0];
	for (const int& el : arr)
	{
		if (el < min)
		{
			min = el;
		}
	}
	std::cout << "\nМинимальный элемент: " << min
		<< std::endl;
}

void MaxIntArrEl(std::vector<int> const& arr)
{
	int max = arr[0];
	for (const int& el : arr)
	{
		if (el > max)
		{
			max = el;
		}
	}
	std::cout << "\nМаксимальный элемент: " << max
		<< std::endl;
}

void SortIntArr(std::vector<int>& arr)
{
	std::sort(arr.begin(), arr.end());
}

void EditIntArrEl(std::vector<int>& arr)
{
	int index;
	std::cout << "\nВведите индекс элемента, который хотите поменять: ";
	std::cin >> index;
	if (index >= arr.size() || index < 0)
	{
		std::cout << "Ошибка" << std::endl;
	}
	else
	{
		std::cout << "Введите значение: ";
		std::cin >> arr[index];
	}
}





void InputDoubleArr(std::vector<double>& arr)
{
	for (int i = 0; i != arr.size(); i++)
	{
		arr[i] = rand() % 10;
	}
}

void OutputDoubleArr(std::vector<double> const& arr)
{
	for (const double& el : arr)
	{
		std::cout << el << " ";
	}
}

void MinDoubleArrEl(std::vector<double> const& arr)
{
	double min = arr[0];
	for (const double& el : arr)
	{
		if (el < min)
		{
			min = el;
		}
	}
	std::cout << "\nМинимальный элемент: " << min
		<< std::endl;
}

void MaxDoubleArrEl(std::vector<double> const& arr)
{
	double max = arr[0];
	for (const double& el : arr)
	{
		if (el > max)
		{
			max = el;
		}
	}
	std::cout << "\nМаксимальный элемент: " << max
		<< std::endl;
}

void SortDoubleArr(std::vector<double>& arr)
{
	std::sort(arr.begin(), arr.end());
}

void EditDoubleArrEl(std::vector<double>& arr)
{
	int index;
	std::cout << "\nВведите индекс элемента, который хотите поменять: ";
	std::cin >> index;
	if (index >= arr.size() || index < 0)
	{
		std::cout << "Ошибка" << std::endl;
	}
	else
	{
		std::cout << "Введите значение: ";
		std::cin >> arr[index];
	}
}





void InputCharArr(std::vector<char>& arr)
{
	for (int i = 0; i != arr.size(); i++)
	{
		arr[i] = rand() % 10;
	}
}

void OutputCharArr(std::vector<char> const& arr)
{
	for (const char& el : arr)
	{
		std::cout << el << " ";
	}
}

void MinCharArrEl(std::vector<char> const& arr)
{
	char min = arr[0];
	for (const char& el : arr)
	{
		if (el < min)
		{
			min = el;
		}
	}
	std::cout << "\nМинимальный элемент: " << min
		<< std::endl;
}

void MaxCharArrEl(std::vector<char> const& arr)
{
	char max = arr[0];
	for (const char& el : arr)
	{
		if (el > max)
		{
			max = el;
		}
	}
	std::cout << "\nМаксимальный элемент: " << max
		<< std::endl;
}

void SortCharArr(std::vector<char>& arr)
{
	std::sort(arr.begin(), arr.end());
}

void EditCharArrEl(std::vector<char>& arr)
{
	int index;
	std::cout << "\nВведите индекс элемента, который хотите поменять: ";
	std::cin >> index;
	if (index >= arr.size() || index < 0)
	{
		std::cout << "Ошибка" << std::endl;
	}
	else
	{
		std::cout << "Введите значение: ";
		std::cin >> arr[index];
	}
}