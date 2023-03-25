#include <iostream>
#include <string>

//
// Implement the getline function, which reads the 
// input stream character by character until it 
// reaches the end of the stream or encounters a 
// line break character ('\n'), and returns a C-style 
// string with the characters read.
//
char* memory_oxp(char* arr_of_char, int new_size, int i)
{
	char* more_size_arr = new char[new_size];
	for (int j = 0; j < i; j++)
	{
		more_size_arr[j] = arr_of_char[j];
	}
	delete[] arr_of_char;
	arr_of_char = more_size_arr;
	return arr_of_char;
}
char* getline_mine()
{
	char symbol = 'a';
	int size = 10, new_size = 0;
	char* arr_of_char = new char[size];
	int i = 0;
	while (std::cin.get(symbol) && symbol != '\n' && symbol != std::cin.eof())
	{
		if (i >= size)
		{
			new_size = size * 2;
			arr_of_char = memory_oxp(arr_of_char, new_size, i);
			size = new_size;
		}
		arr_of_char[i] = symbol;
		i++;
	}
	arr_of_char = memory_oxp(arr_of_char, i+1, i);
	arr_of_char[i] = '\0';
	for (int j = 0; j < i; j++)
	{
		std::cout << *(arr_of_char + j);
	}
		return arr_of_char;
		delete[] arr_of_char;
}

int main()
{
	/* char symbol = 'a';
	int size = 10, new_size = 0;
	char* arr_of_char = new char[size];
	int i = 0;
	while (std::cin.get(symbol) && symbol != '\n')
	{
		if (i >= size)
		{
			new_size = size * 2;
			char* more_size_arr = new char[new_size];
			size = new_size;
			for (int j = 0; j < i; j++)
			{
				more_size_arr[j] = arr_of_char[j];
			}
			delete[] arr_of_char;
			arr_of_char = more_size_arr;
		}
		arr_of_char[i] = symbol;
		i++;
	}
	char* new_arr_of_char = new char[i];
	for (int j = 0; j < i; j++)
	{
		new_arr_of_char[j] = arr_of_char[j];
	}
	delete[] arr_of_char;
	arr_of_char = new_arr_of_char;
	for (int j = 0; j < i; j++)
	{
		std::cout << *(arr_of_char+j);
	}
	*/
	getline_mine();
	// delete[] arr_of_char;
	
	return 0;
}