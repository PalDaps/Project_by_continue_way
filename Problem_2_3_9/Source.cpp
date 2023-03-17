#include <iostream>

//
// Need to implement a function that shifts the 
// contents of the array to the left by a given 
// number of positions
//

void rotate(int a[], unsigned size, int shift)
{
	int first_elem = shift % size;
	for (int k = 0; k < shift % size; ++k)
	{
	
		for (int i = 1; i < size; i++)
		{
			int temp = a[i-1];
			a[i - 1] = a[i];
			a[i] = temp;
		}
	}
	for (int i = 0; i < size; ++i)
		std::cout << a[i] << " ";
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	unsigned size = sizeof(a) / 4;
	int* p_1 = &a[1];
	int* p_2 = &a[2];
	int shift = 0;
	std::cin >> shift;
	std::cout << p_1 << " " << p_2 << std::endl;
	p_1++;
	std::cout << p_1 << std::endl;

	for (int* i = &a[0]; *i <= sizeof(a)/4; ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	rotate(a, size, shift);
	return 0;
}