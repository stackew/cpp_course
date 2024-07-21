#include <iostream>

#include "GameFuncsLibrary.h"

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    size_t user_choice_val;
    UserChoice user_choice;

    std::cout << "1)Размер поля" << std::endl
        << "2)Выйти из программы" << std::endl
        << "Что вы хотите выбрать: ";
    std::cin >> user_choice_val;
    while (user_choice_val > 2 || user_choice_val < 1)
    {
        std::cout << "Вы ввели что-то не так!" << std::endl;
        std::cout << "Введите другое значение: ";
        std::cin >> user_choice_val;
    }
    user_choice = static_cast<UserChoice>(user_choice_val);//в функцию

    FieldSize mode;
    switch (user_choice)
    {
    case FIELD_SIZE:
        mode = ModeSelection();
        PlayGame(mode);
        break;
    case EXIT:
        std::cout << "Программа успешно завершена!" << std::endl;
        return 0;
        break;
    default:
        break;
    }

    return 0;
}