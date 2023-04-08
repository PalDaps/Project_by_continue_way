#include <iostream>
#include <cstring>

//
// To work with strings, you can come up with many useful methods. 
// An example of such a method is the append method — it adds a 
// copy of the argument string to the end of the current line. 
// You need to implement the append method.
//
struct string_mine_three
{
	explicit string_mine_three(const char* str_main = "")
	{
		this->size = strlen(str_main);
		char* new_str = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			new_str[i] = str_main[i];
		}
		new_str[size] = '\0';
		this->str = new_str;
	}
	explicit string_mine_three(size_t n, char c)
	{

		this->size = n;
		char* new_str = new char[this->size + 1];
		for (int i = 0; i < this->size; i++)
		{
			new_str[i] = c;
		}
		new_str[this->size] = '\0';
		this->str = new_str;
	}
	void append(string_mine_three& stroka)
	{
		size_t size_of_line2 = stroka.size;
		char* word = new char[this->size + stroka.size + 1];
		for (int i = 0; i < this->size; i++)
		{
			word[i] = this->str[i];
		}
		for (int i = this->size, k = 0; i < this->size + stroka.size; i++, k++)
		{
			word[i] = stroka.str[k];
		}
		word[this->size + stroka.size] = '\0';
		delete[] str;
		this->str = word;
		this->size = this->size + stroka.size;
		std::cout << this->str;
	}
	~string_mine_three()
	{
		delete[] this->str;

	}
	size_t size;
	char* str;
};

string_mine_three spaces(size_t n)
{
	const string_mine_three s(n, 'a');
	return s;
}
void foo(string_mine_three object)
{
	std::cout << object.str << "\n";
}

int main()
{
	string_mine_three line1("a");
	string_mine_three line2("b");
	// std::cout << spaces(10).str << "\n";
	string_mine_three ten_spaces;
	// ten_spaces = string_mine_three(10, 'a');
	// std::cout << ten_spaces.str << "\n";
	// foo(string_mine_three(10, 'a'));
	return 0;
}