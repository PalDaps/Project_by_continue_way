#include <iostream>

struct String {

	char& at(size_t idx)
	{
		return str[idx];
	}
	char at(size_t idx) const
	{
		return str[idx];
	}
	size_t size;
	char* str;
};

int main()
{
	// String greet("Hello");
	// char ch1 = greet.at(0);
	// String const const_greet("Hello, Const!");
	// char const& ch2 = const_greet.at(0);
	return 0;
}