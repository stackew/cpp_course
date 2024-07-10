#pragma once

#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <conio.h> 
#include <map>
#include <Windows.h>
#include <mmsystem.h>
#include <chrono>

#pragma comment(lib, "winmm.lib")

enum FieldSize
{
    TWO_BY_TWO = 1,
    FOUR_BY_FOUR,
    SIX_BY_SIX,

    EXIT
};

enum Turn
{
    PLAYER1 = 0,
    PLAYER2
};

using IntMatrix = std::vector<std::vector<int>>;
using CharMatrix= std::vector<std::vector<char>>;

struct Card
{
    int RowIndex;
    int ColIndex;
};

static std::map <int, char> ConvertToSymbols
{
    {1, '¶'}, {2, '§'}, {3, '¤'},
    {4, '*'}, {5, 'x'}, {6, '&'},
    {7, '%'}, {8, '@'}, {9, '!'},
    {10, '$'}, {11, '^'}, {12, '~'},
    {13, '+'}, {14, '-'}, {15, '='},
    {16, 'ý'}, {17, 'ò'}, {18, '_'},
    {19, '?'}
};


bool IsMatch(Card& card1, Card& card2, IntMatrix const& Field);

bool IsAlreadyOpened(Card& card, std::vector<Card> const& OpenedCards);

bool IsFree(IntMatrix const& Field, const int& row_pos,
    const int& col_pos);

void PrintMarking(const int& amount);

void PrintClosedField(CharMatrix const& ClosedField);

void PrintOpenedCards(const Card& card1, const Card& card2, IntMatrix const& Field,
    std::vector<Card> const& OpenedCards);

int SetFieldSize(int& rows, int& cols, int& MaxRandNum, FieldSize const& FSize);

void AddPair(IntMatrix& Field, const int& el, const int& size);

void GenerateField(IntMatrix& Field, std::vector<int>& used_nums,
    const int& rows, const int& cols, const int& MaxRandNum);

bool IsCorrect(Card& card1, Card& card2, const int& rows, const int& cols,
    std::vector<Card> const& OpenedCards);

FieldSize ModeSelection();

void Turns(int& Player1Points, int& Player2Points, CharMatrix& ClosedField,
    int& FlipsNumber, const IntMatrix& Field);

void MainGame(FieldSize FSize);