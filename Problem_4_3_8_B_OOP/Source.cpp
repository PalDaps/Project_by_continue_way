#include <iostream>

//
// Develop an Expression class hierarchy to represent arithmetic 
// expressions. When the BinaryOperation object is destroyed, 
// it is responsible for destroying the left and right operands 
// (it is guaranteed that they are allocated in dynamic memory).
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
		switch(op)
		{ 
		case '*' :
			return (*left).evaluate() * (*right).evaluate();
		case '+' :
			return left->evaluate() + right->evaluate();
		case '/' :
			return left->evaluate() / right->evaluate();
		case '-' :
			return left->evaluate() - right->evaluate();
		default :
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

int main()
{
	Number a(4.5);
	Expression* sube = (Expression*)new BinaryOperation((Expression*)new Number(4.5), '*', (Expression*)new Number(5));
	Expression* expr = (Expression*)new BinaryOperation((Expression*)new Number(3), '+', sube);
	std::cout << expr->evaluate() << std::endl;
	delete expr;
	return 0;
}