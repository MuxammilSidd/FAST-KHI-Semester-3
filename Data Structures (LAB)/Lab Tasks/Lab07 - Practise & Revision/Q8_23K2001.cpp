//23K2001 - Muzammil
#include <iostream>
using namespace std;

int seqA(int upto){
    if(upto==1)
        return 1;

    return upto+seqA(upto-1);
}
int seqB(int x){
    if(x==0 || x==1)
        return x;

    return seqB(x-1)+seqB(x-2);
}

int main() {
    cout<<"Sequence A:"<<endl;
    seqA(10);
    for(int i=1;i<=10;i++)
        cout<<seqA(i)<<"\t";
    cout<<endl<<endl;
    cout<<"Sequence B:"<<endl;
    for(int i=0;i<10;i++)
        cout<<seqB(i)<<"\t";
    return 0;
}
