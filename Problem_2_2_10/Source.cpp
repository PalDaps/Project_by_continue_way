#include <iostream>

//
// It is required to write a program that "reverses" 
// a sequence of positive integers using recursion.
//

void iorow()
{
	int n;
	std::cin >> n;
	if (n == 0) return;
	iorow();
	std::cout << n << " ";
}

int main()
{
	iorow();
	return 0;
}