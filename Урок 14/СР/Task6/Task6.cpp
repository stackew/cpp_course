#include <iostream>
#include <string>
#include <algorithm>

int CountWordOccurrences(std::string const& text, std::string const& word)
{
	int count = 0;
	for (size_t i = 0; i <= text.size() - word.size();)
	{
		int pos = text.find(word, i);
		if (pos == std::string::npos)
		{
			break;
		}
		count++;
		i = pos + 1;
	}
	return count;
}

int CountSentences(std::string const& text)
{
	int count = 0;
	for (const char& letter : text)
	{
		if (letter == '.' || letter == '!' || letter == '?')
		{
			count++;
		}
	}
	return count;
}

void CountPAndC(std::string const& text, int& Pcount, int& Ccount)
{
	for (const char& letter : text)
	{
		if (letter == '.')
		{
			Pcount++;
		}
		else if (letter == ',')
		{
			Ccount++;
		}
	}
}

void ReverseSentences(std::string text)
{
	int i = 0, j = 0;
	int n = text.size();
	while (j < n) {
		if (text[j] == ' ')
		{  
			std::reverse(text.begin() + i, text.begin() + j);
			j++;
			i = j;
		}
		else {
			j++;
		}
	}
	if (i < j) {
		std::reverse(text.begin() + i, text.begin() + j);
	}
	std::cout << "Текст с перевернутыми предложениями: " << text << std::endl;
}
int main()
{
	setlocale(LC_ALL, "rus");
	std::string text = "This just a text. Really!";

	std::string word;
	std::cout << "Введите слово, которое хотите найти: ";
	std::cin >> word;
	int count = CountWordOccurrences(text, word);
	if (count > 0)
	{
		std::cout << "Слово встречается: " << count << " раз" << std::endl;
	}
	else
	{
		std::cout << "Слово не найдено" << std::endl;
	}

	int countsents = CountSentences(text);
	std::cout << "В тексте " << countsents << " предложений" << std::endl;

	int Pcount = 0;
	int Ccount = 0;
	CountPAndC(text, Pcount, Ccount);
	std::cout << "Количество точек в тексте: " << Pcount << std::endl;
	std::cout << "Количество запятых в тексте: " << Ccount << std::endl;

	ReverseSentences(text);

	std::cout << "Перевернутая строка: ";
	std::reverse(text.begin(), text.end());
	std::cout << text;

	return 0;
}
