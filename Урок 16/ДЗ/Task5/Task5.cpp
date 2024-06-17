#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

enum EntityType
{
	BIRD = 1,
	CATTLE,
	HUMAN
};

enum ArtiodactylCheck
{
	YES = 1,
	NO
};

union Characteristic
{
	float bird_flying_speed;
	bool isCattleArtiodactyl;
	int human_IQ_level;
};

struct LivingEntity
{
	float move_speed;
	EntityType type;
	std::string colour;
	Characteristic characteristic;
};

void fill_entity_data(LivingEntity& entity)
{
	std::cout << "---Создание сущности---" << std::endl;
	std::cout << "Введите скорости передвижения (км/ч): ";
	std::cin >> entity.move_speed;

	int enum_val;
	bool isDataCorrect1;
	do
	{
		isDataCorrect1 = true;
		std::cout << "Типы сущности:" << std::endl
			<< "1)Птица" << std::endl
			<< "2)Скот" << std::endl
			<< "3)Человек" << std::endl
			<< "Введите тип сущности: ";
		std::cin >> enum_val;
		EntityType entity_type = static_cast<EntityType>(enum_val);

		switch (entity_type)
		{
		case BIRD:
			entity.type = BIRD;
			std::cout << "Введите скорость полета птицы: ";
			std::cin >> entity.characteristic.bird_flying_speed;
			break;
		case CATTLE:
			int artiodactylcheck_val;
			bool isDataCorrect2;
			entity.type = CATTLE;
			do
			{
				isDataCorrect2 = true;
				std::cout << "Ваше животное парнокопытное (1 - Да | 2 - Нет): ";
				std::cin >> artiodactylcheck_val;
				ArtiodactylCheck isArtiodactyl = 
					static_cast<ArtiodactylCheck> (artiodactylcheck_val);
				switch (isArtiodactyl)
				{
				case YES:
					entity.characteristic.isCattleArtiodactyl = true;
					break;
				case NO:
					entity.characteristic.isCattleArtiodactyl = false;
					break;
				default:
					std::cout << "Вы ввели что-то не так!" << std::endl;
					isDataCorrect2 = false;
					break;
				}
			} while (!isDataCorrect2);
			break;
		case HUMAN:
			entity.type = HUMAN;
			std::cout << "Введите количество IQ человека: ";
			std::cin >> entity.characteristic.human_IQ_level;
			break;
		default:
			std::cout << "Вы ввели что-то не так!" << std::endl;
			isDataCorrect1 = false;
			break;
		}
	} while (!isDataCorrect1);
	
	std::cout << "Введите цвет сущности: ";
	std::cin >> entity.colour;
}

void print_entity_info(LivingEntity const& entity)
{
	std::cout << "\nСкорость передвижения: " << entity.move_speed << std::endl
		<< "Тип: ";
	switch (entity.type)
	{
	case BIRD:
		std::cout << "Птица" << std::endl;
		std::cout << "Скорость полета: " << entity.characteristic.bird_flying_speed
			<< std::endl;
		break;
	case CATTLE:
		std::cout << "Скот" << std::endl;
		std::cout << "Парнокопытность: ";
		switch (entity.characteristic.isCattleArtiodactyl)
		{
		case true:
			std::cout << "Присутствует" << std::endl;
			break;
		case false:
			std::cout << "Отсутствует" << std::endl;
			break;
		}
		break;
	case HUMAN:
		std::cout << "Человек" << std::endl;
		std::cout << "Уровень IQ: " << entity.characteristic.human_IQ_level
			<< std::endl;
		break;
	}
	std::cout << "Цвет: " << entity.colour << std::endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	LivingEntity test_entity;

	fill_entity_data(test_entity);

	print_entity_info(test_entity);

	return 0;
}