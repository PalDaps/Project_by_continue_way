#include <iostream>

//
// A structure can have several constructors. A fill-in constructor 
// may be useful for a string (for example, to create a string of 
// spaces). The fill-in constructor takes a number and a character, 
// and creates a string with a specified number of repetitions of 
// the passed character. You also need to implement a destructor 
// that will free up the allocated memory.
//
struct string_mine_two
{
	explicit string_mine_two(size_t n, char c)
	{

		this->size = n;
		char* new_str = new char[this->size+1];
		for (int i = 0; i < this->size; i++)
		{
			new_str[i] = c;
		}
		new_str[this->size] = '\0';
		this->str = new_str;
	}
	~string_mine_two()
	{
		delete[] this->str;
	}
	size_t size;
	char* str;
	
};

int main()
{
	string_mine_two line(5, 'k');

		
	return 0;
}