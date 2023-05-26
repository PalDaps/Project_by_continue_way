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


class Number : public Expression
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

class BinaryOperation : public Expression
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
	Expression* exp = new BinaryOperation(new Number(4.5), '*', new Number(2));
	std::cout << exp->evaluate();
	return 0;
}