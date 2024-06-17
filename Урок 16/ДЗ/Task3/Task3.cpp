#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <Windows.h>

struct Book
{
	std::string Name;
	std::string Author;
	std::string Publisher;
	std::string Genre;
};

using vector = std::vector<Book>;

enum BookParameters
{
	NAME = 1,
	AUTHOR,
	PUBLISHER,
	GENRE
};	

void edit_book(vector& books, int index)
{
	int var;
	std::cout << "\n1)Название" << std::endl
		<< "2)Автор" << std::endl
		<< "3)Издательство" << std::endl
		<< "4)Жанр" << std::endl
		<< "Что вы хотите изменить: ";
	std::cin >> var;
	BookParameters parameter = static_cast<BookParameters> (var);
	switch (parameter)
	{
	case NAME:
		std::cout << "Введите новое название книги: ";
		std::cin >> books[index].Name;
		break;
	case AUTHOR:
		std::cout << "Введите автора книги: ";
		std::cin >> books[index].Author;
		break;
	case PUBLISHER:
		std::cout << "Введите издательство книги: ";
		std::cin >> books[index].Publisher;
		break;
	case GENRE:
		std::cout << "Введите новый жанр книги: ";
		std::cin >> books[index].Genre;
		break;
	default:
		std::cout << "Вы ввели что то не так!" << std::endl;
		break;
	}
}
void print_books(vector const& books)
{
	int count = 1;
	std::cout << "\n---Список книг---" << std::endl;
	for (const Book& book : books)
	{
		std::cout << count << ") "
			<< "Название: " << book.Name << std::endl
			<< "Автор: " << book.Author << std::endl
			<< "Издательство: " << book.Publisher << std::endl
			<< "Жанр: " << book.Genre << std::endl;
		count++;
	}
}

void search_by_author(vector const& books, std::string author)
{
	std::cout << "\nКниги, имеющие такого автора: " << std::endl;
	for (const Book& book : books)
	{
		if (book.Author == author)
		{
			std::cout <<"Название: " << book.Name << std::endl
				<< "Автор: " << book.Author << std::endl
				<< "Издательство: " << book.Publisher << std::endl
				<< "Жанр: " << book.Genre << "\n" << std::endl;
		}
	}
}
void search_by_name(vector const& books, std::string name)
{
	std::cout << "Книги, имеющие такоe имя: " << std::endl;
	for (const Book& book : books)
	{
		if (book.Name == name)
		{
			std::cout << "Название: " << book.Name << std::endl
				<< "Автор: " << book.Author << std::endl
				<< "Издательство: " << book.Publisher << std::endl
				<< "Жанр: " << book.Genre << "\n" << std::endl;
		}
	}
}

bool NamePredicate(Book const& rbook, Book const& lbook)
{
	return rbook.Name < lbook.Name;
}

bool AuthorPredicate(Book const& rbook, Book const& lbook)
{
	return rbook.Author < lbook.Author;
}

bool PublisherPredicate(Book const& rbook, Book const& lbook)
{
	return rbook.Publisher< lbook.Publisher;
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector books(10);
	books[0] = { "Маленький принц", "Экзюпери", "Эксмо", "Сказка" };
	books[1] = { "Ревизор", "Гоголь", "ACT", "Комедия" };
	books[2] = { "Продавец воздуха", "Беляев", "Эксмо", "Фантастика" };
	books[3] = { "Анна Каренина", "Толстой", "ACT", "Мелодрама" };
	books[4] = { "Горе от ума", "Грибоедов", "ACT", "Комедия" };
	books[5] = { "Дубровский", "Пушкин", "ACT", "Мелодрама" };
	books[6] = { "Птицы", "Торин", "МИФ", "Детектив" };
	books[7] = { "Стальной алхимик", "Аракава", "Азбука", "Фантастика" };
	books[8] = { "Пески времени", "Шелдон", "ACT", "Детектив" };
	books[9] = { "Недоросль", "Фонвизин", "Эксмо", "Комедия" };

	print_books(books);

	edit_book(books, 0);
	print_books(books);

	search_by_author(books, "Пушкин");

	search_by_name(books, "Стальной алхимик");

	std::sort(books.begin(), books.end(), NamePredicate);
	print_books(books);

	std::sort(books.begin(), books.end(), AuthorPredicate);
	print_books(books);

	std::sort(books.begin(), books.end(), PublisherPredicate);
	print_books(books);
	return 0;
}
