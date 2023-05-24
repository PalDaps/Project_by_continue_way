#include <iostream>

//
// You need to implement a function that takes two pointers 
// to the base Expression class as input, and returns true 
// if both pointers actually point to objects of the same class, 
// and false otherwise
//
class Expression
{
public:
	virtual double evaluate() const = 0;
	virtual ~Expression()
	{

	}
};


class Number : Expression
{
public:
	Number(double value) : value(value)
	{
	}
	double evaluate() const
	{
		return value;
	}
	~Number()
	{
		std::cout << "Destructor frome Number" << std::endl;
	}

private:
	double value;
};

class BinaryOperation : Expression
{
public:
	BinaryOperation(Expression const* left, char op, Expression const* right)
		: left(left), op(op), right(right)
	{

	}
	double evaluate() const
	{
		switch (op)
		{
		case '*':
			return (*left).evaluate() * (*right).evaluate();
		case '+':
			return left->evaluate() + right->evaluate();
		case '/':
			return left->evaluate() / right->evaluate();
		case '-':
			return left->evaluate() - right->evaluate();
		default:
			return 0;
		}

	}
	~BinaryOperation()
	{
		std::cout << "Destructor from BinaryOperation" << std::endl;
		delete left;
		delete right;
	}

private:
	Expression const* left;
	char op;
	Expression const* right;

};

bool check_equals(Expression const* left, Expression const* right)
{
	return *((int**)left) == *((int**)right);
}

int main()
{
	Number left(2.5);
	Number right(3.0);
	// BinaryOperation* binary = new BinaryOperation(left, '+', right);

	return 0;
}