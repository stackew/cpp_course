#include <iostream>
#include <string>
#include <algorithm>

bool NumPredicate(char el)
{
	return isdigit(el);
}

bool LetterPredicate(char el)
{
	return isalpha(el);
}

bool SymbPredicate(char el)
{
	if (!isdigit(el) && !isalpha(el))
	{
		return true;
	}
	return false;
}
int main()
{
	setlocale(LC_ALL, "rus");

	std::string string = "Ab12cd9 -*daE2";

	std::cout << "Количество цифр в строке: "
	<< std::count_if(string.begin(), string.end(), NumPredicate)
	<< std::endl;

	std::cout << "Количество букв в строке: "
		<< std::count_if(string.begin(), string.end(), LetterPredicate)
		<< std::endl;

	std::cout << "Количество символов в строке: "
		<< std::count_if(string.begin(), string.end(), SymbPredicate)
		<< std::endl;
	return 0;
}