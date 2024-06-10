#include <iostream>
#include <string>

enum Values
{
	RIDE_HEIGHT = 1,
	ENGINE_CAPACITY,
	ENGINE_POWER,
	WHEEL_DIAMETER,
	COLOUR,
	GEARBOX_TYPE
};

enum Actions
{
	SET_VALUES = 1,
	SHOW_VALUES,
	SEARCH_FOR_VALUE,
	EXIT
};

struct car
{
	float ride_height = NULL;
	float engine_capacity = NULL;
	float engine_power = NULL;
	float wheel_diameter = NULL;
	std::string colour;
	std::string gearbox_type;
};

void set_values(car &car)
{
	std::cout << "\n---Создание машины---" << std::endl;
	
	std::cout << "Введите высоту посадки: ";
	std::cin >> car.ride_height;

	std::cout << "Введите объем двигателя: ";
	std::cin >> car.engine_capacity;

	std::cout << "Введите мощность двигателя: ";
	std::cin >> car.engine_power;

	std::cout << "Введите диаметр колес: ";
	std::cin >> car.wheel_diameter;

	std::cin.ignore();
	std::cout << "Введите цвет машины: ";
	std::getline(std::cin, car.colour);

	std::cout << "Введите тип коробки передач: ";
	std::getline(std::cin, car.gearbox_type);
}

void show_values(car const& car)
{
	std::cout << "\n---Параметры машины---" << std::endl;
	std::cout << "Высота посадки: " << car.ride_height << std::endl;
	std::cout << "Объем двигателя: " << car.engine_capacity << std::endl;
	std::cout << "Мощность двигателя: " << car.engine_power << std::endl;
	std::cout << "Диаметр колес: " << car.wheel_diameter << std::endl;
	std::cout << "Цвет: " << car.colour << std::endl;
	std::cout << "Тип коробки передач: " << car.gearbox_type << std::endl;
}

void search_for_values(car const& car, Values value)
{
	switch (value)
	{
	case RIDE_HEIGHT:
		std::cout << "Высота посадки: " << car.ride_height << std::endl;
		break;
	case ENGINE_CAPACITY:
		std::cout << "Объем двигателя: " << car.engine_capacity << std::endl;
		break;
	case ENGINE_POWER:
		std::cout << "Мощность двигателя: " << car.engine_power << std::endl;
		break;
	case WHEEL_DIAMETER:
		std::cout << "Диаметр колес: " << car.wheel_diameter << std::endl;
		break;
	case COLOUR:
		std::cout << "Цвет: " << car.colour << std::endl;
		break;
	case GEARBOX_TYPE:
		std::cout << "Тип коробки передач: " << car.gearbox_type << std::endl;
		break;
	default:
		std::cout << "Вы ввели что-то не так!" << std::endl;
		break;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	car car;
	int val1, val2;
	Actions action;
	Values value;

	do
	{
		std::cout << "\n---Опции---" << std::endl;
		std::cout << "1)Задать значения" << std::endl
			<< "2)Посмотреть значения" << std::endl
			<< "3)Найти значение" << std::endl
			<< "4)Выйти" << std::endl;
		std::cout << "Выберите действие: ";
		std::cin >> val1;
		action = static_cast<Actions>(val1);
		
		switch (action)
		{
		case SET_VALUES:
			set_values(car);
			break;
		case SHOW_VALUES:
			show_values(car);
			break;
		case SEARCH_FOR_VALUE:
			std::cout << "\nКакой параметр вы хотите найти?" << std::endl
				<< "1)Высота посадки" << std::endl
				<< "2)Объем двигателя" << std::endl
				<< "3)Мощность двигателя" << std::endl
				<< "4)Диаметр колес" << std::endl
				<< "5)Цвет" << std::endl
				<< "6)Тип коробки передач" << std::endl;
			std::cout << "Введите: ";
			std::cin >> val2;
			value = static_cast<Values>(val2);
			search_for_values(car, value);
			break;
		case EXIT:
			std::cout << "\nПрограмма успешно завершена" << std::endl;
			break;
		default:
			std::cout << "\nВы ввели что-то не так!" << std::endl;
			break;
		}
	} while (action != EXIT);
	return 0;
}
