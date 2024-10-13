//23K2001 - Muzammil
#include <iostream>
using namespace std;

bool checkPrime(int x,int i=2){
    if(x<2)
        return false;
    if(i*i>x)
        return true;
    if(x%i==0)
        return false;

    return checkPrime(x,i+1);
}
void composite_primes(int m, int n) {
    if(m>n) return;
    if(checkPrime(m))
        cout<<m<<"(P)"<<endl;
    else if(m>1)
        cout<<m<<"(C)"<<endl;
    else
        cout<<m<<"(Neither)"<<endl;
    composite_primes(m + 1, n);
}
int main() {
    composite_primes(0,15);
    return 0;
}
