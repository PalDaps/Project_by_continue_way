#include <iostream>
// #define test1
// #define recursion_io
// #define recursion_reverse
// #define memory

void io_numbers()
{
	int a;
	std::cin >> a;
	if (a == 0) return;
	io_numbers();
	std::cout << a << " ";
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
	io_numbers();
#endif


#ifdef recursion_reverse
	int n = 0;
	std::cin >> n;
	io_reverse_numbers(n);
#endif

#ifdef memory


#endif
	return 0;
}