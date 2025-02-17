#pragma once
class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction();
	Fraction(int num, int den);

	void SetFraction(int num, int den);
	void GetFraction();

	Fraction Sum(Fraction f1, Fraction f2);
	Fraction Sub(Fraction f1, Fraction f2);
	Fraction Multiply(Fraction f1, Fraction f2);
	Fraction Divizion(Fraction f1, Fraction f2);

	void Reduct();
};

