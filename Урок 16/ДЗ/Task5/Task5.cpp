#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#define ENTITY_VECTOR_SIZE 10

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
	double bird_flying_speed;
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

void fill_entity_type_and_char(LivingEntity& entity)
{
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
}

void fill_entity_data(LivingEntity& entity)
{
	std::cout << "Введите скорости передвижения (км/ч): ";
	std::cin >> entity.move_speed;

	fill_entity_type_and_char(entity);

	std::cout << "Введите цвет сущности: ";
	std::cin >> entity.colour;
}

LivingEntity entity_creation()
{
	LivingEntity entity;
	fill_entity_data(entity);

	return entity;
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

void edit_entity(LivingEntity& entity)
{
	fill_entity_data(entity);
}

void print_entities(std::vector<LivingEntity> const& entities)
{
	for (const LivingEntity& entity : entities)
	{
		print_entity_info(entity);
	}
}

void search_and_output_matches(std::vector<LivingEntity> const& entities,
	double const& characteristic)
{
	bool isPrinted = false;
	for (const LivingEntity& entity : entities)
	{
		if (entity.characteristic.bird_flying_speed == characteristic)
		{
			print_entity_info(entity);
			isPrinted = true;
		}
	}

	if (!isPrinted)
	{
		std::cout << "Ничего не найдено." << std::endl;
	}
}

void search_and_output_matches(std::vector<LivingEntity> const& entities,
	bool const& characteristic)
{
	bool isPrinted = false;
	for (const LivingEntity& entity : entities)
	{
		if (entity.characteristic.isCattleArtiodactyl == characteristic)
		{
			print_entity_info(entity);
			isPrinted = true;
		}
	}

	if (!isPrinted)
	{
		std::cout << "Ничего не найдено." << std::endl;
	}
}

void search_and_output_matches(std::vector<LivingEntity> const& entities,
	int const& characteristic)
{
	bool isPrinted = false;
	for (const LivingEntity& entity : entities)
	{
		if (entity.characteristic.human_IQ_level == characteristic)
		{
			print_entity_info(entity);
			isPrinted = true;
		}
	}

	if (!isPrinted)
	{
		std::cout << "Ничего не найдено." << std::endl;
	}
}

LivingEntity create_livingEntity_byParam(float move_speed, EntityType type, std::string colour,
	double characteristic)
{
	Characteristic ch;
	ch.bird_flying_speed = characteristic;
	return { move_speed, type, colour, ch };
}

LivingEntity create_livingEntity_byParam(float move_speed, EntityType type, std::string colour,
	bool characteristic)
{
	Characteristic ch;
	ch.isCattleArtiodactyl = characteristic;
	return{ move_speed, type, colour, ch };
}

LivingEntity create_livingEntity_byParam(float move_speed, EntityType type, std::string colour,
	int characteristic)
{
	Characteristic ch;
	ch.human_IQ_level = characteristic;
	return{ move_speed, type, colour, ch };
}


void search_by_characteristic(std::vector<LivingEntity> const& entities)
{
	int enum_entity;
	bool isDataCorrect1;
	do
	{
		isDataCorrect1 = true;
		std::cout << "\nЧью характеристику вы хотите найти" << std::endl
			<< "1)Птицы" << std::endl
			<< "2)Скота" << std::endl
			<< "3)Человека" << std::endl
			<< "Введите ответ: ";
		std::cin >> enum_entity;
		EntityType type = static_cast<EntityType>(enum_entity);
		switch (type)
		{
		case BIRD:
			double bird_ch;
			std::cout << "Введите скорость полета птицы: ";
			std::cin >> bird_ch;
			search_and_output_matches(entities, bird_ch);
			break;
		case CATTLE:
			bool cattle_ch, isDataCorrect2;
			int artiodactylcheck_val;
			do
			{
				isDataCorrect2 = true;

				std::cout << "Животное парнокопытное (1-Да | 2-Нет): ";
				std::cin >> artiodactylcheck_val;
				ArtiodactylCheck isArtiodactyl =
					static_cast<ArtiodactylCheck>(artiodactylcheck_val);
				switch (isArtiodactyl)
				{
				case YES:
					cattle_ch = true;
					break;
				case NO:
					cattle_ch = false;
					break;
				default:
					std::cout << "Вы ввели что-то не так!" << std::endl;
					isDataCorrect2 = false;
					break;
				}

			} while (!isDataCorrect2);
			search_and_output_matches(entities, cattle_ch);
			break;
		case HUMAN:
			int human_ch;
			std::cout << "Введите IQ человека: ";
			std::cin >> human_ch;
			search_and_output_matches(entities, human_ch);
			break;
		default:
			std::cout << "Вы ввели что-то не так!" << std::endl;
			isDataCorrect1 = false;
			break;
		}

	} while (!isDataCorrect1);
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	LivingEntity test_entity = entity_creation();
	print_entity_info(test_entity);

	std::vector<LivingEntity> entities(ENTITY_VECTOR_SIZE);
	entities[0] = create_livingEntity_byParam(10, HUMAN, "Бежевый", 70);
	entities[1] = create_livingEntity_byParam(6, BIRD, "Синий", 6.4);
	entities[2] = create_livingEntity_byParam(5, HUMAN, "Черный", 110);
	entities[3] = create_livingEntity_byParam(7, CATTLE, "Белый", true);
	entities[4] = create_livingEntity_byParam(3, CATTLE, "Коричневый", false);
	entities[5] = create_livingEntity_byParam(1, BIRD, "Красный", 2.3);
	entities[6] = create_livingEntity_byParam(13, HUMAN, "Бежевый", 89);
	entities[7] = create_livingEntity_byParam(12, CATTLE, "Серый", true);
	entities[8] = create_livingEntity_byParam(0.8, BIRD, "Зеленый", 10.5);
	entities[9] = create_livingEntity_byParam(11, HUMAN, "Шоколадный", 97);

	print_entities(entities);
	edit_entity(entities[5]);
	print_entities(entities);

	search_by_characteristic(entities);
	return 0;
}