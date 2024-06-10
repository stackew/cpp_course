#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

std::vector<std::vector<int>> d2vector_init()
{
	int rows, cols;
	std::cout << "Введите количество строк и столбцов массива(строки, столбцы): ";
	std::cin >> rows >> cols;
	std::vector<std::vector<int>> d2vector(rows,
		std::vector<int>(cols));

	for (int i = 0; i != rows; i++)
	{
		for (int j = 0; j != cols; j++)
		{
			d2vector[i][j] = rand() % (-10 - 10 + 1) - 10;
		}
	}
	return d2vector;
}

void d2vector_cout(std::vector<std::vector<int>> const& d2vector)
{
	for (auto const& rows : d2vector)
	{
		for (auto el : rows)
		{
			std::cout << el << " ";
		}
		std::cout << std::endl;
	}
}

void d1vector_count(std::vector<int> const& vector)
{
	for (int el : vector)
	{
		std::cout << el << " ";
	}
}
bool isElIn2DVector(std::vector<std::vector<int>> const& d2vector, int el)
{
	for (auto const& row : d2vector)
	{
		if (std::find(row.begin(), row.end(), el) != row.end())
		{
			return true;
		}
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	std::cout << "---Массив A---" << std::endl;
	std::vector<std::vector<int>> A = d2vector_init();
	d2vector_cout(A);

	std::cout << "\n---Массив B---" << std::endl;
	std::vector<std::vector<int>> B = d2vector_init();
	d2vector_cout(B);

	std::cout << "\n---Массив C---" << std::endl;
	std::vector<std::vector<int>> C = d2vector_init();
	d2vector_cout(C);
	
	std::vector<int> common_ABC;
	for (const auto  &row : A)
	{
		for (const int & el : row)
		{
			if (std::find(common_ABC.begin(), common_ABC.end(), el) == common_ABC.end() &&
				isElIn2DVector(B, el) &&
				isElIn2DVector(C, el))
			{
				common_ABC.push_back(el);
			}
		}
	}
	std::cout << "Общие значения для ABC: ";
	d1vector_count(common_ABC);

	std::vector<int> unique_ABC;
	for (const auto & vector : { A, B, C })
	{
		for (const auto& row : vector)
		{
			for (const int &el : row)
			{
				if (std::find(unique_ABC.begin(), unique_ABC.end(), el) == unique_ABC.end())
				{
					if (vector == A)
					{
						if(!isElIn2DVector(B, el) && !isElIn2DVector(C, el))
						{
							unique_ABC.push_back(el);
						}
					}
					else if (vector == B)
					{
						if (!isElIn2DVector(A, el) && !isElIn2DVector(C, el))
						{
							unique_ABC.push_back(el);
						}
					}
					else
					{
						if (!isElIn2DVector(A, el) && !isElIn2DVector(B, el))
						{
							unique_ABC.push_back(el);
						}
					}
				}
			}
		}
	}
	std::cout << "\nУникальные значения для ABC: ";
	d1vector_count(unique_ABC);

	std::vector<int> common_AC;
	for (const auto& row : A)
	{
		for (const int & el : row)
		{
			if (std::find(common_AC.begin(), common_AC.end(), el) == common_AC.end() &&
				isElIn2DVector(C, el))
			{
				common_AC.push_back(el);
			}
		}
	}
	std::cout << "\nОбщие значения для AC: ";
	d1vector_count(common_AC);

	std::vector<int> negative_ABC;
	for (const auto& vector : { A, B, C })
	{
		for (const auto& row : vector)
		{
			for (const int& el : row)
			{
				if (std::find(negative_ABC.begin(), negative_ABC.end(), el) == negative_ABC.end() &&
					el < 0)
				{
					negative_ABC.push_back(el);
				}
			}
		}
	}
	std::cout << "\nНегативные значения для ABC: ";
	d1vector_count(negative_ABC);
	return 0;
}