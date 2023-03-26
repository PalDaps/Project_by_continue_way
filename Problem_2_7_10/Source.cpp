#include <iostream>

//
// Implement the swap_min function, which takes a two-dimensional array 
// of integers as input, searches in this array for a string containing 
// the smallest value among all the array elements, and swaps this 
// string with the first row of the array.
//

void swap_min(int* m[], unsigned rows, unsigned cols)
{
	int safe_i = 0;
	int num_min = m[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (num_min > m[i][j])
			{
				num_min = m[i][j];
				safe_i = i;
			}
		}
	}
	int* temp = m[safe_i];
	m[safe_i] = m[0];
	m[0] = temp;
}

int main()
{
	int rows = 4, cols = 4, safe_i = 0, safe_j = 0;
	int** m = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		m[i] = new int[cols];
	}
	for ( int i = 0; i < rows; i++ )
	{ 
		for (int j = 0; j < cols; j++)
		{
			m[i][j] = rand() % 11;
		}
	}
	int num_min = m[0][0];
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (num_min > m[i][j])
			{
				num_min = m[i][j];
				safe_i = i;
			}
		}
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << m[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	int* temp = m[safe_i];
	m[safe_i] = m[0];
	m[0] = temp;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << m[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << num_min << " " << safe_i;
	for (int i = 0; i < rows; i++)
	{
		delete[] m[i];
	}
	delete[] m;
	return 0;
}