#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using fstream = std::fstream;

bool isvowel(const char& symbol)
{
	const char vowels[10] = { 'a', 'e', 'i', 'o', 'u',
							  'A','E','I','O','U' };

	if(std::find(std::begin(vowels), std::end(vowels), symbol)
		!= std::end(vowels))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");


	fstream file1;
	fstream file2;

	file1.open("file1.txt", fstream::in); //Содержимое файла вводил сам, можно посмотреть, открыв txt
	file2.open("file2.txt", fstream::in | fstream::out);

	if (!file1.is_open() || !file2.is_open())
	{
		std::cout << "Что-то пошло не так!";
	}
	else
	{
		int count_symbols = 0,
			count_strings = 1,
			count_vowels = 0,
			count_consonants = 0,
			count_nums = 0;

		char FileSymb;
		while (!file1.eof())
		{
			file1.get(FileSymb);
			count_symbols++;
			if (FileSymb == '\n')
			{
				count_strings++;
			}
			else if (isdigit(FileSymb))
			{
				count_nums++;
			}
			else if (isvowel(FileSymb) && !isdigit(FileSymb))
			{
				count_vowels++;
			}
			else
			{
				count_consonants++;
			}
		}
		file1.close();

		file2 <<
			"Количество символов: " << count_symbols
			<< "\nКоличество строк: " << count_strings
			<< "\nКоличество гласных букв: " << count_vowels
			<< "\nКоличество согласных букв: " << count_consonants
			<< "\nКоличество цифр: " << count_nums << std::endl;

		file2.seekg(0, std::ios::beg);

		std::string File2Out;
		while (!file2.eof())
		{
			File2Out = "";
			std::getline(file2, File2Out);
			std::cout << File2Out << std::endl;
		}
	}
	file2.close();

	return 0;
}