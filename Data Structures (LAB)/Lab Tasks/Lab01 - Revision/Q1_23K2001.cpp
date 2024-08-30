//23K2001 - Muzammil
#include<iostream>
using namespace std;

class bankAccount{
    private:
    float balance;
    public:
    bankAccount() { balance = 0.0; }
    bankAccount(float b){ balance = b; }
    float display(){ return balance; }
    void deduct(float x){ balance-=x; }
};

int main(){
    bankAccount account1;
    cout<<"Acc#1: "<<account1.display()<<endl;
    bankAccount account2(1000);
    cout<<"Acc#2: "<<account2.display()<<endl;

    bankAccount account3(account2);
    account3.deduct(200);
    cout<<"Acc#3: "<<account3.display()<<endl;
    cout<<"Acc#2: "<<account2.display()<<endl;
    return 0;
}