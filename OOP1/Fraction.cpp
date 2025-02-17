#include "Fraction.h"
#include<iostream>
#include<numeric>

using namespace std;

Fraction::Fraction()
{
	numerator = 1;
	denominator = 1;
}

Fraction::Fraction(int num, int den)
{
	numerator = num;
	denominator = den;
	Reduct();
}

void Fraction::SetFraction(int num, int den)
{
	if (num != 0) {
		numerator = num;
	}
	if (den > 0) {
		denominator = den;
	}
	Reduct();
}

void Fraction::GetFraction()
{
	cout << "ִנמבü: " << 
		numerator << 
		'/' << 
		denominator <<
		'\n';
}

Fraction Fraction::Sum(Fraction f1, Fraction f2)
{
	int num;
	int den;
	if (f1.denominator != f2.denominator) {
		den = f1.denominator * f2.denominator;
		num = f1.numerator * f2.denominator +
			f2.numerator * f1.denominator;
	}
	else {
		den = f1.denominator;
		num = f1.numerator + f2.numerator;
	}
	return {num, den};
}

Fraction Fraction::Sub(Fraction f1, Fraction f2)
{
	int num;
	int den;
	if (f1.denominator != f2.denominator) {
		den = f1.denominator * f2.denominator;
		num = f1.numerator * f2.denominator -
			f2.numerator * f1.denominator;
	}
	else {
		den = f1.denominator;
		num = f1.numerator - f2.numerator;
	}
	return { num, den };
}

Fraction Fraction::Multiply(Fraction f1, Fraction f2)
{
	return {f1.numerator * f2.numerator,
		f1.denominator * f2.denominator};
}

Fraction Fraction::Divizion(Fraction f1, Fraction f2)
{
	return { f1.numerator * f2.denominator,
		f1.denominator * f2.numerator };
}

void Fraction::Reduct()
{
	int nod = gcd(numerator, denominator);
	numerator /= nod;
	denominator /= nod;
}
