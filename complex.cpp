#include "complex.h"
#include <cmath>
#include <sstream>

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
	std::string out="";
	if(module()!=1){
		out+=patch::to_string(module())+"(";
	}
	if(cos(argument())<0){
		out+="-";
	}
	out+="cos(pi*"+patch::to_string(argument()/3.14)+")";
	if(sin(argument())<0){
		out+="-";
	}
	else{
		out+="+";
	}
	out+="i*sin(pi*"+patch::to_string(argument()/3.14)+")";
	if(module()!=1){
		out+=")";
	}
	return out;
}
std::string Complex::exponentialForm(){
	std::string out="";
	if(module()!=1){
		out+=patch::to_string(module())+"*";
	}
	out+="exp(i*pi*"+patch::to_string(argument()/3.14)+")";
	return out;
}

Complex Complex::pow(int power){
    return fromExp(argument()*power,std::pow(module(),power));
}

std::ostream& operator<<(std::ostream& os, const Complex& c){
	os<<c.x;
	if(c.y>=0){
		os<<"+";
		if(c.y!=1){
			os<<c.y;
		}
	}
	else{
		os<<"-";
		if(c.y!=-1){
			os<<-1*c.y;
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
    return Complex::fromExp(b.argument()+argument(),b.module()*module());
}
Complex Complex::operator/(Complex b){
    return Complex::fromExp(argument()-b.argument(),module()/b.module());
}

Complex operator+(double real, const Complex& complex){
    return Complex(real,0)+complex;
}
Complex operator*(double real, Complex& complex){
    Complex r(real);
    return Complex::fromExp(r.argument()+complex.argument(),r.module()*complex.module());
}

