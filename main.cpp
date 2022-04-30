#include <iostream>
#include "complex.h"

using namespace std;
int main(){
	Complex z1(2,-2);
	Complex z2(5,-2);
    cout<<z1.exponentialForm()<<endl;
    cout<<z2.exponentialForm()<<endl;
    cout<<(z1-z2)<<endl;
	return 0;
}
