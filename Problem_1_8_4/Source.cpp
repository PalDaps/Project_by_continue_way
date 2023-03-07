#include <iostream>

//
// Write a power function that implements 
// the raising of an integer to a non-negative integer power
//

int power(int x, unsigned p) 
{
    int answer;
    if (p == 0) return 1;
    return x*power(x, p - 1);
}

int main()
{
    int x = 0;
    unsigned p = 0;
    std::cin >> x >> p;
    std::cout << power(x, p);
	return 0;
}