#include <iostream>
#include <string>

//
// Implement the MAX macro from three parameters, 
// which assigns to the integer (int) variable passed 
// as the third argument the largest of the values passed
// in the first two arguments.
//
#define mac_func(a, b, c)  \
{   int _a = a; \
    int _b = b; \
    (c) = (_a > _b ? _a : _b); \
}

int main()
{
	int a = 0, b = 0, c = 0, x = 0;
	std::cin >> a >> b >> c;
    mac_func(a, b, c);
	std::cout << std::endl << c;
	return 0;
}