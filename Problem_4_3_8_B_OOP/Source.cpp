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
	virtual ~Expression() {
	}
};


class Number : Expression
{
public:
	Number(double value) : value(value) {

	}
	double evaluate() const override;
	~Number() {
	}
	
private:
	double value;
};

class BinaryOperation : Expression
{
public:
	BinaryOperation(Expression const* left, char op, Expression const* right)
		: left(left), op(op), right(right) {
	}
	double evaluate() const override {
		if (left != nullptr && right != nullptr) {
			switch (op) {
			case '*':
				return (*left).evaluate() * (*right).evaluate();
			case '+':
				return left->evaluate() + right->evaluate();
			case '/':
				if (right->evaluate())
					return left->evaluate() / right->evaluate();
			case '-':
				return left->evaluate() - right->evaluate();
			default:
				return 0;
			}
		}
		else return 0;

	}
	~BinaryOperation() {
		if (left) {
			if (left != right) {
				delete left;
				left = nullptr;
			}	
		}
		if (right)
			delete right;
	}

private:
	Expression const* left;
	char op;
	Expression const* right;

};

double Number::evaluate() const {
	return value;
}

int main()
{
	Number a(4.5);
	Expression* sube = (Expression*)new BinaryOperation((Expression*)new Number(4.5), '*', (Expression*)new Number(5));
	Expression* expr = (Expression*)new BinaryOperation((Expression*)new Number(3), '+', sube);
	std::cout << expr->evaluate() << std::endl;
	delete expr;
	return 0;
}