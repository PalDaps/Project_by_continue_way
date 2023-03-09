#include <iostream>
#include <string>

//
// Write a program that reads character - by - 
// character from std::cin until it consumes 
// the input stream, and replaces several 
// consecutive spaces with oneand outputs 
// the result to std::cout.
//

int main()
{
	int count = 0;
	char c = '\0';
	while (std::cin.get(c))
	{
		if (c != ' ' && c != '\n') count = 0;
		if (c == ' ') count++;
		if ( count <= 1 ) std::cout << c;
		if (c == '\n') break;
	}
	return 0;
}