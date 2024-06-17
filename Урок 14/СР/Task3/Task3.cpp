#include <iostream>
#include <string>

void CountWords(std::string const& string)
{
	int count = 0;
	bool isInWord = false;

	for (const char& el : string)
	{
		if (isspace(el))
		{
			isInWord = false;
		}
		else if (!isInWord)
		{
			isInWord = true;
			count++;
		}
	}

	std::cout << "Количество слов в строке: " << count;
}

int main()
{
	setlocale(LC_ALL, "rus");

	std::string string = "Пацфуа афцфьао фцуаур фывоо в офво.";

	CountWords(string);
	return 0;
}
