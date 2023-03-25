#include <iostream>

//
// In this problem, i need to implement the resize function. 
// The resize function takes three arguments as input: 
// a pointer to the memory area allocated using the 
// new[] operator, the size of the area (size) and 
// the new size (new_size). The function should 
// allocate memory of the new_size size, copy data 
// from the transferred memory area to it, free 
// the old memory area and return the allocated 
// memory area of the new size with the copied data.
//

char* resize(const char* str, unsigned size, unsigned new_size)
{
	char* new_arr_of_char = new char[new_size];
	for (int i = 0; i < new_size; i++)
	{
		new_arr_of_char[i] = str[i];
	}
	delete[] str;
	return new_arr_of_char;
}

int main()
{
	int size = 5;
	char* str = new char[size];
	for (int i = 0; i < size; i++)
	{
		str[i] = 'i';
	}
	for (int i = 0; i < size; i++)
	{
		std::cout << str[i];
	}
	std::cout << std::endl;
	std::cout << resize(str, size, 3);
	// delete[] str;

	return 0;
}