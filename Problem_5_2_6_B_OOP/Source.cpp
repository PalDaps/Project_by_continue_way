#include <iostream>

struct Rational {
	//	private:
	int numerator_;
	int denominator_;
	//	public:
	Rational(int numerator_ = 0, int denominator_ = 1) : numerator_(numerator_), denominator_(denominator_) {
		std::cout << "The constructor volunteered" << std::endl;
	}
	~Rational() {
		std::cout << "The destructor volunteered" << std::endl;
	}
	//	Is it possible to halve the code below? I don't know yet
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
	friend bool operator==(const Rational& left, const Rational& right);
	friend bool operator<(const Rational& left, const Rational& right);
	//	Rational& operator+=(const Rational& another);
	//	Rational& operator+=(const int another);
	//	Rational& operator-=(const Rational& another);
	//	Rational& operator-=(const int another);
	//	Rational& operator*=(const Rational& another);
	//	Rational& operator*=(const int another);
	//	Rational& operator/=(const Rational& another);
	//	Rational& operator/=(const int another);
	int gcd(int a, int b);
	void neg() { numerator_ = -numerator_; };
	void inv() { std::swap(numerator_, denominator_); };
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
	denominator_ = denominator_ * number;
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
//
//Rational& Rational::operator+=(const Rational& another) {
//	this->add(another);
//	return *this;
//}
//
//Rational& Rational::operator+=(const int another) {
//	this->add(another);
//	return *this;
//}
//
//Rational& Rational::operator-=(const Rational& another) {
//	this->sub(another);
//	return *this;
//}
//
//Rational& Rational::operator-=(const int another) {
//	this->sub(another);
//	return *this;
//}
//
//Rational& Rational::operator*=(const Rational& another) {
//	this->mul(another);
//	return *this;
//}
//
//Rational& Rational::operator*=(const int another) {
//	this->mul(another);
//	return *this;
//}
//
//Rational& Rational::operator /=(const Rational& another) {
//	this->div(another);
//	return *this;
//}
//
//Rational& Rational::operator /=(const int another) {
//	this->div(another);
//	return *this;
//}

// In theory, all of the above can be replaced with four operators
// 8 : 42 PM
// 7 / 23 / 2023 
// Its a magic

Rational& operator+=(Rational& left, const Rational& right) {
	left.add(right);
	return left;
}

Rational& operator-=(Rational& left, const Rational& right) {
	left.sub(right);
	return left;
}

Rational& operator*=(Rational& left, const Rational& right) {
	left.mul(right);
	return left;
}

Rational& operator/=(Rational& left, const Rational& right) {
	left.div(right);
	return left;
}

//Rational operator+(const Rational& left, int right) {
//	Rational res = left;
//	return res += right;
//}
//
//Rational operator+(int left, const Rational& right) {
//	Rational res = right;
//	return res += left;
//}
//
//Rational operator+(const Rational& left, const Rational& right) {
//	Rational res_left = left;
//	Rational res_right = right;
//	return res_left += res_right;
//}
//
//Rational operator-(const Rational& left, int right) {
//	Rational res = left;
//	return res -= right;
//}
//
//Rational operator-(int left, const Rational& right) {
//	Rational res = right;
//	res.neg();
//	return res += left;
//}
//
//Rational operator-(const Rational& left, const Rational& right) {
//	Rational res_left = left;
//	Rational res_right = right;
//	return res_left -= res_right;
//}
//
//Rational operator*(const Rational& left, int right) {
//	Rational res = left;
//	return res *= right;
//}
//
//Rational operator*(int left, const Rational& right) {
//	Rational res = right;
//	return res *= left;
//}
//
//Rational operator*(const Rational& left, const Rational& right) {
//	Rational res_left = left;
//	Rational res_right = right;
//	return res_left *= res_right;
//}
//
//Rational operator/(const Rational& left, int right) {
//	Rational res = left;
//	return res /= right;
//}
//
//Rational operator/(int left, const Rational& right) {
//	Rational res = right;
//	res.inv();
//	return res *= left;
//}
//
//Rational operator/(const Rational& left, const Rational& right) {
//	Rational res_left = left;
//	Rational res_right = right;
//	return res_left /= res_right;
//}

// In theory, all of the above can be replaced with four operators
// 8 : 28 PM
// 7 / 23 / 2023 
// Its a magic

Rational operator+(Rational left, const Rational& right) {
	return left += right;
}

Rational operator-(Rational left, const Rational& right) {
	return left -= right;
}

Rational operator*(Rational left, const Rational& right) {
	return left *= right;
}

Rational operator/(Rational left, const Rational& right) {
	return left /= right;
}

// 10 : 42 PM / Comparison operators
// 7 / 23 / 2023 

bool operator==(const Rational& left, const Rational& right) {
	return left.numerator_ == right.numerator_ && right.denominator_ == left.denominator_;
}

bool operator!=(const Rational& left, const Rational& right) {
	return !(left == right);
}

bool operator<(const Rational& left, const Rational& right) {
	return left.numerator_ * right.denominator_ < right.numerator_* left.denominator_;
}

bool operator>(const Rational& left, const Rational& right) {
	return right < left;
}

bool operator<=(const Rational& left, const Rational& right) {
	return !(right < left);
}

bool operator>=(const Rational& left, const Rational& right) {
	return !(left < right);
}

int main() {
	std::cout << "HELLO!" << std::endl;
	// Rational number1(1, 2);
	Rational number2(1, 1);
	Rational number3(5, 2);
	int a = 4;
	//  number1.add(5);
	//	number1.sub(number2);
	//	number1.mul(number2);
	//	number1.div(number2);
	//	number1 += number2;
	//Rational number1 = 12 + 13;
	//std::cout << "Numerator_ of number1 : " << number1.numerator_ << std::endl;
	//std::cout << "Denominator_ of number1 : " << number1.denominator_ << std::endl;

	//bool res_eq = (2 == number2);
	//std::cout << res_eq << std::endl;

	//bool res_le = (1 < number3);
	//std::cout << res_le << std::endl;
	
	return 0;
}
