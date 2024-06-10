#include <iostream>
#include <vector>
#include <string>
using string_vector = std::vector<std::string>;

void fill_lastNames(string_vector &last_names)
{
	for (int i = 0; i != last_names.size(); i++)
	{
		std::cout << "Введите фамилию: ";
		std::getline(std::cin, last_names[i]);
	}
}

void sort_lastNames(string_vector &last_names)
{
	char letter1, letter2;
	for (int i = 0; i != last_names.size(); i++)
	{
		for (int j = 0; j != last_names.size() - 1; j++)
		{
			for (int k = 0; k != last_names[j].size(); k++)
			{
				letter1 = last_names[j][k];
				letter2 = last_names[j + 1][k];
				if (int(letter1) > int(letter2))
				{
					std::swap(last_names[j], last_names[j + 1]);
					break;
				}
				else if (int(letter1) < int(letter2))
				{
					break;
				}
			}
		}
	}

}

void vector_cout(string_vector const& last_names)
{
	for (int i = 0; i != last_names.size(); i++)
	{
		std::cout << last_names[i] << std::endl;
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	string_vector last_names(5);
	fill_lastNames(last_names);
	sort_lastNames(last_names);
	vector_cout(last_names);
	return 0;
}