#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

//НЕ ДОДЕЛАЛ

struct Book
{
	std::string Name;
	std::string Author;
	std::string Publisher;
	std::string Genre;
};

using vector = std::vector<Book>;

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

int main()
{
	setlocale(LC_ALL, "rus");
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
	return 0;
}
