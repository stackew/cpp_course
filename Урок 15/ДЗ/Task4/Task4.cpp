#include <iostream>
#include <ctime>
#include "MatrixFuncsLibrary.h";

int** matrix_transposition(int** matrix, int& rows, int& cols)
{
    int new_rows = cols;
    int new_cols = rows;
    int** new_matrix = create_matrix(new_rows, new_cols);

    int f = 0, s = 0;
    for (int i = 0; i != new_rows; i++)
    {
        for (int j = 0; j != new_cols; j++)
        {
            new_matrix[i][j] = matrix[f][s];
            f++;
        }
        f = 0;
        s++;
    }

    delete_matrix(matrix, rows);
    rows = new_rows;
    cols = new_cols;

    return new_matrix;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "RU");

    int rows, cols;
    std::cout << "Введите количество строк матрицы: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов матрицы: ";
    std::cin >> cols;

    int** matrix = create_matrix(rows, cols);
    matrix_initialization(matrix, rows, cols);

    std::cout << "Ваша матрица:" << std::endl;
    matrix_output(matrix, rows, cols);

    matrix = matrix_transposition(matrix, rows, cols);

    std::cout << "Ваша транспонированная матрица: " << std::endl;
    matrix_output(matrix, rows, cols);

    delete_matrix(matrix, rows);

    return 0;
}