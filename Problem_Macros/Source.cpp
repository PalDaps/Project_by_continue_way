#include <iostream>
// #define test1
// #define recursion_io
// #define recursion_reverse
// #define memory
#define testing_structs

void io_numbers()
{
	int a;
	std::cin >> a;
	if (a == 0) return;
	io_numbers();
	std::cout << a << " ";
}
void io_reverse_numbers(int n)
{
	int i;
	i = n;
	std::cout << i << " ";
	n--;
	if (n == 0)
	{
		std::cout << n;
		return;
	}
	io_reverse_numbers(n);
}

struct Point
{
	double x;
	double y;
	void shift(Point *lala, double value_x, double value_y)
	{
		this->x = this->x + x; // обращаемс€ к соответствующему полю экземпл€ра lala
		this->y = this->y + y; 
		std::cout << this->x << " " << this->y << std::endl;
		std::cout << lala->x << " " << lala->y << std::endl;
		x = x + value_x; // это че? j
		y = y + value_y; // это че?
		std::cout << x << " " << y;
	}
};

struct Segment
{	
    Point t1;
	Point t2;

};


double length_of_line(Segment object)
{
	double dx;
	double dy;
	dx = object.t1.x - object.t2.x;
	std::cout << dx << std::endl;
	dy = object.t1.y - object.t2.y;
	std::cout << dy << std::endl;
	return sqrt(pow(dx, 2) - pow(dy, 2));
}


int main()
{
#ifdef test1
	int n = 0;
	std::cin >> n;
	for (int i = n; i >= 0; --i)
		std::cout << i << " ";

	std::cout << "HALLO";
#endif


#ifdef recursion_io
	io_numbers();
#endif


#ifdef recursion_reverse
	int n = 0;
	std::cin >> n;
	io_reverse_numbers(n);
#endif

#ifdef memory


#endif
#ifdef testing_structs
	Point one = { 2.5, 3.9 };
	Point two = { 6.4, 1.3 };
	// Segment line = { one, two };
	// std::cout << length_of_line(line);
	one.shift(&one, 1.0, 1.0);
#endif
	return 0;
}