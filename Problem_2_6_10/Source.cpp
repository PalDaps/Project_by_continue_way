#include <iostream>
#include <string>

//
// Implement the getline function, which reads the 
// input stream character by character until it 
// reaches the end of the stream or encounters a 
// line break character ('\n'), and returns a C-style 
// string with the characters read.
//

int main()
{
	char symbol = 'a';
	int size = 10, new_size = 0;
	char* arr_of_char = new char[size];
	int i = 0;
	while (std::cin.get(symbol) && symbol != '\n')
	{
		arr_of_char[i] = symbol;
		i++;
		if (i > size)
		{
			new_size = size * 2;
			char* more_size_arr = new char[new_size];
		}
	}
	char* new_arr_of_char = new char[i];
	for (int j = 0; j < i; j++)
	{
		new_arr_of_char[j] = arr_of_char[j];
	}
	delete[] arr_of_char;

	for (int j = 0; j < i; j++)
	{
		std::cout << *(new_arr_of_char+j);
	}
	delete[] new_arr_of_char;
	
	return 0;
}