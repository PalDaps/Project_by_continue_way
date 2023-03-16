#include <iostream>
// #define test1
// #define recursion

int main()
{
#ifdef test1
	for (int i = 0; i < 4; ++i)
		std::cout << i << " ";

	std::cout << "HALLO";
#endif
	return 0;
}