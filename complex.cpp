#include "complex.h"
#include "fraction.h"
#include <cmath>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

Complex::Complex(double real){
    x=real;
    y=0;
}
Complex::Complex(double real, double imaginary){
	x=real;
	y=imaginary;
}
Complex::Complex(short form, double argument, double module){
    x=module*cos(argument);
    y=module*sin(argument);
}
double Complex::real(){
	return x;
}
double Complex::imaginary(){
	return y;
}
double Complex::module(){
	return sqrt(x*x+y*y);
}
double Complex::argument(){
    if(x!=0) {
        double fi=atan(y/x);
        if(x<0 && y<0) fi-=M_PI;
        if(x<0 && y>=0) fi+=M_PI;
        return fi;
    }
    return 0;
}
std::string Complex::trigonometricForm(){
	Fraction arg(argument()/3.14);
	std::string out="";
	if(module()!=1){
		out+=patch::to_string(Fraction(module()).getString())+"(";
	}
	if(cos(argument())<0){
		out+="-";
	}
	out+="cos(pi*"+arg.getString()+")";
	if(sin(argument())<0){
		out+="-";
	}
	else{
		out+="+";
	}
	out+="i*sin(pi*"+arg.getString()+")";
	if(module()!=1){
		out+=")";
	}
	return out;
}
std::string Complex::exponentialForm(){
	Fraction arg(argument()/3.14);
	std::string out="";
	if(module()!=1){
		out+=patch::to_string(Fraction(module()).getString())+"*";
	}
	out+="exp(i*pi*"+patch::to_string(arg)+")";
	return out;
}

Complex Complex::pow(int power){
    return Complex(1,argument()*power,std::pow(module(),power));
}

std::ostream& operator<<(std::ostream& os, const Complex& c){
	os<<Fraction::roundoff(c.x,2);
	if(c.y>=0){
		os<<"+";
		if(c.y!=1){
			os<<Fraction::roundoff(c.y,2);
		}
	}
	else{
		os<<"-";
		if(c.y!=-1){
			os<<Fraction::roundoff(-1*c.y,2);
		}
	}
	os<<"i";
	return os;
}

Complex Complex::operator+(Complex b){
    b.x+=x;
    b.y+=y;
    return b;
}
Complex Complex::operator-(Complex b){
    b.x=x-b.x;
    b.y=y-b.y;
    return b;
}
Complex Complex::operator*(Complex b){
    Complex out(1,b.argument()+argument(),b.module()*module());
    return out;
}
Complex Complex::operator/(Complex b){
    Complex out(1,argument()-b.argument(),module()/b.module());
    return out;
}

Complex operator+(double real, const Complex& complex){
    return Complex(real,0)+complex;
}
Complex operator*(double real, Complex& complex){
    Complex r(real);
    return Complex(1,r.argument()+complex.argument(),r.module()*complex.module());
}

