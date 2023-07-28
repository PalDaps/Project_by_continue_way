#include <iostream>
#

struct Expression
{
	virtual double evaluate() const = 0;
	virtual ~Expression() {}
};

struct Number : Expression
{
private:
	double value;
public:
	Number(double value) : value(value) {

	}
	double evaluate() const override {
		return value;
	}
	double get_value() const {
		return value;
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
		if (left) {
			if (left != right) {
				delete left;
				left = nullptr;
			}
		}
		if (right) {
			delete right;
			right = nullptr;
		}
	}
	double evaluate() const override {
		if (left != nullptr && right != nullptr) {
			switch (op) {
			case '*':
				return left->evaluate() * right->evaluate();
			case '/':
				if (right->evaluate())
					return left->evaluate() / right->evaluate();
			case '+':
				return left->evaluate() + right->evaluate();
			case '-':
				return left->evaluate() - right->evaluate();
			default:
				return 0;
			}
		}
		else return 0;
	}
};

struct ScopedPtr {
	explicit ScopedPtr(Expression* ptr = nullptr) : ptr(ptr) {};
	Expression* get() const {
		return ptr;
	}
	Expression* release() {
		Expression* temp_ptr = ptr;
		ptr = nullptr;
		return temp_ptr;
	}
	void reset(Expression* ptr = nullptr) {
		delete this->ptr;
		this->ptr = ptr;
	}
	Expression& operator*() const {
		return *ptr;
	}
	Expression* operator->() const {
		return ptr;
	}
	~ScopedPtr() {
		delete ptr;
	}
private:
	Expression* ptr;
};


int main()
{
	std::cout << "hello";
	return 0;
}
