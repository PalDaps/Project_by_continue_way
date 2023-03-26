#include <iostream>

//
// Write a function that takes as input an integer matrix M 
// (in other words, just a two-dimensional integer array) 
// of the size rows×cols, and returns the transposed matrix
//
void allocate2d(unsigned rows, unsigned cols)
{
	int** ma = new int* [rows];
	for (unsigned int i = 0; i < rows; i++)
	{
		ma[i] = new int[cols];
	}
}
void delete2d(int **ma, unsigned rows)
{
	for (unsigned int i = 0; i < rows; i++)
	{
		delete[] ma[i];
	}
	delete[] ma;
}
int** transpose(int* const* m, unsigned rows, unsigned cols)
{
	int** ma = new int* [rows];
	for (unsigned int i = 0; i < rows; i++)
	{
		ma[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{ 
		for (int j = 0; j < cols; j++)
		{
			ma[i][j] = m[i][j];
		}
	}
	int** trans = new int* [cols];
	for (unsigned int i = 0; i < cols; i++)
	{
		trans[i] = new int[rows];
	}
	for (unsigned int i = 0; i < cols; i++)
	{
		for (unsigned int j = 0; j < rows; j++)
		{
			trans[i][j] = ma[j][i];
		}
	}
	for (unsigned int i = 0; i < cols; i++)
	{
		for (unsigned int j = 0; j < rows; j++)
		{
			std::cout << trans[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	return trans;
}

int main()
{
	int rows = 2, cols = 2, counter = 1;
	int** m = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		m[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			m[i][j] = counter++;
		}
	}
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			std::cout << m[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	transpose(m, rows, cols);
	/*for (int i = 0; i < rows; i++)
	{
		for (int j = i; j < cols; j++)
		{
			int temp = matrice[j][i];
			matrice[j][i] = matrice[i][j];
			matrice[i][j] = temp;
		}
	}
	for (int i = 0; i < rows; i++)
	{
		delete[] matrice[i];
	}
	delete[] matrice;
	*/

	return 0;
}