#include <iostream>
#include <fstream>
#include <string>

using ifstream = std::ifstream;

int main()
{
	setlocale(LC_ALL, "ru");
	
	ifstream file1, file2;

	file1.open("file1.txt"); //Содержимое файлов вводил сам, можно посмотреть, открыв txt
	file2.open("file2.txt");

	if (!file1.is_open() || !file2.is_open())
	{
		std::cout << "Что-то пошло не так!" << std::endl;
	}
	else
	{
		std::string File1Str, File2Str;
		while (!file1.eof())
		{
			std::getline(file1, File1Str);
		}
		while (!file2.eof())
		{
			std::getline(file2, File2Str);
		}


		if (File1Str != File2Str)
		{
			std::cout << "Строка из 1 файла: " << File1Str << std::endl
				<< "Строка из 2 файла: " << File2Str << std::endl;
		}
		else
		{
			std::cout << "Строки совпадают" << std::endl;
		}
	}
	file1.close();
	file2.close();
	
	return 0;
}
