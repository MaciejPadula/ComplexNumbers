#ifndef FRACTION_H
#define FRACTION_H

#include <math.h>
#include <iostream>
#include <sstream>
class Fraction{
	private:
		int l,m;
	public:

		Fraction(int l,int m);
		Fraction(double a);
		friend std::ostream& operator<<(std::ostream& os, const Fraction& ft);
		Fraction operator+(Fraction b);
		Fraction operator++(int l);
		Fraction operator+=(Fraction b);
		Fraction operator-(Fraction b);
		Fraction operator*(Fraction b);
		Fraction operator/(Fraction b);
		bool operator<(Fraction b);
		bool operator>(Fraction b);
		bool operator<=(Fraction b);
		bool operator>=(Fraction b);
		bool operator==(Fraction b);
		void reduction();
		int odwr(int l);
		int NWD(int a, int b);
		std::string getString();
		friend Fraction operator+(int l, const Fraction& ft);
		friend Fraction operator-(int l, const Fraction& ft);
		friend Fraction operator*(int l, const Fraction& ft);
		friend Fraction operator/(int l, const Fraction& ft);

		friend Fraction operator-(const Fraction& ft);

        static float roundoff(float value, unsigned char prec);
};
#endif
