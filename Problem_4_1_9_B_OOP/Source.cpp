#include <iostream>

//
// Implement the get_foo function so that the 
// following code compiles and works: 
// foo_says(get_foo(msg));
//

struct Foo {
public:
	void say() const
	{
		std::cout << "Foo says: " << msg << "\n";
	}
protected:
	Foo(const char* msg) : msg(msg)
	{

	}
private:
	const char* msg;
};

void foo_says(const Foo& foo)
{
	foo.say();
}

Foo get_foo(const char* msg)
{
	struct Foo_without_protected : Foo { // A class that inherits from the Foo class to access the Foo constructor, since this constructor is in the protected segment
		Foo_without_protected(const char* msg) : Foo(msg)
		{
		}
	
	};
	Foo_without_protected Object(msg);
	return Object;
}

int main()
{
	char msg[] = "Hello";
	foo_says(get_foo(msg));
	return 0;
}