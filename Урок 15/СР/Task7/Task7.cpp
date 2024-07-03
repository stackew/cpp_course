#include <iostream>
#include <vector>

#define M 2
#define N 3
#define K 3

using matrix = std::vector<std::vector<int>>;


void PrintMatrix(matrix const& matrix)
{
	for (const std::vector<int>& row : matrix)
	{
		for (const int& el : row)
		{
			std::cout << el << " ";
		}
		std::cout << std::endl;
	}
}



int MultiMatrixElSum(matrix const& matrix1, matrix const& matrix2, int& k, int& l)
{
	int El = 0;

	int count = K;
	int j = 0;

	while (count-- != 0)
	{
		El += matrix1[k][j] * matrix2[j][l];
		j++;
	}

	return El;
}

matrix MatrixMulti(matrix const& matrix1, matrix const& matrix2)
{
	matrix matrix3(M, std::vector<int>(K));

	int k = 0, l = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			matrix3[i][j] = MultiMatrixElSum(matrix1, matrix2, k, l);
			l++;
		}
		l = 0;
		k++;
	}

	return matrix3;
}

int main()
{
	matrix matrix1 = {
					   {1, 2, 3},
					   {1, 0, -1},	// M*N
	};

	matrix matrix2 = {
					   {3, 4, 5},
					   {6, 0, -2},	// N*K
					   {7, 1, 8},
	};


	matrix matrix3 = MatrixMulti(matrix1, matrix2);
	PrintMatrix(matrix3);

	return 0;
}