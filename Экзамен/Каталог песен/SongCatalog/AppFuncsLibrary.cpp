#include <iostream>

#include "AppFuncsLibrary.h"

void AddSongText(Song& song)
{
	if (song.Text != "")
	{
		std::cout << "� ���� ����� ��� ���� �����!" << std::endl;
	}
	else
	{
		string text, str;
		int open_type_val;
		TextOpenType type;

		string file_name;
		std::ifstream file;
		do
		{
			std::cout << "1)������ � ����������" << std::endl
				<< "2)��������� �� �����" << std::endl
				<< "3)�� ��������� �����" << std::endl
				<< "��� �� ������ �������� �����: ";
			std::cin >> open_type_val;
			type = static_cast<TextOpenType>(open_type_val);
			switch (type)
			{
			case MANUALLY:
				std::cin.ignore();
				std::cout << "������� ����� �����: ";
				std::getline(std::cin, text);
				break;

			case FROM_FILE:
				std::cout << "������� �������� ����� ������ � ����������� (��������.����������): ";
				std::cin >> file_name;

				file.open(file_name);
				if (!file.is_open())
				{
					std::cout << "�� ���������� ������� ������ �� �����!" << std::endl;
				}
				else
				{
					std::cout << "����� ������� ��������!" << std::endl;
					
					while (!file.eof())
					{	
						str = "";
						getline(file, str);
						text += str;
					}
					file.close();
				}
				break;
			case DONT_OPEN:
				std::cout << "����� �� ����� �������� ��� �������." << std::endl;
				break;
			default:
				std::cout << "�� ����� ���-�� �� ���!" << std::endl;
				break;
			}
		} while (type != MANUALLY && type != FROM_FILE && type != DONT_OPEN);
		song.Text = text;
	}
}

Song CreateSong()
{
	Song song;
	std::cin.ignore();
	std::cout << "������� �������� �����: ";
	std::getline(std::cin, song.Name);
	std::cout << "������� ������ �����: ";
	std::getline(std::cin, song.Author);
	std::cout << "������� ��� �������� �����: ";
	std::cin >> song.YearOfCreation;
	AddSongText(song);

	return song;
}

void PrintSongInfo(const Song& song)
{
	std::cout << "   ��������: " << song.Name << std::endl
		<< "   �����: " << song.Author << std::endl
		<< "   ��� ��������: " << song.YearOfCreation << std::endl
		<< "   �����: " << song.Text << std::endl;
}

void PrintCatalog(std::vector<Song> const& catalog)
{
	int count = 1;
	for (const Song& song : catalog)
	{
		std::cout << count++ << ") ";
		PrintSongInfo(song);
	}
}

void EditSong(Song& song_to_edit)
{
	song_to_edit = CreateSong();
}

void ClearSongText(Song& song)
{
	song.Text = "";
	std::cout << "����� ������� ������!" << std::endl;
}

void SaveSongText(const Song& song)
{
	if (song.Text == "")
	{
		std::cout << "� ������ ����� �� ���������� ������." << std::endl;
	}
	else
	{
		std::ofstream file;
		string file_name;
		std::cout << "������� ��� �����, � ������� ������ ��������� ����� (������: file_name.txt): ";
		std::cin >> file_name;
		file.open(file_name);
		if (!file.is_open())
		{
			std::cout << "�� ������� ������� ����." << std::endl;
		}
		else
		{
			file << song.Text;
			std::cout << "����� ������� ��������!" << std::endl;
		}
	}
}

void SearchByAuthor(std::vector<Song> catalog, const string& author)
{
	std::cout << "����� � ����� �������: " << std::endl;
	for (const Song& song : catalog)
	{
		if (song.Author == author)
		{
			std::cout << "-" << song.Name << std::endl;
		}
	}
}

void SearchByWord(std::vector<Song> catalog, const string& word)
{
	std::cout << "����� � ����� ������ � ������: " << std::endl;
	for (const Song& song : catalog)
	{
		const size_t found = song.Text.find(word);
		if (found != string::npos)
		{
			std::cout << "-" << song.Name << std::endl;
		}
	}
}

int ChooseOption()
{
	int option_val;
	std::cout << "\n---������� �����---" << std::endl;
	std::cout << "1)�������� ����� � �������" << std::endl
		<< "2)���������� ���������� ��������" << std::endl
		<< "3)���������� ���������� � �����" << std::endl
		<< "4)�������� ������ �����" << std::endl
		<< "5)�������� ����� �����" << std::endl
		<< "6)��������� ����� ����� � ����" << std::endl
		<< "7)����� �� ������" << std::endl
		<< "8)����� �� ����� � ������" << std::endl
		<< "9)����� �� ���������" << std::endl;
	std::cout << "��� �� ������ �������: ";
	std::cin >> option_val;

	while (option_val > MAX_OPTION_VAL || option_val < MIN_OPTION_VAL) //�������� ����������� ��� MAX_OPTION_VAL � MIN
	{
		std::cout << "�� ����� ���- �� �� ���!" << std::endl;
		std::cout << "��� �� ������ �������: ";
		std::cin >> option_val;
	}
	system("cls");
	return option_val;
}

int SongIndexInput(const int& catalog_size)
{
	int song_index;
	std::cout << "������� ����� �����: ";
	std::cin >> song_index;
	if (song_index - 1 >= catalog_size || song_index < MIN_OPTION_VAL)
	{
		std::cout << "����� ����� �� ����������!" << std::endl;
		return -1;
	}
	return song_index - 1;
}

void SongCatalogApp()
{
	std::vector<Song> catalog;

	int catalog_size = 0;
	int song_index;
	string us_author, us_word;
	Options option;
	do
	{
		option = static_cast<Options>(ChooseOption());
		switch (option)
		{
		case ADD_SONG_TO_CATALOG:
			catalog.push_back(CreateSong());
			catalog_size = catalog.size();
			break;
		case PRINT_CATALOG:
			PrintCatalog(catalog);
			break;
		case PRINT_SONG_INFO:
			song_index = SongIndexInput(catalog_size);
			if (song_index != -1) PrintSongInfo(catalog[song_index]);
			break;
		case EDIT_SONG:
			song_index = SongIndexInput(catalog_size);
			if (song_index != -1) EditSong(catalog[song_index]);
			break;
		case CLEAR_SONG_TEXT:
			song_index = SongIndexInput(catalog_size);
			if (song_index != -1) ClearSongText(catalog[song_index]);
			break;
		case SAVE_SONG_TEXT:
			song_index = SongIndexInput(catalog_size);
			if (song_index != -1) SaveSongText(catalog[song_index]);
			break;
		case SEARCH_BY_AUTHOR:
			std::cout << "������� ������, ����� �������� ������ �����: ";
			std::cin >> us_author;
			SearchByAuthor(catalog, us_author);
			break;
		case SEARCH_BY_WORD:
			std::cout << "������� �����, ������� ������ �����: ";
			std::cin >> us_word;
			SearchByWord(catalog, us_word);
			break;
		case EXIT:
			std::cout << "��������� ������� ���������!" << std::endl;
			break;
		default:
			std::cout << "�� ����� ���-�� �� ���!" << std::endl;
			break;
		}
	} while (option != EXIT);
}
