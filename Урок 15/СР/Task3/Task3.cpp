#include <iostream>
#include "ArrFuncsLibrary.h"

int** add_row(int** arr, int& rows, int cols, int index)
{
    int new_rows = rows + 1;
    int** temp_arr = create_arr(new_rows, cols);

    int k = 0;
    bool isFlag = true;
    for (int i = 0; i != new_rows; i++)
    {
        for (int j = 0; j != cols; j++)
        {
            if (i == index)
            {
                std::cout << "Введите новое значение для [" << i << "][" << j << "]: ";
                std::cin >> temp_arr[i][j];
                if (isFlag)
                {
                    k--;
                    isFlag = false;
                }
            }
            else
            {
                temp_arr[i][j] = arr[k][j];

            }
        }
        k++;
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

    int** arr = create_arr(rows, cols);

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
    std::cout << "Введите индекс строки, которую хотите добавить: ";
    std::cin >> index;
    if (index<0 || index>rows)
    {
        std::cout << "Индекс введен неверно!" << std::endl;
        return 0;
    }
    arr = add_row(arr, rows, cols, index);

    cout_arr(arr, rows, cols);

    delete_arr(arr, rows);

    return 0;
}

