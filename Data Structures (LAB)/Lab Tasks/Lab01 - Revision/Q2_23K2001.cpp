//23K2001 - Muzammil
#include<iostream>
using namespace std;

class Exam{
    private:
    string name,date;
    char score;
    public:
    void setRecord(string n,string d,char s){ name=n; 
    date = d;
    score = s;
    }
    void examDetails(){
        cout<<"Name: "<<name<<endl;
        cout<<"Date: "<<date<<endl;
        cout<<"Score: "<<score<<endl;
    }
};

int main(){
    Exam e1;
    e1.setRecord("Muzammil","23-Aug-2024",'A');
    e1.examDetails();

    cout<<endl;
    Exam e2 = e1;
    e2.examDetails();

    cout<<endl;
    e1.setRecord("Muzammil","27-Feb-2024",'B');
    e1.examDetails();
    
    cout<<endl;
    e2.examDetails();

    return 0;
}
//If we do not implement our own copy constructor then the objects will use the same memory
//because of this issue, when object destructor is called, it will destruct the same object 
//twice that can problem with program. If we change some record then it does not reflect in the copied object
//This was due to shallow copy constructor, it can be solved by making deep copy constructor that allocates separate memory
//for the new object that is created. So no issues will be encountered in pointers and dynamic attributes however
//in our question there are no dynamic memories..