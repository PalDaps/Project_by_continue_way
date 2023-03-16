#include <iostream>

//
// Need to implement a function that shifts the 
// contents of the array to the left by a given 
// number of positions
//

void rotate(int a[], unsigned size, int shift)
{

}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };

	int* p = &arr[1];

	for (int i = 0; i < sizeof(arr) / 4; ++i)
		std::cout << arr[i] << " ";
	return 0;
}