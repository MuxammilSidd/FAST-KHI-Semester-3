//23K2001 - Muzammil
#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void sort(int *arr1,int *arr2,int s1,int s2){
    int index = 0;
    for(int i=0;i<s2;i++){
        int val = arr2[i];
        for (int j=0;j<s1;j++){
            if(val == arr1[j]){
                swap(arr1[index], arr1[j]);
                index++;
            }
        }
    }
}

int main() {
    int n,m;
    cout<<"Enter length of Array#1: ";
    cin>>n;
    int arr1[n];
    cout<<"Input "<<n<<" elements:"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr1[i];
    cout<<"Enter length of Array#2: ";
    cin>>m;
    int arr2[m];
    cout<<"Input "<<m<<" elements:"<<endl;
    for(int i=0;i<m;i++)
        cin>>arr2[i];
    
    cout<<"Array#1:"<<endl;
    for(int i:arr1)
        cout<<i<<"\t";
    cout<<endl<<"Array#2:"<<endl;
    for(int i:arr2)
        cout<<i<<"\t";
    cout<<endl<<endl<<"Array#1 after sorting to Array#2:"<<endl;
    sort(arr1,arr2,n,m);
    for(int i:arr1)
        cout<<i<<"\t";
    return 0;
}
