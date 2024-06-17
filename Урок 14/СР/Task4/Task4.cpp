#include <iostream>
#include <string>

void Palindrome_check(std::string const& string)
{
	bool isPalindrome = true;
	for (size_t i = 0; i != string.size() / 2; i++)
	{
		if (string[i] != string[string.size() - i - 1])
		{
			isPalindrome = false;
			break;
		}
	}
	if (isPalindrome)
	{
		std::cout << "Строка является палиндромом" << std::endl;
	}
	else
	{
		std::cout << "Строка не является палиндромом" << std::endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	std::string string1 = "fef";
	std::string string2 = "eff";

	Palindrome_check(string1);
	Palindrome_check(string2);

	return 0;
}
