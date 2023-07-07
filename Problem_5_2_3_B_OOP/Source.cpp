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
	void add(const int number);
	void sub(Rational number);
	void sub(const int number);
	void mul(Rational number);
	void mul(const int number);
	void div(Rational number);
	void div(const int number);
	Rational operator+() const;
	Rational operator-() const;
	Rational& operator+=(const Rational& another);
	Rational& operator+=(const int another);
	Rational& operator-=(const Rational& another);
	Rational& operator-=(const int another);
	Rational& operator*=(const Rational& another);
	Rational& operator*=(const int another);
	Rational& operator/=(const Rational& another);
	Rational& operator/=(const int another);
	int gcd(int a, int b);
	void neg() { numerator_ = -numerator_; };
};

int Rational::gcd(int a, int b) {
	a = std::abs(a);
	b = std::abs(b);
	int ost = 1;
	if (a > b)
		std::swap(a, b);
	while (ost != 0) {
		ost = b % a;
		b = a;
		a = ost;
	}
	return b;
}


void Rational::add(Rational number) {
	numerator_ = numerator_ * number.denominator_ + number.numerator_ * denominator_;
	denominator_ = denominator_ * number.denominator_;
	int del = gcd(numerator_, denominator_);
	numerator_ = numerator_ / del;
	denominator_ = denominator_ / del;
}

void Rational::add(const int number) {
	numerator_ = numerator_ + denominator_ * number;
	denominator_ = denominator_ * number;
	int del = gcd(numerator_, denominator_);
	numerator_ = numerator_ / del;
	denominator_ = denominator_ / del;
}

void Rational::sub(Rational number) {
	numerator_ = numerator_ * number.denominator_ - number.numerator_ * denominator_;
	denominator_ = denominator_ * number.denominator_;
	int del = gcd(numerator_, denominator_);
	numerator_ = numerator_ / del;
	denominator_ = denominator_ / del;
}

void Rational::sub(const int number) {
	numerator_ = numerator_ - number * denominator_;
	denominator_ = denominator_ *number;
	int del = gcd(numerator_, denominator_);
	numerator_ = numerator_ / del;
	denominator_ = denominator_ / del;
}

void Rational::mul(Rational number) {
	numerator_ = numerator_ * number.numerator_;
	denominator_ = denominator_ * number.denominator_;
	int del = gcd(numerator_, denominator_);
	numerator_ = numerator_ / del;
	denominator_ = denominator_ / del;
}

void Rational::mul(const int number) {
	numerator_ = numerator_ * number;
	int del = gcd(numerator_, denominator_);
	numerator_ = numerator_ / del;
	denominator_ = denominator_ / del;
}

void Rational::div(Rational number) {
	numerator_ = numerator_ * number.denominator_;
	denominator_ = denominator_ * number.numerator_;
	int del = gcd(numerator_, denominator_);
	numerator_ = numerator_ / del;
	denominator_ = denominator_ / del;
}

void Rational::div(const int number) {
	denominator_ = denominator_ * number;
	int del = gcd(numerator_, denominator_);
	numerator_ = numerator_ / del;
	denominator_ = denominator_ / del;
}

Rational Rational::operator+() const {
	Rational number(this->numerator_, this->denominator_);
	return number;
}

Rational Rational::operator-() const {
	Rational number(this->numerator_, this->denominator_);
	number.neg();
	return number;
}

Rational& Rational::operator+=(const Rational& another) {
	this->add(another);
	return *this;
}

Rational& Rational::operator+=(const int another) {
	this->add(another);
	return *this;
}

Rational& Rational::operator-=(const Rational& another) {
	this->sub(another);
	return *this;
}

Rational& Rational::operator-=(const int another) {
	this->sub(another);
	return *this;
}

Rational& Rational::operator*=(const Rational& another) {
	this->mul(another);
	return *this;
}

Rational& Rational::operator*=(const int another) {
	this->mul(another);
	return *this;
}

Rational& Rational::operator /=(const Rational& another) {
	this->div(another);
	return *this;
}

Rational& Rational::operator /=(const int another) {
	this->div(another);
		return *this;
}










int main() {
	std::cout << "HELLO!" << std::endl;
	Rational number1(5, 2);
	Rational number2(7, 2);
	int a = 4;
	// number1.add(number2);
	// number1.sub(number2);
	// number1.mul(number2);
	//number1.div(number2);
	//number1 += number2;
	number1 += number2;
	std::cout << "Numerator_ of number1 : " << number1.numerator_ << std::endl;
	std::cout << "Denominator_ of number1 : " << number1.denominator_ << std::endl;
	return 0;
}