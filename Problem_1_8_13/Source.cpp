#include <iostream>

//
// Write a program to calculate the integer 
// logarithm to base 2.
//
void logar(int b)
{
	int counter = 0;
	while (true)
	{
		int del;
		del = b / 2;
		b = del;
		counter++;
		if (b < 2) break;
	}
	std::cout << counter << std::endl;
}

int main()
{
	int n = 0, x = 0, b = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> b;
		logar(b);
	}
	return 0;
}