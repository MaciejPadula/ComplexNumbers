#include <iostream>
#include <math.h>
#include <string>
#include "fraction.h"

#ifndef COMPLEX_H
#define COMPLEX_H
class Complex{
	private:
		double x,y;
	public:
        Complex(double real);
        Complex(double real, double imaginary);
        static Complex fromExp(double argument, double module){
            return Complex(module*cos(argument), module*sin(argument));
        }
        double real();
        double imaginary();
        double module();
        double argument();
        std::string trigonometricForm();
        std::string exponentialForm();

        Complex pow(int power);
        friend std::ostream& operator<<(std::ostream& os, const Complex& c);
        Complex operator+(Complex b);
        Complex operator-(Complex b);
        Complex operator*(Complex b);
        Complex operator/(Complex b);


        friend Complex operator+(double real, const Complex& complex);
        friend Complex operator*(double real, Complex& complex);
};
#endif
