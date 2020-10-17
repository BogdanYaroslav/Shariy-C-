#include "Fraction.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

int  Fraction::counter=0;



Fraction::Fraction() {
	numerator_ = 1;
	denominator_ = 1;
	counter++;


}

Fraction::Fraction(const int num1, const int num2) :numerator_(num1), denominator_(num2) { 
	counter++; 
}

Fraction::~Fraction() { counter--;
}

void Fraction::setNumerator(const int num) {
	numerator_ = num;
}
void Fraction::setDenomirator(const int num) {
	denominator_ = num;
}
int Fraction::getDenomirator()const {
	return denominator_;
}
int Fraction::getNumerator()const {
	return numerator_;
}

Fraction Fraction::operator+(Fraction& num) {

	cout << "(" << this->numerator_ << "/" << this->denominator_ << ") + (" << num.numerator_ << "/" << num.denominator_ << ") = ";
	Fraction res(this->numerator_ * num.denominator_ + this->denominator_ * num.numerator_, this->denominator_ * num.denominator_);
	res.reduce();
	counter++;
	return res;
}

Fraction Fraction::operator-(Fraction& num) {
	cout << "(" << this->numerator_ << "/" << this->denominator_ << ") - (" << num.numerator_ << "/" << num.denominator_ << ") = ";
	Fraction res(this->numerator_ * num.denominator_ - this->denominator_ * num.numerator_, this->denominator_ * num.denominator_);
	res.reduce();
	counter++;
	return res;
}

Fraction Fraction::operator*(Fraction& num) {
	cout << "(" << this->numerator_ << "/" << this->denominator_ << ") * (" << num.numerator_ << "/" << num.denominator_ << ") = ";
	Fraction res(this->numerator_ * num.numerator_, this->denominator_ * num.denominator_);
	res.reduce();
	counter++;
	return res;
}

Fraction Fraction::operator/(Fraction& num) {
	cout << "(" << this->numerator_ << "/" << this->denominator_ << ") / (" << num.numerator_ << "/" << num.denominator_ << ") = ";
	Fraction res(this->numerator_ * num.denominator_, this->denominator_ * num.numerator_);
	res.reduce();
	counter++;
	return res;
}

void Fraction::reduce() {

	if (numerator_ == 0) {
		cout  << numerator_ << endl<<endl;
		return;
	}
	else if(denominator_==0)
	{
		cout  << "На ноль делить нельзя " << endl << endl;
		return;
	}
	else
	{
		int NOD = gcd(abs(numerator_), abs(denominator_));

		cout << numerator_ << "/" << denominator_ <<" = ";
		numerator_ /= NOD;
		denominator_ /= NOD;

		cout << numerator_ << "/" << denominator_ << endl << endl;
	}
}

void Fraction::printAsFraction(double decimal)
{
	cout << decimal << " = ";

	int i = 1;//знаменатель

	int tmp = (int)(decimal * 10);

	while (tmp == 0)
	{
		decimal *= 10;
		i *= 10;
		tmp = (int)(decimal * 10);
	}


	while ((int)(decimal * 10) % 10 != 0)
	{
		
		decimal *= 10;//числитель
		i *= 10;//знаменатель
	}

	Fraction res((int)decimal, i);
	res.reduce();
	counter++;
}

void Fraction::printAsFraction( char* decimal) {

	cout << decimal << " = ";

	char* dot = strchr(decimal,'.');
	dot++;

	int count = 0;
	while (*dot!='\0')
	{
		count++;
		dot++;
	}

	double num = atof(decimal);
	int denom = 1;

	for (int i = 0; i < count; i++) {
		num *= 10;
		denom *= 10;
	}

	Fraction res((int)num,denom);
	res.reduce();
	counter++;
}



int Fraction::gcd(int a, int b) {

	while (a != 0 && b != 0) {
		if (a > b) {
			a = a % b;
		}
		else
		{
			b = b % a;
		}
	}
	return  (a + b);
}