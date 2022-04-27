#include <iostream>
#include "complex.h"

using namespace std;
int main(){
	Complex z1(2,-2);
	Complex z2(5,-2);
    cout<<Complex::fromExp(0.25*M_PI, sqrt(2));
	return 0;
}
