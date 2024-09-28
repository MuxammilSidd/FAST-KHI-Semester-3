//23K2001 - Muzammil
#include<iostream>
using namespace std;

int recursiveArraySum(int *arr[],int *sizes,int dim){
    if(dim==0)
        return 0;
    if(sizes[dim-1]==0)
        return recursiveArraySum(arr,sizes,dim-1);

    return (arr[dim-1][--sizes[dim-1]])+recursiveArraySum(arr,sizes,dim);
}
int main(){
    int **flex;
    flex = new int*[4];
    flex[0] = new int[2];
    flex[1] = new int[3];
    flex[2] = new int[4];
    flex[3] = new int[1];

    for(int i=0;i<2;i++)
    flex[0][i] = 3;
    
    for(int i=0;i<3;i++)
    flex[1][i] = 2;

    for(int i=0;i<4;i++)
    flex[2][i] = 4;

    for(int i=0;i<1;i++)
    flex[3][i] = 8;

    int sizes[] = {2,3,4,1};
    cout<<"Sum of all elements: "<<recursiveArraySum(flex,sizes,4);
    for(int i=0;i<4;i++)
        delete[] flex[i];
    delete[] flex;
    return 0;
}