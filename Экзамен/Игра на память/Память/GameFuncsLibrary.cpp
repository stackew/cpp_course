#include <iostream>
#include "Important.h"

void Init_Map(std::map <int, char>& ConvertToSymbols)
{
    ConvertToSymbols.emplace(1, '¶');
    ConvertToSymbols.emplace(2, '§');
    ConvertToSymbols.emplace(3, '¤');
    ConvertToSymbols.emplace(4, '*');
    ConvertToSymbols.emplace(5, 'x');
    ConvertToSymbols.emplace(6, '&');
    ConvertToSymbols.emplace(7, '%');
    ConvertToSymbols.emplace(8, '@');
    ConvertToSymbols.emplace(9, '!');
    ConvertToSymbols.emplace(10, '$');
    ConvertToSymbols.emplace(11, '^');
    ConvertToSymbols.emplace(12, '~');
    ConvertToSymbols.emplace(13, '+');
    ConvertToSymbols.emplace(14, '-');
    ConvertToSymbols.emplace(15, '=');
    ConvertToSymbols.emplace(16, 'э');
    ConvertToSymbols.emplace(17, 'т');
    ConvertToSymbols.emplace(18, '_');
    ConvertToSymbols.emplace(19, '?');
}

bool isMatch(Card& card1, Card& card2, vector2dint const& Field)
{
    return Field[card1.RowIndex][card1.ColIndex] == Field[card2.RowIndex][card2.ColIndex]; //Проверка совпали ли карты
}

bool isAlreadyOpened(Card& card, std::vector<Card> const& OpenedCards)
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

bool isFree(vector2dint const& Field, const int& row_pos,
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

void PrintClosedField(vector2dchar const& ClosedField)
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

void PrintOpenedCards(const Card& card1, const Card& card2, vector2dint const& Field,
    std::vector<Card> const& OpenedCards, std::map <int, char> ConvertToSymbols)
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
            else if (isAlreadyOpened(card, OpenedCards))
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
    default:
        std::cout << "Вы ввели что-то неправильно";
        return -1;
        break;
    }
    return 0;
}

void AddPair(vector2dint& Field, const int& el, const int& size)
{
    bool isCheck = false;
    int rand_row = rand() % size;
    int rand_col = rand() % size;

    while (!isCheck)
    {
        if (isFree(Field, rand_row, rand_col))
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

void GenerateField(vector2dint& Field, std::vector<int>& used_nums,
    const int& rows, const int& cols, const int& MaxRandNum)
{
    for (int i = 0; i != rows; i++)
    {
        for (int j = 0; j != cols; j++)
        {
            if (isFree(Field, i, j))
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