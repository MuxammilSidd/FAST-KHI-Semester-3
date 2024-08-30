//23K2001 - Muzammil
#include<iostream>
using namespace std;
int main(){
    int *num;
    num = new int[6];
    for(int i=0,j=0;i<6;i++,j+=2)
    num[i]=j;

    cout<<"Base Address: "<<num<<" Value: "<<*num<<endl;
    for(int i=1;i<6;i++)
    cout<<"Address: "<<num+i<<" Value: "<<num[i]<<endl;

    num[3] = 2001;
    cout<<"3rd Index Address: "<<num+3<<" Value: "<<num[3]<<endl;

    delete[] num;

    return 0;
}