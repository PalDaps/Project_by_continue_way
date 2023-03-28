#include <iostream>

struct ivector3d
{
	int array[3];
};

void scale(ivector3d* v, int k)
{
	for (int i = 0; i != 3; ++i)
	{
		v->array[i] = v->array[i] * k;
	}
}
int main()
{
	ivector3d iv3d = { 1, 1, 1 };
	ivector3d iv4d = { 2, 2, 2 };
	scale(&iv3d, 2);
	return 0;
}