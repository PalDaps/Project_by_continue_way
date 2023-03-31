#include <iostream>
#include <cstddef>
#include <cstring>

//
// It is required to implement a constructor that accepts a C-style 
// string as input, calculates its size (excluding the terminating 
// 0 character) and stores it in the size field, in addition, 
// the constructor must allocate memory sufficient to store 
// a copy of the passed string (along with the terminating 0 character), 
// copies the passed string to the allocated memory and saves 
// the pointer to the beginning of this memory area 
// in the str field
//
struct string_mine_one
{
	explicit string_mine_one(const char* str_main = "")
	{
		this->size = strlen(str_main);
		char* new_str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			new_str[i] = str_main[i];
		}
		new_str[size + 1] = '\0';
		this->str = new_str;
	}
	size_t size;
	char* str;
};

int main()
{
	string_mine_one line("hello world!");
	std::cout << line.size << std::endl;
	return 0;
}