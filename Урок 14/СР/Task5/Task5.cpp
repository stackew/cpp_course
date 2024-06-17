#include <iostream>
#include "StrFuncsLibrary.h"

int main()
{
	setlocale(LC_ALL, "RU");

	char str1[] = "String1 and 2";
	int len1 = mystrlen(str1);
	std::cout << "Длина первой строки: " << len1 << std::endl;

	char strcopy[100];
	mystrcpy(strcopy, str1);
	std::cout << "Копированная строка: " << strcopy << std::endl;

	char strcat[100] = "Strggg";
	mystrcat(strcat, str1);
	std::cout << strcat << std::endl;

	char* FoundChar = mystrchr(str1, 'a');
	if (FoundChar)
	{
		std::cout << "Элемент найден: " << FoundChar << std::endl;
	}
	else
	{
		std::cout << "Элемент не найден" << std::endl;
	}

	char string_to_find[4] = "and";
	char* FoundString = mystrstr(str1, string_to_find);
	if (FoundString)
	{
		std::cout << "Элемент найден: " << FoundString << std::endl;
	}
	else
	{
		std::cout << "Элемент не найден" << std::endl;
	}
	return 0;
}
