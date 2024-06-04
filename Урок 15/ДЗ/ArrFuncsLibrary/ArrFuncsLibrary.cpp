#include <iostream>

int** create_arr(int rows, int cols)
{
    int** arr = new int* [rows];
    for (int i = 0; i != rows; i++)
    {
        arr[i] = new int[cols];
    }
    return arr;
}

void delete_arr(int** arr, int rows)
{
    for (int i = 0; i != rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
void cout_arr(int** arr, int rows, int cols)
{
    for (int i = 0; i != rows; i++)
    {
        for (int j = 0; j != cols; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void input_arr(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << "Array [" << i << "][" << j << "]= ";
            std::cin >> arr[i][j];
        }
    }
}
