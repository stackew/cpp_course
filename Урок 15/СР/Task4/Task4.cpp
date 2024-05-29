#include <iostream>
#include "ArrFuncsLibrary.h"

int** delete_row(int** arr, int& rows, int cols, int index)
{
    int new_rows = rows - 1;
    int** temp_arr = Create_arr(new_rows, cols);

    int k = 0;
    bool isFlag = true;
    for (int i = 0; i != rows; i++)
    {
        for (int j = 0; j != cols; j++)
        {
            if (i != index)
            {
                temp_arr[k][j] = arr[i][j];
            }
            else
            {
                if (isFlag)
                {
                    k--;
                    isFlag = false;
                }
            }
        }
        k++;
    }
    delete_arr(arr, rows);
    rows--;
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
            std::cout << "Введите Arr[" << i + 1 << "][" << j << "]: ";
            std::cin >> arr[i][j];
        }
    }

    cout_arr(arr, rows, cols);

    int index;
    std::cout << "Введите индекс строки, которую хотите удалить: ";
    std::cin >> index;
    if (index<0 || index>rows)
    {
        std::cout << "Индекс введен неверно!" << std::endl;
        return 0;
    }
    arr = delete_row(arr, rows, cols, index);

    cout_arr(arr, rows, cols);

    delete_arr(arr, rows);

    return 0;
}

