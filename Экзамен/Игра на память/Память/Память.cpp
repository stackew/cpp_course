#include <iostream>
#include "Important.h"
#include "GameFuncsLibrary.h"
int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    std::map <int, char> ConvertToSymbols;
    Init_Map(ConvertToSymbols);

    int rows, cols, MaxRandNum;

    int SizeVal;
    FieldSize FSize;

    int BreakCycle;
    do
    {
        std::cout << "---Игра на память---" << std::endl
            << "1)2x2" << std::endl
            << "2)4x4" << std::endl
            << "3)6x6" << std::endl                             //Выбор размера поля
            << "Выбор размера поля: ";
        std::cin >> SizeVal;
        FSize = static_cast<FieldSize>(SizeVal);

        BreakCycle = SetFieldSize(rows, cols, MaxRandNum, FSize);
    } while (BreakCycle < 0);

    _getch();
    system("cls");




    vector2dint Field(rows, std::vector<int>(cols));

    std::vector<int> used_nums;                             //Генерация игрового поля

    GenerateField(Field, used_nums, rows, cols, MaxRandNum);





   int Player1Points = 0, Player2Points = 0;

    int TurnVal = 0;
    Turn WhichTurn;

    vector2dchar ClosedField(rows, std::vector<char>(cols));
    for (int i = 0; i != ClosedField.size(); i++)
    {
        for (int j = 0; j != ClosedField[i].size(); j++)        //Заполнение интерфейса поля и объявление переменных
        {
            ClosedField[i][j] = '#';
        }
    }

    std::vector<Card> OpenedCards;

    int FlipsNumber = 0;





    auto timer_start = std::chrono::high_resolution_clock::now();

    do
    {
        std::cout << "---Начало раунда---" << std::endl;

        PrintClosedField(ClosedField);


        std::cout << "Ходит " << TurnVal + 1 << " игрок:" << std::endl;
        Card card1, card2;
        while (true)
        {
            std::cout << "Введите индекс 1 карты которую хотите открыть (Строка, столбец): ";
            std::cin >> card1.RowIndex >> card1.ColIndex;
            if (isAlreadyOpened(card1, OpenedCards))
            {
                std::cout << "Карта уже была открыта!" << std::endl;
            }
            else if (card1.RowIndex >= rows || card1.RowIndex < 0                               //Проверка первой карты на правильность
                || card1.ColIndex >= cols || card1.ColIndex < 0)
            {
                std::cout << "Карты с таким индексом не существует" << std::endl;
            }
            else
            {
                break;
            }
        }

        while (true)
        {
            std::cout << "Введите индекс 2 карты которую хотите открыть (Строка, столбец): ";
            std::cin >> card2.RowIndex >> card2.ColIndex;
            if (isAlreadyOpened(card2, OpenedCards))
            {
                std::cout << "Карта уже была открыта!" << std::endl;
            }
            else if (card2.RowIndex >= rows || card2.RowIndex < 0
                || card2.ColIndex >= cols || card2.ColIndex < 0)
            {
                std::cout << "Карты с таким индексом не существует" << std::endl;               //Проверка второй карты на правильность
            }
            else if (card2.RowIndex == card1.RowIndex &&
                card2.ColIndex == card1.ColIndex)
            {
                std::cout << "Нельзя открыть 1 карту" << std::endl;
            }
            else
            {
                break;
            }
        }

        FlipsNumber += 2;
 
        PrintOpenedCards(card1, card2, Field, OpenedCards, ConvertToSymbols);

        WhichTurn = static_cast<Turn>(TurnVal);
        if (isMatch(card1, card2, Field))
        {
            ClosedField[card1.RowIndex][card1.ColIndex] = ' ';
            ClosedField[card2.RowIndex][card2.ColIndex] = ' ';

            OpenedCards.push_back(card1);
            OpenedCards.push_back(card2);

            switch (WhichTurn)
            {
            case PLAYER1:
                Player1Points ++;                                               //Проверка на нахождение пары
                std::cout << "Первый игрок получает очко!" << std::endl;
                break;
            case PLAYER2:
                Player2Points++;
                std::cout << "Второй игрок получает очко!" << std::endl;
                break;
            default:
                break;
            }
            PlaySound(TEXT("correct-answer-sound.wav"), NULL, SND_FILENAME | SND_SYNC);
        }
        else
        {
            PlaySound(TEXT("wrong-answer-sound.wav"), NULL, SND_FILENAME | SND_SYNC);
        }

        switch (WhichTurn)
        {
        case PLAYER1:
            TurnVal = PLAYER2;
            break;
        case PLAYER2:                   //Переход хода другому игроку
            TurnVal = PLAYER1;
            break;
        default:
            break;
        }

        std::cout << "Количество очков первого игрока: " << Player1Points << std::endl;
        std::cout << "Количество очков второго игрока: " << Player2Points << std::endl;

        std::cout << "---Конец раунда---" << std::endl;
        _getch();

        system("cls");
    } while (Player1Points + Player2Points != (rows * rows) / 2);

    auto timer_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = timer_end - timer_start;

    if (Player1Points > Player2Points)
    {
        std::cout << "---Победил 1 игрок со счетом: " << Player1Points << " очков---"
            << std::endl;
    }
    else if (Player1Points < Player2Points)
    {
        std::cout << "---Победил 2 игрок со счетом: " << Player2Points << " очков---"       //Определние победителя
            << std::endl;
    }
    else
    {
        std::cout << "-----Игра закончилась ничьей!-----" << std::endl;
    }

    std::cout << "Время игры: " << duration.count() << std::endl;
    std::cout << "Количество переворотов карт: " << FlipsNumber << std::endl;           //Доп. данные
    return 0;
}