#pragma once


#ifdef INTEGER
#define InputArr InputIntArr
#define OutputArr OutputIntArr
#define MinArrEl MinIntArrEl
#define MaxArrEl MaxIntArrEl
#define SortArr SortIntArr
#define EditArrEl EditIntArrEl

void InputIntArr(std::vector<int>& arr);

void OutputIntArr(std::vector<int> const& arr);

void MinIntArrEl(std::vector<int> const& arr);

void MaxIntArrEl(std::vector<int> const& arr);

void SortIntArr(std::vector<int>& arr);

void EditIntArrEl(std::vector<int>& arr);
#endif

#ifdef DOUBLE
#define InputArr InputDoubleArr
#define OutputArr OutputDoubleArr
#define MinArrEl MinDoubleArrEl
#define MaxArrEl MaxDoubleArrEl
#define SortArr SortDoubleArr
#define EditArrEl EditDoubleArrEl

void InputDoubleArr(std::vector<double>& arr);

void OutputDoubleArr(std::vector<double> const& arr);

void MinDoubleArrEl(std::vector<double> const& arr);

void MaxDoubleArrEl(std::vector<double> const& arr);

void SortDoubleArr(std::vector<double>& arr);

void EditDoubleArrEl(std::vector<double>& arr);
#endif

#ifdef CHAR
#define InputArr InputCharArr
#define OutputArr OutputCharArr
#define MinArrEl MinCharArrEl
#define MaxArrEl MaxCharArrEl
#define SortArr SortCharArr
#define EditArrEl EditCharArrEl


void InputCharArr(std::vector<char>& arr);

void OutputCharArr(std::vector<char> const& arr);

void MinCharArrEl(std::vector<char> const& arr);

void MaxCharArrEl(std::vector<char> const& arr);

void SortCharArr(std::vector<char>& arr);

void EditCharArrEl(std::vector<char>& arr);
#endif
