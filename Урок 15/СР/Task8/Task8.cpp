#include <iostream> 

template <typename T>
T* createNDimensionalArray(const int* dimensions, int numDimensions) {
    // Вычисляем общий размер массива 
    int totalSize = 1;
    for (int i = 0; i < numDimensions; ++i) {
        totalSize *= dimensions[i];
    }

    // Создаем динамический массив с нужным размером 
    T* array = new T[totalSize];

    // Заполняем массив нулями (или другими значениями по умолчанию) 

    // Возвращаем указатель на созданный массив 
    return array;
}

int main() {
    // Пример использования функции 
    int dimensions[] = { 2, 5, 3, 4, 10 };
    int numDimensions = sizeof(dimensions) / sizeof(dimensions[0]);
    int* myArray = createNDimensionalArray<int>(dimensions, numDimensions);

    // Выводим размеры массива 
    std::cout << "Размеры массива: ";
    for (int i = 0; i < numDimensions; ++i) {
        std::cout << dimensions[i] << " ";
    }
    std::cout << std::endl;

    // Выводим адрес первого элемента массива 
    std::cout << "Адрес первого элемента: " << &myArray[0] << std::endl;

    // Не забываем освободить память после использования массива 
    delete[] myArray;

    return 0;
}