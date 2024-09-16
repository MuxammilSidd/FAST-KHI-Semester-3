//23K2001 - Muzammil
#include<iostream>
using namespace std;
template<class T>
bool haveDuplicates(T *arr,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j])
            return true;
        }
    }
    return false;
}

int main(){
	int *m = nullptr;
	int n;
	cout<<"How many elements: ";
	cin>>n;
	m = new int[n];
	cout<<"Enter "<<n<<" elements:"<<endl;
	for(int i=0;i<n;i++)
	cin>>m[i];

	cout<<endl<<"Checking for duplicates:"<<endl;
	if(haveDuplicates(m,n)==true)
    cout<<endl<<"inputted array has duplicates."<<endl;
    else
    cout<<endl<<"no duplicates."<<endl;

	for(int i=0;i<n;i++)
	    cout<<m[i]<<"\t";
    delete[] m;
	return 0;
}