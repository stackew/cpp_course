#include <iostream>
#include <vector>
#include <ctime>

#define ROWS 4
#define COLS 5
using vector2d = std::vector<std::vector<int>>;

void fill2darr(vector2d& arr2d)
{
	for (int i = 0; i != ROWS; i++)
	{
		for (int j = 0; j != COLS; j++)
		{
			arr2d[i][j] = rand() % 15;
		}
	}
}

void print2darr(vector2d const& arr2d)
{
	for (const std::vector<int>& row : arr2d)
	{
		for (const int& el : row)
		{
			std::cout << el << " ";
		}
		std::cout << std::endl;
	}
}

vector2d arr2dSumm(vector2d const& arr1, vector2d const& arr2)
{
	vector2d arr3(ROWS, std::vector<int>(COLS));
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr3[i][j] = arr1[i][j] + arr2[i][j];
		}
	}
	return arr3;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	vector2d arr1(ROWS, std::vector<int>(COLS));
	vector2d arr2(ROWS, std::vector<int>(COLS));

	fill2darr(arr1);
	fill2darr(arr2);

	std::cout << "Первый массив: " << std::endl;
	print2darr(arr1);
	std::cout << "Второй массив: " << std::endl;
	print2darr(arr2);

	vector2d arr3 = arr2dSumm(arr1, arr2);
	std::cout << "Третий массив: " << std::endl;
	print2darr(arr3);

	return 0;
}
