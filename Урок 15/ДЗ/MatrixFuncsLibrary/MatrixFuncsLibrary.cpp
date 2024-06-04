#include <iostream>
#include <ctime>

int** create_matrix(int rows, int cols)
{
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
	return matrix;
}

void delete_matrix(int** matrix, int rows)
{
	for (int i = 0; i != rows; i++)
	{
		delete matrix[i];
	}
	delete[] matrix;
}

void matrix_initialization(int** Matrix, int rows, int cols)
{
	for (int i = 0; i != rows; i++)
	{
		for (int j = 0; j != cols; j++)
		{
			Matrix[i][j] = rand() % 10;
		}
	}
}

void matrix_output(int** Matrix, int rows, int cols)
{
	for (int i = 0; i != rows; i++)
	{
		for (int j = 0; j != cols; j++)
		{
			std::cout << Matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}