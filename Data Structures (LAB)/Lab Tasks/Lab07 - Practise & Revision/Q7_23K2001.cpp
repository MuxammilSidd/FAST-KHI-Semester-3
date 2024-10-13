//23K2001 - Muzammil
#include <iostream>
using namespace std;

void print(int i,int upto){
    if(i<=upto){
        if(i%2==0)
            cout<<i-1;
        else
            cout<<i+1;
    }
    else
        return;
    i++;
    cout<<"\t";
    print(i,upto);
}

int main(){
    print(1,10);
    return 0;
}
