#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <stdlib.h> 
#include <conio.h> 

#define MAX_OPTION_VAL 9
#define MIN_OPTION_VAL 1

using string = std::string;

enum Options
{
	ADD_SONG_TO_CATALOG = 1,
	PRINT_CATALOG,
	PRINT_SONG_INFO,
	EDIT_SONG,
	CLEAR_SONG_TEXT,
	SAVE_SONG_TEXT,
	SEARCH_BY_AUTHOR,
	SEARCH_BY_WORD,
	EXIT
};

enum TextOpenType
{
	MANUALLY = 1,
	FROM_FILE,
	DONT_OPEN
};

struct Song
{
	string Name = "";
	string Author = "";
	int YearOfCreation;
	string Text = "";
};

void AddSongText(Song& song);

Song CreateSong();

void PrintSongInfo(const Song& song);

void EditSong(Song& song_to_edit);

void ClearSongText(Song& song);

void SaveSongText(const Song& song);

void SearchByAuthor(std::vector<Song> catalog, const string& author);

void SearchByWord(std::vector<Song> catalog, const string& word);

int ChooseOption();

int SongIndexInput(const int& catalog_size);

void SongCatalogApp();