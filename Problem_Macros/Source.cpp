#include <iostream>
#include <string>
// #define test1
// #define recursion_io
// #define recursion_reverse
// #define memory
// #define testing_structs
// #define DynamicArr
// #define ConstructorOfCoping
// #define PolymorphismFromSimple
// #define PurelyVirtualDestructorsFromeSimple
// #define Lecture2MIPT
// #define TheProblem44
#define Sobes
class A
{
public:
	A()
	{
		std::cout << "Dynamic memory is allocated A" << std::endl;
	}
	virtual ~A() = 0;
};

A::~A() {};

class B : public A
{
public:
	B()
	{
		std::cout << "Dynamic memory is allocated B" << std::endl;
	}
	~B() override
	{
		std::cout << "Dynamic memory is cleaned B" << std::endl;
	}
};


class Weapon
{ 
public:
	virtual void shoot() = 0;
	void Foo()
	{
		std::cout << " Foo()" << std::endl;
	}
};
class Gun : public Weapon
{
public:
	void shoot() override
	{
		std::cout << "BAANG!" << std::endl;
	}
};

class SubmachineGun : public Gun
{
public:
	void shoot() override
	{
		std::cout << "BANG! BANG! BANG!" << std::endl;
	}
};

class Bazooka : public Weapon
{
public:
	void shoot() override
	{
		std::cout << "BOOOM!" << std::endl;
	}
};

class Knife : public Weapon
{
public:
	void shoot() override
	{
		std::cout << "HUYAK" << std::endl;
	}
};
class Player
{
public:
	void shoot(Weapon* weapon)
	{
		weapon->shoot();
	}
};
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

int foo()
{
	return 42;
}

void foo_1(int* x)
{
	int g;
	g = *x;
}

void bar(int& x)
{
	int g;
	g = x;
}

struct Person
{
	virtual ~Person() {}
	Person(std::string name)
	{
		this->name_ = name;
	}
	virtual std::string name() const { return name_; }
	// virtual std::string occupation() const = 0;
	std::string name_;
};

struct Student : Person {
	std::string occupation() const { return "student"; }
	virtual int group() const { return group_; }
private:
	int group_;
};

struct Teacher : Person {
	Teacher(std::string const& name) : Person(name)
	{
		std::cout << this->name();
	}
};

struct Professor : Teacher {
	Professor(std::string const& name) : Teacher(name) {}
	std::string name() const override { return "Prof. " + name_; }
};

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
#ifdef DynamicArr
	int size = 5;
	int** pointer = new int* [size];
	for (int i = 0; i < size; i++)
	{
		pointer[i] = new int[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			pointer[i][j] = 1;
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << pointer[i][j] << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < size; i++)
	{
		delete[] pointer[i];
	}
#endif
#ifdef ConstructorOfCoping

#endif

#ifdef Polymorphism
	Gun gun;
	SubmachineGun machigun;
	Bazooka bazooka;
	// gun.shoot();
	// Gun* pointer = &machigun;

	// pointer->shoot();
	// gun.shoot();
	// machigun.shoot();
	Player Daps;
	Knife kerambit;
	// kerambit.Foo();
	// Daps.shoot(&kerambit);
	// Daps.shoot(&machigun);
	// Daps.shoot(&gun);
	// Daps.shoot(&bazooka);
#endif
#ifdef PurelyVirtualDestructorsFromSimple
	// A* bptr = new B;
	// delete bptr;
#endif
#ifdef Lecture2MIPT
	int x;
	int& rx = x;
	const int& l = foo();
	std::cout << &l << " " << &x << " " << &rx << std::endl;
	// using links
	int x;
#endif
#ifdef TheProblem44
	Professor p("Strausstrup");

#endif
#ifdef Sobes
	int a = 101010101010;
	int count0 = 0;
	int count1 = 0;
	for (int i = 0; i < sizeof(a) * 8; i++) {
		int bit = (a >> i) & 1; // Extract the i-th bit using bitwise shift and bitwise AND

		if (bit == 0) {
			count0++; // Increment the count of 0s
		}
		else {
			count1++; // Increment the count of 1s
		}
	}
	std::cout << "Count0 " << count0 << std::endl; // idi nahui
	std::cout << "Count1 " << count1 << std::endl;
#endif

	return 0;
}