#include <iostream>
#include <string>

// #define one

//
// Write a function that calculates the length of a 
// C-style string. Note that the terminating null 
// character does not need to be counted.
//
unsigned strlen_mine(const char* str)
{
	int count = 0;
	const char* ptr = str;
	while (*ptr != '\0')
	{
		count++;
		ptr++;
	}
	return count;
}
int main()
{
#ifdef one
	char hello[] = "Hello";
	char hello2[] = { 'a', 'b' };
	char* p_one = hello2;
	for (int i = 0; i < sizeof(hello) / sizeof(char); i++)
		std::cout << hello[i] << " ";
	std::cout << std::endl;
	std::cout << *p_one << std::endl;
	strlen_mine(hello);
#endif
	char str[] = "Jojo";
	char* p_one = str;
	std::cout << *p_one << std::endl << strlen_mine(str);
	return 0;
}