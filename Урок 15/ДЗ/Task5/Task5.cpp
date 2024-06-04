#include <iostream>
#include <string>

enum Action
{
	NUMBER_SEARCH = 1,
	NAME_SEARCH = 2,
	EDIT_CONTACTS = 3,
	EXIT = 4
};
std::string** create_arr(int rows, int cols)
{
	std::string** arr = new std::string * [rows];
	for (int i = 0; i != rows; i++)
	{
		arr[i] = new std::string[cols];
	}
	return arr;
}

void init_arr(std::string**& arr, int rows, int cols)
{
	for (int i = 0; i != cols; i++)
	{
		std::cout << "Введите имя: ";
		std::getline(std::cin, arr[0][i]);

		std::cout << "Введите номер: ";
		std::getline(std::cin, arr[1][i]);
	}
}

void arr_output(std::string** const& arr, int rows, int cols)
{
	int count = 1;
	std::cout << "Твоя телефонная книга:" << std::endl;
	for (int i = 0; i != cols; i++)
	{
		std::cout << count << ")" << arr[0][i]
			<< ": " << arr[1][i] << std::endl;
		count++;
	}
}

void arr_delete(std::string**& arr, int rows)
{
	for (int i = 0; i != rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void number_search(std::string** const& arr, int cols, std::string const& number)
{
	int count = 1;
	bool isCheck = false;
	std::cout << "\nАбоненты с таким номером:\n";
	for (int i = 0; i != cols; i++)
	{
		if (arr[1][i] == number)
		{
			std::cout << count << ") " << arr[0][i]
				<< ": " << arr[1][i] << std::endl;
			isCheck = true;
		}
		count++;
	}
	if (!isCheck)
	{
		std::cout << "По такому номеру ничего не найдено." << std::endl;
	}
	std::cout << std::endl;
}

void name_search(std::string** const& arr, int cols, std::string const& name)
{
	int count = 1;
	bool isCheck = false;
	std::cout << "Номера абонентов с таким именем:\n";
	for (int i = 0; i != cols; i++)
	{
		if (arr[0][i] == name)
		{
			std::cout << count << ") " << arr[0][i] << ": " << arr[1][i] << std::endl;
			isCheck = true;
		}
		count++;
	}
	if (!isCheck)
	{
		std::cout << "Нет абонента с таким именем." << std::endl;
	}
	std::cout << std::endl;
}

std::string** add_contact(std::string**& arr, int rows, int& cols)
{
	std::string new_name, new_number;
	std::cout << "\nВведите имя нового абонента: ";
	std::cin.ignore();
	std::getline(std::cin, new_name);
	std::cout << "Введите номер нового абонента: ";
	std::getline(std::cin, new_number);

	std::string** new_arr = create_arr(rows, cols + 1);
	for (int i = 0; i != rows; i++)
	{
		for (int j = 0; j != cols; j++)
		{
			new_arr[i][j] = arr[i][j];
		}
	}
	new_arr[0][cols] = new_name;
	new_arr[1][cols] = new_number;

	std::cout << "Телефонная книжка успешно обновлена!\n" << std::endl;

	arr_delete(arr, rows);
	cols++;

	return new_arr;
}

void edit_contact(std::string**& arr, int rows, int cols)
{
	int index;
	std::cout << "Какой контакт вы хотите изменить (Введите номер): ";
	std::cin >> index;
	if (index < 1 || index > cols)
	{
		std::cout << "Такого контакта не существует" << std::endl;
	}
	else
	{
		std::string edited_name, edited_number;
		std::cout << "\nВведите новое имя: ";
		std::cin.ignore();
		std::getline(std::cin, edited_name);
		std::cout << "Введите новый номер: ";
		std::getline(std::cin, edited_number);
		arr[0][index - 1] = edited_name;
		arr[1][index - 1] = edited_number;
		std::cout << "Изменения успешно применены!" << std::endl;
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	int rows = 2;
	int cols = 1;
	std::string** arr = create_arr(rows, cols);

	init_arr(arr, rows, cols);

	arr_output(arr, rows, cols);

	int val, val2;
	Action action;
	std::string number;
	std::string name;
	do
	{
		std::cout << "\n----Меню-----" << std::endl;
		std::cout << "1)Поиск по номеру\n2)Поиск по имени\n3)Добавить изменения\n4)Выйти"
			<< "\nДействие: ";
		std::cin >> val;
		action = static_cast<Action>(val);
		switch (action)
		{
		case NUMBER_SEARCH:
			std::cout << "Введите номер: ";
			std::cin.ignore();
			std::getline(std::cin, number);
			number_search(arr, cols, number);
			break;
		case NAME_SEARCH:
			std::cout << "Введите имя: ";
			std::cin.ignore();
			std::getline(std::cin, name);
			name_search(arr, cols, name);
			break;
			break;
		case EDIT_CONTACTS:
			std::cout << "1) Добавить контакт\n2) Изменить контакт\nДействие: ";
			std::cin >> val2;
			switch (val2)
			{
			case 1:
				arr = add_contact(arr, rows, cols);
				arr_output(arr, rows, cols);
				break;
			case 2:
				edit_contact(arr, rows, cols);
				arr_output(arr, rows, cols);
				break;
			default:
				std::cout << "Вы ввели что-то не так!" << std::endl;
				break;
			}
			break;
		case EXIT:
			std::cout << "Программа успешно завершена!" << std::endl;
			break;
		default:
			std::cout << "Вы ввели что то не так!" << std::endl;
			break;
		}
	} while (action != EXIT);
	arr_delete(arr, rows);
	return 0;
}
