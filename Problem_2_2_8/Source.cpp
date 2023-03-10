#include <iostream>

//
//
//

unsigned gcd(unsigned a, unsigned b)
{
	unsigned temp_one, temp_two, del;
	temp_one = (a > b ? a : b);
	temp_two = (a > b ? b : a);
	if (temp_two == 0) return temp_one;
	del = temp_one % temp_two;
	if (del == 0) return temp_two;
	else
	{
		temp_one = del;
		return gcd(temp_one, temp_two);
	}
}

int main()
{
	unsigned a = 0, b = 0;
	std::cin >> a >> b;
	std::cout << gcd(a, b);
	return 0;
}