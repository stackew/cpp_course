#include <iostream>
#include <string>
#include <vector>
#include <variant>
#include <Windows.h>

enum Type_of_CarNum
{
	INT_NUMBER = 1,
	STRING_NUMBER
};

struct Car
{
	std::string colour;
	std::string model;
	std::variant<std::string, int> car_number;
};

void fill_car_number(Car& car)
{
	int val, int_car_number;
	std::string str_car_number;
	bool isCheck;
	do
	{
		isCheck = true;
		std::cout << "Номерной знак" << std::endl
			<< "1)Пятизначный числовой номер" << std::endl
			<< "2)Номер словом (до 8-ми символов)" << std::endl
			<< "Выберите номер: ";
		std::cin >> val;
		Type_of_CarNum type = static_cast<Type_of_CarNum>(val);
		std::cout << "Введите номер: ";
		switch (type)
		{
		case INT_NUMBER:
			std::cin >> int_car_number;
			car.car_number = int_car_number;
			break;
		case STRING_NUMBER:
			std::cin >> str_car_number;
			car.car_number = str_car_number;
			break;
		default:
			isCheck = false;
			std::cout << "Вы ввели что то не так!\n";
			break;
		}
	} while (!isCheck);
}

void fill_data(Car &car)
{
	std::cout << "\n---Создание машины---" << std::endl;
	std::cout << "Введите цвет машины: ";
	std::cin >> car.colour;
	std::cout << "Введите модель машины: ";
	std::cin >> car.model;
	fill_car_number(car);
}

void print_car(Car const& car)
{
	std::cout << "\nЦвет машины: " << car.colour << std::endl
		<< "Модель машины: " << car.model << std::endl;
	std::cout << "Номер машины: ";
	if (holds_alternative<int>(car.car_number))
	{
		std::cout << get<int>(car.car_number);
	}
	else if (holds_alternative<std::string>(car.car_number))
	{
		std::cout << get<std::string>(car.car_number);
	}
}

void edit_car(Car& car)
{
	std::cout << "\n---Редакторование машины---" << std::endl
		<< "Введите цвет: ";
	std::cin >> car.colour;
	std::cout << "Введите модель: ";
	std::cin >> car.model;
	fill_car_number(car);
}

void print_cars(std::vector<Car> const& cars)
{
	int count = 1;
	std::cout << "\n\n---Машины---";
	for (const Car& car : cars)
	{
		std::cout << std::endl << "Машина " << count;
		print_car(car);
		count++;
	}
}

void search_by_number(std::vector<Car> const& cars)
{
	bool isCheck;
	int val, int_car_number;
	std::string str_car_number;
	do
	{
		isCheck = true;
		std::cout << "---Поиск машины---" << std::endl
			<< "1)По числовому номеру" << std::endl
			<< "2)По слову" << std::endl
			<< "Какой поиск вы хотите выполнить: ";
		std::cin >> val;
		Type_of_CarNum type = static_cast<Type_of_CarNum>(val);
		std::cout << "Введите номер: ";
		switch (type)
		{
		case INT_NUMBER:
			std::cin >> int_car_number;
			std::cout << "Машины с таким номером: ";
			for (const Car& car : cars)
			{
				auto pIcar_number = std::get_if<int>(&car.car_number);
				if (pIcar_number != nullptr && *pIcar_number == int_car_number)
				{
					print_car(car);
				}
			}
			break;
		case STRING_NUMBER:
			std::cin >> str_car_number;
			std::cout << "\nМашины с таким номером: ";
			for (const Car& car : cars)
			{
				auto pScar_number = std::get_if<std::string>(&car.car_number);
				if (pScar_number != nullptr && *pScar_number == str_car_number)
				{
					print_car(car);
				}
			}
			break;
		default:
			isCheck = false;
			std::cout << "Вы ввели что то не так!\n";
			break;
		}
	} while (!isCheck);

}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	Car test_car;
	fill_data(test_car);
	print_car(test_car);

	std::vector<Car> cars(10);
	cars[0] = { "Colour1", "Model1", 11111 };
	cars[1] = { "Colour2", "Model2", 22222 };
	cars[2] = { "Colour3", "Model3", "Num3"};
	cars[3] = { "Colour4", "Model4", "Num4"};
	cars[4] = { "Colour5", "Model5", 55555 };
	cars[5] = { "Colour6", "Model6", "Num6"};
	cars[6] = { "Colour7", "Model7", 77777 };
	cars[7] = { "Colour8", "Model8", 88888 };
	cars[8] = { "Colour9", "Model9", 99999 };
	cars[9] = { "Colour10", "Model10", "Num10"};

	print_cars(cars);

	edit_car(cars[4]);

	print_cars(cars);

	search_by_number(cars);

	return 0;
}