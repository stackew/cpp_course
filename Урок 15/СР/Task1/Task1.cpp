#include <iostream>
#include "ArrFuncsLibrary.h"


int** add_row(int** arr, int& rows, int cols)
{
    int new_rows = rows + 1;
    int** temp_arr = Create_arr(new_rows, cols);

    for (int i = 0; i != new_rows; i++)
    {
        for (int j = 0; j != cols; j++)
        {
            if (i == rows)
            {
                std::cout << "Введите новое значение для [" << i << "][" << j << "]: ";
                std::cin >> temp_arr[i][j];
            }
            else
            {
                temp_arr[i][j] = arr[i][j];
            }
        }
    }
    delete_arr(arr, rows);
    rows++;
    return temp_arr;
}
int main()
{
    setlocale(LC_ALL, "RU");
    int rows, cols;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    int** arr = Create_arr(rows, cols);

    for (int i = 0; i != rows; i++)
    {
        for (int j = 0; j != cols; j++)
        {
            std::cout << "Введите Arr[" << i << "][" << j << "]: ";
            std::cin >> arr[i][j];
        }
    }

    cout_arr(arr, rows, cols);

    arr = add_row(arr, rows, cols);

    cout_arr(arr, rows, cols);

    delete_arr(arr, rows);

    return 0;
}


