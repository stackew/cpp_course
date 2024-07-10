#include <iostream>
#include <string>
#include <vector>
#include <fstream>

enum TextOpenType
{
	MANUALLY = 1,
	FROM_FILE
};

using string = std::string;

struct Song
{
	string Name;
	string Author;
	int YearOfCreation;
	string Text;
};

void AddToCatalog(std::vector<Song>& Catalog)
{
	Song song;
	std::cout << "Введите название песни: ";
	std::getline(std::cin, song.Name);
	std::cout << "Введите автора песни: ";
	std::getline(std::cin, song.Author);
	std::cout<< "Введите год создания песни: ";
	std::cin >> song.YearOfCreation;

	Catalog.push_back(song);
}

void AddSongText(Song& song)
{
	string Text;
	int OpenTypeVal;
	TextOpenType Type;

	string FileName;
	std::fstream File;
	do
	{
		std::cout << "1)Ввести с клавиатуры" << std::endl
			<< "2)Загрузить из файла" << std::endl
			<< "Как вы хотите добавить текст: ";
		std::cin >> OpenTypeVal;
		Type = static_cast<TextOpenType>(OpenTypeVal);
		switch (Type)
		{
		case MANUALLY:
			std::cin.ignore();
			std::cout << "Введите текст песни: ";
			std::getline(std::cin, Text);
			break;
			
		case FROM_FILE:
			std::cout << "Введите название файла вместе с расширением (Название.расширение): ";
			std::cin >> FileName;

			File.open(FileName, std::fstream::in);
			if (!File.is_open())
			{
				std::cout << "Не получилось считать данные из файла!" << std::endl;
			}
			else
			{
				std::cout << "Файл открыт!";
				while (!File.eof())
				{
					Text = "";
					File >> Text;
					std::cout << Text << " ";
				}
				File.close();
			}
			break;

		default:
			std::cout << "Вы ввели что-то не так!" << std::endl;
			break;
		}
	} while (Type != MANUALLY && Type != FROM_FILE);
	song.Text = Text;
}

void ClearSongText(Song& song)
{
	string FileName;
	std::fstream File;
	std::cout << "Введите название файла вместе с расширением (Название.расширение): ";
	std::cin >> FileName;
	File.open(FileName);
	if (!File.is_open())
	{
		std::cout << "Такого файла не существует!" << std::endl;
	}
	else
	{
		File << "";
	}
	song.Text = ;
}


int main()
{
	setlocale(LC_ALL, "ru");

	std::vector<Song> Catalog;
	AddToCatalog(Catalog);

	AddSongText(Catalog[0]);

	std::cout << Catalog[0].Text;
	return 0;

}