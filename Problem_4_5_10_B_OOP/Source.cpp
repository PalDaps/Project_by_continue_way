#include <iostream>

struct Number;
struct BinaryOperation;

struct Visitor {
	virtual void visitNumber(Number const* number) = 0;
	virtual void visitBinaryOption(BinaryOperation const* operation) = 0;
	virtual ~Visitor() {}
};

struct Expression
{
	virtual double evaluate() const = 0;
	virtual void visit(Visitor* visitor) const = 0;
	virtual ~Expression() {}
};

struct Number : Expression
{
private:
	double value;
public:
	Number(double value);
	double evaluate() const override {
		return value;
	}
	double get_value() const { 
		return value; 
	}
	void visit(Visitor* visitor) const {
		visitor->visitNumber(this);
	}
};

struct BinaryOperation : Expression
{
private:
	Expression const* left;
	Expression const* right;
	char op;
public:
	BinaryOperation(Expression const* left, char op, Expression const* right) 
		: left(left), right(right), op(op) {

	}
	~BinaryOperation() {

	}
	double evaluate() const {
		switch (op) {
		case '*' : 
			return left->evaluate() * right->evaluate();
		case '/' :
			return left->evaluate() / right->evaluate();
		case '+' :
			return left->evaluate() / right->evaluate();
		case '-' :
			return left->evaluate() / right->evaluate();
		default :
			return 0;
		}
	}
	Expression const* get_left() const {
		return left;
	}
	Expression const* get_right() const {
		return right;
	}
};

struct PrintVisitor : Visitor {
	void visitNumber(Number const* number) {

	}
	void visitBinaryOperation(BinaryOperation const* bop) {

	}

};


int main()
{
	return 0;
}