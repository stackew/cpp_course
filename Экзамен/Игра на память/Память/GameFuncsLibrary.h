#pragma once

void Init_Map(std::map <int, char>& ConvertToSymbols);

bool isMatch(Card& card1, Card& card2, vector2dint const& Field);

bool isAlreadyOpened(Card& card, std::vector<Card> const& OpenedCards);

bool isFree(vector2dint const& Field, const int& row_pos,
    const int& col_pos);

void PrintMarking(const int& amount);

void PrintClosedField(vector2dchar const& ClosedField);

void PrintOpenedCards(const Card& card1, const Card& card2, vector2dint const& Field,
    std::vector<Card> const& OpenedCards, std::map <int, char> ConvertToSymbols);

int SetFieldSize(int& rows, int& cols, int& MaxRandNum, FieldSize const& FSize);

void AddPair(vector2dint& Field, const int& el, const int& size);

void GenerateField(vector2dint& Field, std::vector<int>& used_nums,
    const int& rows, const int& cols, const int& MaxRandNum);