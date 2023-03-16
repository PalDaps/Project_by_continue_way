#include <iostream>

//
// It is required to write a program that "reverses" 
// a sequence of positive integers using recursion.
//

int iorow(int n)
{
	int temp = n;
	std::cout << n << " ";
	std::cin >> n;
	if (n == 0) {
		std::cout << n << " ";
		return n;
	}
	return iorow(n);
	std::cout << n << " ";
}

int main()
{

	int n = 0;
	std::cin >> n;
	iorow(n);
	return 0;

}