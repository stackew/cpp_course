#include <iostream>
#include <vector>
#include <ctime> 

using vector2d = std::vector<std::vector<int>>;

void fill_2darr(vector2d& arr2d)
{
	for (int i = 0; i != arr2d.size(); i++)
	{
		for (int j = 0; j != arr2d[i].size(); j++)
		{
			arr2d[i][j] = rand() % 5;
		}
	}
}

void print_2darr(vector2d const& arr2d)
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

void remove_row_withZeroEl(vector2d& arr2d)
{
	int arrRowsSize = arr2d.size();
	for (int i = 0; i < arrRowsSize; i++)
	{
		for (int j = 0; j < arr2d[i].size(); j++)
		{
			if (arr2d[i][j] == 0)
			{
				arr2d.erase(arr2d.begin() + i);
				arrRowsSize--;
				break;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int rows = 4;
	int cols = 4;
	vector2d arr2d(rows, std::vector<int>(cols));

	fill_2darr(arr2d);
	print_2darr(arr2d);

	std::cout << std::endl;
	remove_row_withZeroEl(arr2d);
	print_2darr(arr2d);

	return 0;
}