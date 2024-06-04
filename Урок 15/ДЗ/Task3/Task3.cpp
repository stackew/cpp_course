#include <iostream>
#include <ctime>
#include "MatrixFuncsLibrary.h"


enum Sides
{
	RIGHT = 1,
	LEFT = 2,
	UP = 3,
	DOWN = 4
};

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
			Matrix[i][j] = rand() %  10;
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

void FRIGHT(int** shifted_matrix, int** matrix,
	int rows, int cols, int shift_index, int temp_index)
{
	for (int i = 0; i != rows; i++)
	{
		for (int j = 0; j != cols; j++)
		{
			if (shift_index != 0)
			{
				shifted_matrix[i][j] = matrix[i][cols - shift_index];
				shift_index--;
			}
			else
			{
				shifted_matrix[i][j] = matrix[i][j - temp_index];
			}
		}
		shift_index = temp_index;
	}
}

void FLEFT(int** shifted_matrix, int** matrix,
	int rows, int cols, int shift_index, int temp_index)
{
	for (int i = 0; i != rows; i++)
	{
		for (int j = 0; j != cols; j++)
		{
			if (cols - shift_index != 0)
			{
				shifted_matrix[i][j] = matrix[i][shift_index];
				shift_index++;
			}
			else
			{
				shifted_matrix[i][j] = matrix[i][j - (cols - temp_index)];
			}
		}
		shift_index = temp_index;
	}
}

void FUP(int** shifted_matrix, int** matrix,
	int rows, int cols, int shift_index)
{
	int count = 0;
	for (int i = 0; i != rows; i++)
	{
		for (int j = 0; j != cols; j++)
		{
			if (shift_index < rows)
			{
				shifted_matrix[i][j] = matrix[shift_index][j];
			}
			else
			{
				shifted_matrix[i][j] = matrix[count][j];
			}
		}
		shift_index < rows ? shift_index++ : count++;
	}
}

void FDOWN(int** shifted_matrix, int** matrix,
	int rows, int cols, int shift_index)
{
	int count = 0;
	for (int i = 0; i != rows; i++)
	{
		for (int j = 0; j != cols; j++)
		{
			if (rows - shift_index != rows)
			{
				shifted_matrix[i][j] = matrix[rows - shift_index][j];
			}
			else
			{
				shifted_matrix[i][j] = matrix[count][j];
			}
		}
		rows - shift_index != rows ? shift_index-- : count++;
	}
}
int** matrix_shift(int** matrix, int rows, int cols)
{
	int** shifted_matrix = create_matrix(rows, cols);
	int val;
	std::cout << "В какую сторону вы хотите сдвинуть матрицу: "
		<< std::endl << "1)Право\n2)Лево\n3)Вверх\n4)Вниз\nОтвет: ";
	std::cin >> val;
	Sides side = static_cast<Sides>(val);
	int shift_index;
	std::cout << "На сколько позиций вы хотите сдвинуть матрицу: ";
	std::cin >> shift_index;

	if (shift_index < 0)
	{
		return 0;
	}

	if ((side == RIGHT || side == LEFT) && shift_index >= cols)
	{
		shift_index = shift_index - cols;
	}
	if ((side == UP || side == DOWN) && shift_index >= rows)
	{
		shift_index = shift_index - rows;
	}
	int temp_index = shift_index;

	switch (side)
	{
	case RIGHT:
		FRIGHT(shifted_matrix, matrix, rows, cols, shift_index, temp_index);
		break;
	case LEFT:
		FLEFT(shifted_matrix, matrix, rows, cols, shift_index, temp_index);
		break;
	case UP:
		FUP(shifted_matrix, matrix, rows, cols, shift_index);
		break;
	case DOWN:
		FDOWN(shifted_matrix, matrix, rows, cols, shift_index);
		break;
	default:
		break;
	}
	delete_matrix(matrix, rows);

	return shifted_matrix;
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RU");
	int M, N;
	std::cout << "Введите количество строк матрицы: ";
	std::cin >> M;
	std::cout << "Введите количество столбцов матрицы: ";
	std::cin >> N;

	int** matrix = create_matrix(M, N);
	matrix_initialization(matrix, M, N);
	std::cout << "Your matrix:" << std::endl;
	matrix_output(matrix, M, N);

	matrix = matrix_shift(matrix, M, N);
	if (matrix == NULL)
	{
		std::cout << "Такого индекса не существует!" << std::endl;
		return 0;
	}
	else
	{
		matrix_output(matrix, M, N);

		delete_matrix(matrix, M);
		return 0;
	}
}

