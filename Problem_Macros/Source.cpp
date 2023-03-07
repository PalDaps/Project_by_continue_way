#include <iostream>
#define LOL 5
int main()
{
#if LOL >5
	for (int i = 0; i < 4; ++i)
		std::cout << i << " ";
	

	std::cout << "HALLO";
#else
	std::cout << "ANIME";
#endif
	return 0;
}