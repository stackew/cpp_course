#pragma once
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
    SIX_BY_SIX
};

enum Turn
{
    PLAYER1 = 0,
    PLAYER2
};

using vector2dint = std::vector<std::vector<int>>;
using vector2dchar = std::vector<std::vector<char>>;

struct Card
{
    int RowIndex;
    int ColIndex;
};
