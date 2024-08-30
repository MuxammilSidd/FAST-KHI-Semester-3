//23K2001 - Muzammil
#include<iostream>
#include "Q3MatrixMultiply.h"
using namespace std;

void display(int **mat,int rows,int cols){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++)
            cout<<mat[i][j]<<"  ";

            cout<<endl;
        }
        cout<<endl;
    }

int main(){
    int **M = new int*[3];
    for(int i=0;i<3;i++)
    M[i] = new int[2];

    int **N = new int*[2];
    for(int i=0;i<2;i++)
    N[i] = new int[3];

    for(int i=0;i<3;i++)
        for(int j=0;j<2;j++)
            M[i][j] = j+1;
    
    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++)
            N[i][j] = j+2;

    int r = 0, c = 0;
    int **output = multiplyArrays(M,N,3,2,2,3,r,c);

    cout<<"Matrix#1:"<<endl;
    display(M,3,2);
    cout<<"Matrix#2:"<<endl;
    display(N,2,3);
    cout<<"Result:"<<endl;
    display(output,r,c);
    
    for(int i=0;i<3;i++)
        delete[] M[i];
    delete[] M;
    
    for(int i=0;i<2;i++)
        delete[] N[i];
    delete[] N;

    for(int i=0;i<r;i++)
        delete[] output[i];
    delete[] output;

    return 0;
}