#include <iostream>

//
// Implement several functions that give full access 
// to these fields (see the code template), despite 
// the fact that they are closed.
//

class Cls_mine
{
public:
	Cls_mine(char c, double d, int i)
	{
		this->c = c;
		this->d = d;
		this->i = i;
	}
	char& get_c(Cls_mine& object)
	{
		Cls_mine* pointer_c = &object;
		return *((char*)(pointer_c));
	}
	double& get_d(Cls_mine& object)
	{
		Cls_mine* pointer_x = &object;
		char* pointer_d = (char*)pointer_x;
		pointer_d = pointer_d + 8;
		return *(double *)pointer_d;

	}
	int& get_i(Cls_mine& object)
	{
		Cls_mine* pointer_y = &object;
		char* pointer_i = (char*)pointer_y;
		pointer_i = pointer_i + 16;
		return *((int*)((double*)pointer_i));

	}
private:
	char c;
	double d;
	int i;
};

int main()
{
	Cls_mine object('a', 2.5, 3);
	std::cout << object.get_i(object);
	return 0;
}