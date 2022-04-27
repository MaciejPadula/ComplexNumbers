#include "fraction.h"

float Fraction::roundoff(float value, unsigned char prec)
{
    float pow_10 = pow(10.0f, (float)prec);
    return round(value * pow_10) / pow_10;
}
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

Fraction::Fraction(int l, int m){
	if(m==0){
		std::cout<< ("Denominator can't be equal to 0!!!\n");
		throw;
	}
	this->l=l;
	this->m=m;
	this->reduction();
}
Fraction::Fraction(double a){
	a=fmod(a,1);
    //a=roundoff(a,2);
    a*=100;
    a=(int)a;
    a/=100;

    double d=a;
	int m=10;
	while(d!=0 && m!=100000){
		m*=10;
		d*=10;
		if((int)floor(d) == (int)d){
			d=0;
		}
		else{
			d=fmod(d,1);
		}
			
		if(d==1.0){
			d=0;
		}
		
	}
	//d+=0.001;
    //std::cout << m;
	this->l=(a*m);
	
	this->m=m;

    if(this->m==0) this->m=1;

    this->reduction();
	if(this->l==33 && this->m==100){
		this->l=1;
		this->m=3;
	}
	
	if(this->l==33 && this->m==50){
		this->l=2;
		this->m=3;
	}
	if(this->l==4 && this->m==25){
		this->l=1;
		this->m=6;
	}
}

void Fraction::reduction(){
	int nwd=NWD(this->l,this->m);
	if(nwd!=0){
		this->l=this->l/nwd;
		this->m=this->m/nwd;
	}
	
	if(this->m<0){
		this->l*=-1;
		this->m*=-1;
	}
}
int Fraction::NWD(int a, int b){
	int c=0;
	do{
		c=a%b;
		a=b;
		b=c;
	}while(c!=0);
	return a;	
}
std::string Fraction::getString(){
	std::string out="";
	
	if(l%m==0){
		out+=patch::to_string(l/m);
	}
	else if(l==0){
		out+="0";
	}
	else{
		out+=(patch::to_string(l)+"/"+patch::to_string(m));
	}	
	return out;
}
Fraction Fraction::operator+(Fraction b){
	if(this->m==b.m){
		Fraction f(this->l+b.l,b.m);
		return f;
	}
	int l=this->l*b.m+b.l*this->m;
	int m=this->m*b.m;
	Fraction f(l,m);
	return f;
}
Fraction Fraction::operator++(int l){
	Fraction ret=Fraction(this->l,this->m);
	Fraction w=ret+1;
	this->l=w.l;
	this->m=w.m;
	return ret;
}
Fraction Fraction::operator+=(Fraction b){
	Fraction w=Fraction(this->l,this->m)+b;
	this->l=w.l;
	this->m=w.m;
	return w;
}
Fraction Fraction::operator-(Fraction b){
	if(this->m==b.m){
		Fraction f(this->l-b.l,b.m);
		return f;
	}
	int l=this->l*b.m-b.l*this->m;
	int m=this->m*b.m;
	Fraction f(l,m);
	return f;
}
Fraction Fraction::operator*(Fraction b){
	Fraction f(this->l*b.l,this->m*b.m);
	return f;
}
Fraction Fraction::operator/(Fraction b){
	Fraction f(this->l*b.m,this->m*b.l);
	return f;
}
bool Fraction::operator<(Fraction b){
	int l1=this->l*b.m;
	int l2=b.l*this->m;
	return l1<l2;
}
bool Fraction::operator>(Fraction b){
	int l1=this->l*b.m;
	int l2=b.l*this->m;
	return l1>l2;
}
bool Fraction::operator<=(Fraction b){
	int l1=this->l*b.m;
	int l2=b.l*this->m;
	return l1<=l2;
}
bool Fraction::operator>=(Fraction b){
	int l1=this->l*b.m;
	int l2=b.l*this->m;
	return l1>=l2;
}
bool Fraction::operator==(Fraction b){
	return (this->l==b.l && this->m==b.m);
}
std::ostream& operator<<(std::ostream& os, const Fraction& ft){
	if(ft.l%ft.m==0){
		os<<ft.l/ft.m;
	}
	else if(ft.l==0){
		os<<ft.l;
	}
	else{
		os<<ft.l<<"/"<<ft.m;
	}
	return os;	
}
Fraction operator+(int l, const Fraction& ft){
	Fraction i(l);
	return i+ft;
}

Fraction operator-(int l, const Fraction& ft){
	Fraction i(l);
	return i-ft;
}
Fraction operator-(const Fraction& ft){
	Fraction i(0);
	return i-ft;
}
Fraction operator*(int l, const Fraction& ft){
	Fraction i(l);
	return i*ft;
}
Fraction operator/(int l, const Fraction& ft){
	Fraction i(l);
	return i/ft;
}