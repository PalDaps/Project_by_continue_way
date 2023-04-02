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

	}
	char& get_c(Cls_mine& object)
	{
		return c;
	}
	double& get_d(Cls_mine& object)
	{

	}
	int& get_i(Cls_mine& object)
	{

	}
private:
	char c;
	double d;
	int i;
};

int main()
{
	Cls_mine object('a', 2.5, 3);
	std::cout << object.get_c(object);
	return 0;
}