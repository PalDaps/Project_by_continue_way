#include <iostream>
#include <string>

//
//
//

int main()
{
	int count = 0;
	char c = '\0';
	while (std::cin.get(c))
	{
		if (c == ' ') count++;

		std::cout << c;
		if (c == '\n') break;
	}
	std::cout << count;
	return 0;
}