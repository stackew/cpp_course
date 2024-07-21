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

enum UserChoice
{
    FIELD_SIZE = 1,
    EXIT
};

enum FieldSize
{
    TWO_BY_TWO = 1,
    FOUR_BY_FOUR,
    SIX_BY_SIX,
};

enum Turn
{
    PLAYER1 = 0,
    PLAYER2
};

using GameField = std::vector<std::vector<int>>;
using ClosedGameField = std::vector<std::vector<char>>;

struct GameSettings
{
    size_t rows;
    size_t cols;
    size_t max_rand_num;
};

static GameSettings two_by_two{ 2, 2, 4 };
static GameSettings four_by_four{ 4, 4, 9 };
static GameSettings six_by_six{ 6, 6, 20 };

static std::map<FieldSize, GameSettings> FieldSettings
{
    {TWO_BY_TWO, two_by_two},
    {FOUR_BY_FOUR, four_by_four},
    {SIX_BY_SIX,six_by_six}
};

struct GameStatistics
{
    size_t p1_points = 0;
    size_t p2_points = 0;
    std::chrono::duration<float> game_duration;
    size_t flips_count = 0;
};

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


bool IsMatch(Card& card1, Card& card2, GameField const& field);

bool IsAlreadyOpened(Card& card, std::vector<Card> const& opened_cards);

bool IsFree(GameField const& field, const int& row_pos,
    const int& col_pos);

void PrintMarking(const int& amount);

void PrintClosedField(ClosedGameField const& closed_field);

void PrintOpenedCards(const Card& card1, const Card& card2, GameField const& field,
    std::vector<Card> const& opened_cards);

GameSettings GetGameSettings(FieldSize const& field_size);

void AddPair(GameField& field, const int& el, const int& size);

void GenerateField(GameField& field, const GameSettings& settings);

bool IsCorrect(Card& card1, Card& card2, GameField const& field,
    std::vector<Card> const& OpenedCards);

void InitClosedField(ClosedGameField& closed_field);

FieldSize ModeSelection();

GameStatistics Turns(ClosedGameField& closed_field, GameField& field);

void OutputStatistics(const GameStatistics& statistics);

void PlayGame(FieldSize field_size);