#include <iostream>

struct String
{
	String(const char* str_main = "")
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
	String(size_t n, char c)
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
	~String()
	{
		delete[] this->str;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->str[i] = other.str[i];
		}

	}
	void append(const String& stroka)
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
private:
	size_t size;
	char* str;
};