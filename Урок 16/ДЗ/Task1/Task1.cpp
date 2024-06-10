#include <iostream>

struct complex_num
{
	double a;
	double b;
};

enum Actions
{
	SUM = 1,
	SUB = 2,
	MULTI = 3,
	DIV = 4
};

void cout_cnum(complex_num cnum)
{
	char NorP;
	cnum.b > 0 ? NorP = '+' : NorP = ' ';
	std::cout << cnum.a << NorP << cnum.b << "i" << std::endl;
}

complex_num summ(complex_num num1, complex_num num2)
{
	complex_num result;

	result.a = num1.a + num2.a;
	result.b = num1.b + num2.b;

	return result;
}

complex_num sub(complex_num num1, complex_num num2)
{
	complex_num result;

	result.a = num1.a - num2.a;
	result.b = num1.b - num2.b;

	return result;
}

complex_num multi(complex_num num1, complex_num num2)
{
	complex_num result;

	result.a = (num1.a * num2.a) + (num1.b * (num2.b * -1));
	result.b = (num1.a * num2.b) + (num1.b * num2.a);

	return result;
}

complex_num div(complex_num num1, complex_num num2)
{
	complex_num result;
	
	result.a = (num1.a * num2.a + num1.b * num2.b) / (num2.a * num2.a + num2.b * num2.b);
	result.b = (num1.b * num2.a - num1.a * num2.b) / (num2.a * num2.a + num2.b * num2.b);

	return result;
}
int main()
{
	setlocale(LC_ALL, "rus");
	complex_num first_cnum, second_cnum, result;
	std::cout << "Введите 1 комплексное число (Действительная часть, Мнимая часть): ";
	std::cin >> first_cnum.a >> first_cnum.b;
	std::cout << "Введите 2 комплексное число (Действительная часть, Мнимая часть): ";
	std::cin >> second_cnum.a >> second_cnum.b;

	std::cout << "1 комплексное число: ";
	cout_cnum(first_cnum);
	std::cout << "2 комплексное число: ";
	cout_cnum(second_cnum);

	int value;
	std::cout << "1)Сложить" << std::endl
		<< "2)Вычесть" << std::endl
		<< "3)Умножить" << std::endl
		<< "4)Разделить" << std::endl
		<< "Выберите действие: ";
	std::cin >> value;
	Actions action = static_cast<Actions>(value);
	switch (action)
	{
	case SUM:
		result = summ(first_cnum, second_cnum);
		break;
	case SUB:
		result = sub(first_cnum, second_cnum);
		break;
	case MULTI:
		result = multi(first_cnum, second_cnum);
		break;
	case DIV:
		result = div(first_cnum, second_cnum);
		break;
	default:
		std::cout << "Вы ввели что то не так!" << std::endl;
		return 0;
		break;
	}

	std::cout << "Ответ: ";
	cout_cnum(result);
	return 0;
}