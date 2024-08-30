//23K2001 - Muzammil
#include<iostream>
using namespace std;

int main(){
    float **gpa;
    gpa = new float*[4];
    //CS - SE - AI - DS
    gpa[0] = new float[2];
    gpa[1] = new float[3];
    gpa[2] = new float[4];
    gpa[3] = new float[1];

    for(int i=0;i<2;i++)
    gpa[0][i] = 3.6;
    
    for(int i=0;i<3;i++)
    gpa[1][i] = 3.3;

    for(int i=0;i<4;i++)
    gpa[2][i] = 4.0;

    for(int i=0;i<1;i++)
    gpa[3][i] = 2.6;

    cout<<"\tGPA: "<<endl;

    cout<<"CS: "<<endl;
    for(int i=0;i<2;i++)
        cout<<gpa[0][i]<<"\t";

    cout<<"\n\n"<<"SE: "<<endl;
    for(int i=0;i<3;i++)
        cout<<gpa[1][i]<<"\t";

    cout<<"\n\n"<<"AI: "<<endl;
    for(int i=0;i<4;i++)
        cout<<gpa[2][i]<<"\t";
    
    cout<<"\n\n"<<"DS: "<<endl;
    for(int i=0;i<1;i++)
        cout<<gpa[3][i]<<"\t";

    for(int i=0;i<4;i++){
        delete[] gpa[i];
    }

    delete[] gpa;
    return 0;
}