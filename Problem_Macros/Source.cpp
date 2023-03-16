#include <iostream>
// #define test1
// #define recursion_io
#define recursion_reverse

void io_numbers()
{
	int a;
	std::cin >> a;
	std::cout << a << " ";
	if (a == 0) return;
	io_numbers();
}
void io_reverse_numbers(int n)
{
	int i;
	i = n;
	std::cout << i << " ";
	n--;
	if (n == 0)
	{
		std::cout << n;
		return;
	}
	io_reverse_numbers(n);
}

int main()
{
#ifdef test1
	int n = 0;
	std::cin >> n;
	for (int i = n; i >= 0; --i)
		std::cout << i << " ";

	std::cout << "HALLO";
#endif


#ifdef recursion_io
	input_the_numbers();
#endif


#ifdef recursion_reverse
	int n = 0;
	std::cin >> n;
	io_reverse_numbers(n);
#endif
	return 0;
}