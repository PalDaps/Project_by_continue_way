#include <iostream>

//
// Need to implement a function that shifts the 
// contents of the array to the left by a given 
// number of positions
//

void rotate(int a[], unsigned size, int shift)
{
	for (int i = 0; i <= size; ++i)
	{
		a[(i + 1) % size] = a[i];
	}
	for (int i = 0; i < size; ++i)
	{
		std::cout << a[i] << " ";
	}
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	unsigned size = sizeof(a) / 4;
	int* p_1 = &a[1];
	int* p_2 = &a[2];

	std::cout << p_1 << " " << p_2 << std::endl;
	p_1++;
	std::cout << p_1 << std::endl;

	for (int* i = &a[0]; *i <= sizeof(a)/4; ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	rotate(a, size, 2);
	return 0;
}