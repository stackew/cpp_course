#include <iostream>

#include "GameFuncsLibrary.h"

bool IsMatch(Card& card1, Card& card2, IntMatrix const& Field)
{
    return Field[card1.RowIndex][card1.ColIndex] == Field[card2.RowIndex][card2.ColIndex]; //Проверка совпали ли карты
}

bool IsAlreadyOpened(Card& card, std::vector<Card> const& OpenedCards)
{
    for (const Card& opened_card : OpenedCards)
    {
        if (card.RowIndex == opened_card.RowIndex &&
            card.ColIndex == opened_card.ColIndex)                 //Проверка была ли карта открыта ранее
        {
            return true;
        }
    }
    return false;
}

bool IsFree(IntMatrix const& Field, const int& row_pos,
    const int& col_pos)
{
    return Field[row_pos][col_pos] == NULL;            //Проверка свободна ли позиция в поле
}

void PrintMarking(const int& amount)
{
    int count = 0;
    std::cout << "  ";
    for (int i = 0; i != amount; i++)
    {
        std::cout << count++ << " ";
    }
                                        //Вывести разлиновку поля
    std::cout << std::endl << " ";

    for (int i = 0; i != count; i++)
    {
        std::cout << "==";
    }

    std::cout << std::endl;
}

void PrintClosedField(CharMatrix const& ClosedField)
{
    int count = 0;
    PrintMarking(ClosedField.size());
    for (int i = 0; i != ClosedField.size(); i++)
    {
        std::cout << count++ << "|";
        for (int j = 0; j != ClosedField[i].size(); j++)    //Вывести после с закрытыми картами
        {
            std::cout << ClosedField[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void PrintOpenedCards(const Card& card1, const Card& card2, IntMatrix const& Field,
    std::vector<Card> const& OpenedCards)
{
    Card card;
    int count = 0;

    PrintMarking(Field.size());
    for (int i = 0; i != Field.size(); i++)
    {
        std::cout << count++ << "|";
        for (int j = 0; j != Field[i].size(); j++)
        {
            card.RowIndex = i;
            card.ColIndex = j;
            if (i == card1.RowIndex && j == card1.ColIndex)
            {
                std::cout << ConvertToSymbols[Field[i][j]] << " ";                        //Вывести поле, с открытыми картами
            }
            else if (i == card2.RowIndex && j == card2.ColIndex)
            {
                std::cout << ConvertToSymbols[Field[i][j]] << " ";;
            }
            else if (IsAlreadyOpened(card, OpenedCards))
            {
                std::cout << "  ";
            }
            else
            {
                std::cout << "#" << " ";
            }
        }
        std::cout << std::endl;
    }
}

int SetFieldSize(int& rows, int& cols, int& MaxRandNum, FieldSize const& FSize)
{
    switch (FSize)
    {
    case TWO_BY_TWO:
        rows = 2;
        cols = 2;
        MaxRandNum = 4;
        break;
    case FOUR_BY_FOUR:
        rows = 4;
        cols = 4;
        MaxRandNum = 9;
        break;                                                                          //Установка параметров размера поля
    case SIX_BY_SIX:
        rows = 6;
        cols = 6;
        MaxRandNum = 20;
        break;
    case EXIT:
        return 1;
    default:
        std::cout << "Вы ввели что-то неправильно";
        return -1;
        break;
    }
    return 0;
}

void AddPair(IntMatrix& Field, const int& el, const int& size)
{
    bool isCheck = false;
    int rand_row = rand() % size;
    int rand_col = rand() % size;

    while (!isCheck)
    {
        if (IsFree(Field, rand_row, rand_col))
        {
            Field[rand_row][rand_col] = el;                        //Добавление пары числа
            isCheck = true;
        }
        else
        {
            rand_row = rand() % size;
            rand_col = rand() % size;
        }
    }
}

void GenerateField(IntMatrix& Field, std::vector<int>& used_nums,
    const int& rows, const int& cols, const int& MaxRandNum)
{
    for (int i = 0; i != rows; i++)
    {
        for (int j = 0; j != cols; j++)
        {
            if (IsFree(Field, i, j))
            {
                int el;
                while (true)
                {
                    el = rand() % MaxRandNum;
                    if (std::find(used_nums.begin(), used_nums.end(), el) == used_nums.end()) //Генерация чисел
                    {
                        Field[i][j] = el;
                        used_nums.push_back(el);
                        break;
                    }
                }
                AddPair(Field, el, rows);
            }
        }
    }
}

bool IsCorrect(Card& card1, Card& card2, const int& rows, const int& cols,
    std::vector<Card> const& OpenedCards)
{
    std::cout << "Введите индекс 1 карты, которую хотите открыть (Строка, Столбец): ";
    std::cin >> card1.RowIndex >> card1.ColIndex;
    std::cout << "Введите индекс 2 карты, которую хотите открыть (Строка, Столбец): ";
    std::cin >> card2.RowIndex >> card2.ColIndex;
    if (IsAlreadyOpened(card1, OpenedCards) || IsAlreadyOpened(card2, OpenedCards)
        || (card1.RowIndex == card2.RowIndex && card1.ColIndex == card2.ColIndex))
    {
        std::cout << "Одна из карт уже была открыта!" << std::endl;
        return false;
    }
    else if (card1.RowIndex >= rows || card1.RowIndex < 0                               //Проверка карт на правильность
        || card1.ColIndex >= cols || card1.ColIndex < 0 ||
        card2.RowIndex >= rows || card2.RowIndex < 0 ||
        card2.ColIndex >= cols || card2.ColIndex < 0)
    {
        std::cout << "Карты с таким индексом не существует" << std::endl;
        return false;
    }
    else
    {
        return true;
    }
}

FieldSize ModeSelection()
{
    int SizeVal;
    FieldSize FSize;

    std::cout << "\n---Игра на память---" << std::endl
        << "1)2x2" << std::endl
        << "2)4x4" << std::endl
        << "3)6x6" << std::endl
        << "4)Выход" << std::endl
        << "Выбор размера поля: ";
    std::cin >> SizeVal;
    FSize = static_cast<FieldSize>(SizeVal);

    return FSize;
}

void Turns(int& Player1Points, int& Player2Points, CharMatrix& ClosedField,
    int& FlipsNumber, const IntMatrix& Field)
{
    std::vector<Card> OpenedCards;
    int TurnVal = 0;
    Turn WhichTurn;

    do
    {
        std::cout << "---Начало раунда---" << std::endl;

        PrintClosedField(ClosedField);


        std::cout << "Ходит " << TurnVal + 1 << " игрок:" << std::endl;
        Card card1, card2;
        while (!IsCorrect(card1, card2, Field.size(), Field.size(), OpenedCards));

        FlipsNumber += 2;

        PrintOpenedCards(card1, card2, Field, OpenedCards);

        WhichTurn = static_cast<Turn>(TurnVal);
        if (IsMatch(card1, card2, Field))
        {
            ClosedField[card1.RowIndex][card1.ColIndex] = ' ';
            ClosedField[card2.RowIndex][card2.ColIndex] = ' ';

            OpenedCards.push_back(card1);
            OpenedCards.push_back(card2);

            switch (WhichTurn)
            {
            case PLAYER1:
                Player1Points++;                                               //Проверка на нахождение пары
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
    } while (Player1Points + Player2Points != (Field.size() * Field.size()) / 2);
}

void MainGame(FieldSize FSize)
{
    _getch();

    system("cls");

    int rows, cols, MaxRandNum;
    if (SetFieldSize(rows, cols, MaxRandNum, FSize) == -1)
    {
        MainGame(ModeSelection());
    }
    else if (SetFieldSize(rows, cols, MaxRandNum, FSize) == 1)
    {
        return;
    }


    IntMatrix Field(rows, std::vector<int>(cols));
    std::vector<int> used_nums;                             //Генерация игрового поля
    GenerateField(Field, used_nums, rows, cols, MaxRandNum);

    CharMatrix ClosedField(rows, std::vector<char>(cols));
    int Player1Points = 0, Player2Points = 0;
    for (int i = 0; i != ClosedField.size(); i++)
    {
        for (int j = 0; j != ClosedField[i].size(); j++)        //Заполнение интерфейса поля и объявление переменных
        {
            ClosedField[i][j] = '#';
        }
    }

    int FlipsNumber = 0;
    auto timer_start = std::chrono::high_resolution_clock::now();

    Turns(Player1Points, Player2Points, ClosedField, FlipsNumber, Field);

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
}
