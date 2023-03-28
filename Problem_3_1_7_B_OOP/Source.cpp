#include <iostream>

struct ivector3d
{
	int arr[3];
};

void scale(ivector3d p, int k) 
{
	struct ivector3d x;
	for (int i = 0; i != 3; i++)
	{
		p.arr[i] = p.arr[i] + k;
	}
	// p-> = (*p).
}
int main()
{
	struct ivector3d iv3d; 
	// iv3d.arr = { 2, 2, 2}; // хуета
	struct ivector3d ded;
	scale(iv3d, 2);
	return 0;
}