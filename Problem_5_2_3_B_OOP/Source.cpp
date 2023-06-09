#include <iostream>

struct Rational {
// private:
	int numerator_;
	int denominator_;
// public:
	Rational(int numerator_ = 0, int denominator_ = 1) : numerator_(numerator_), denominator_(denominator_) {
		std::cout << "The constructor volunteered" << std::endl;
	}
	~Rational() {
		std::cout << "The destructor volunteered" << std::endl;
	}
	void add(Rational number);
};


void Rational::add(Rational number) {
	int temp_numerator = number.numerator_;
	int temp_denominator = number.denominator_;
	number.numerator_ = number.numerator_ * denominator_;
	number.denominator_ = number.denominator_ * denominator_;
	numerator_ = numerator_ * number.denominator_;
	denominator_ = denominator_ * number.denominator_;
}

int main() {
	std::cout << "HELLO!" << std::endl;
	Rational number1(3, 2);
	Rational number2(7, 2);
	number1.add(number2);
	std::cout << "Numerator_ of number1 : " << number1.numerator_ << std::endl;
	std::cout << "Denominator_ of number1 : " << number1.denominator_ << std::endl;
	return 0;
}