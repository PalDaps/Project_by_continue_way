#include <iostream>

struct ivector3d
{
	int* array;
};

void scale(ivector3d object, int k)
{
	for (int i = 0; i < 3; i++)
	{
		*(object.array + i) = *(object.array + i) * k;
	}
	for (int i = 0; i < 3; i++)
	{
		std::cout << object.array[i] << " ";
	}
}

int main()
{
	int m[3] = { 1, 1, 1 };
	int b[3] = { 1, 1, 1 };
	ivector3d iv3d = { m };
	scale(iv3d, 2);
	iv3d.array = b;
	return 0;
}