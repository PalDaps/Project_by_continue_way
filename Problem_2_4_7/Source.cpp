#include <iostream>

//
// You need to implement the concatenation (gluing) 
// function of two C-style strings. The concatenation 
// function takes two C-style strings as input and 
// appends the second one to the end of the first one 
// so that the first line is one C-style string equal 
// to the concatenation of the two original ones
//

void strcat_mine(char* to, const char* from)
{
	int counter = 0;
	char* ptr = &to[0];
	while (*ptr != '\0')
		ptr++;
	const char* ptr2 = &from[0];
	while (*ptr2 != '\0')
	{
		*ptr = *ptr2;
		ptr++;
		ptr2++;
		counter++;
	}
}

int main()
{
	char to[13] = "Hello, ";
	char from[] = "world";
	strcat_mine(to, from); 
	return 0;
}