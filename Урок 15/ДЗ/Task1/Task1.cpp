#include <iostream>
#include "ArrFuncsLibrary.h"

int** add_to_twodarr(int** arr, int rows, int& cols)
{
	int col_index;
	std::cout << "Введите индекс столбца, который хотите добавить: "; //2 4 1
	std::cin >> col_index;
	if (col_index >= cols || col_index < 0)
	{
		return 0;
	}

	int new_cols = cols + 1;
	int** temp_arr = create_arr(rows, new_cols);


	std::cout << "Введите значения для нового столбца: " << std::endl;
	size_t k = 0;
	size_t cout_count = 1;
	for (int i = 0; i != rows; i++)
	{
		for (int j = 0; j != new_cols; j++)
		{
			if (j == col_index)
			{
				std::cout << cout_count << ") ";
				std::cin >> temp_arr[i][j];
				cout_count++;
			}
			else
			{
				temp_arr[i][j] = arr[i][k];
				k++;
			}
		}
		k = 0;
	}
	delete_arr(arr, rows);

	cols++;

	return temp_arr;
}

int main()
{
	setlocale(LC_ALL, "RU");

	int rows;
	std::cout << "Введите количество строк: ";
	std::cin >> rows;

	int cols;
	std::cout << "Введите количество столбцов: ";
	std::cin >> cols;

	int** arr = create_arr(rows, cols);
	input_arr(arr, rows, cols);
	cout_arr(arr, rows, cols);

	arr = add_to_twodarr(arr, rows, cols);

	if (arr != nullptr)
	{
		cout_arr(arr, rows, cols);
		delete_arr(arr, rows);
	}
	else
	{
		std::cout << "Индекс был введен неправильно" << std::endl;
	}

	return 0;
}


