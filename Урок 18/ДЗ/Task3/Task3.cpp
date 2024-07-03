#include <iostream>
#include <fstream>
#include <string>

using fstream = std::fstream;

std::string EncryptFileToCaesar(std::string & text, int shift_count)
{
	for (int i = 0; i <= text.size(); i++)
	{
		char symbol = text[i];
		if (symbol >= 'a' && symbol <= 'z') 
		{
			symbol = symbol + shift_count;

			if (symbol > 'z') 
			{
				symbol = symbol - 'z' + 'a' - 1;
			}

			text[i] = symbol;
		}
		else if (symbol >= 'A' && symbol <= 'Z')
		{
			symbol = symbol + shift_count;

			if (symbol > 'Z')
			{
				symbol = symbol - 'Z' + 'A' - 1;
			}

			text[i] = symbol;
		}
	}

	return text;
}

int main()
{
	setlocale(LC_ALL, "ru");

	fstream original_file, encrypted_file;

	original_file.open("original.txt", fstream::in | fstream::out);
	encrypted_file.open("encrypted.txt", fstream::in | fstream::out);

	if (!original_file.is_open() || !encrypted_file.is_open())
	{
		std::cout << "Что-то пошло не так!" << std::endl;
	}
	else
	{
		original_file << "This just a text, nothing more.";

		original_file.seekg(0, std::ios::beg);
		std::cout << "Оригинальный текст: ";
		std::string original_file_out;
		while (!original_file.eof())
		{
			original_file_out = "";
			std::getline(original_file, original_file_out);
			std::cout << original_file_out;
		}
		original_file.close();

		encrypted_file << EncryptFileToCaesar(original_file_out, 3);

		encrypted_file.seekg(0, std::ios::beg);
		std::cout << "\nЗашифрованный текст: ";
		std::string encrypted_file_out;
		while (!encrypted_file.eof())
		{
			encrypted_file_out = "";
			std::getline(encrypted_file, encrypted_file_out);
			std::cout << encrypted_file_out;
		}
	}
	encrypted_file.close();

	return 0;
}
