//23K2001 - Muzammil
#include<iostream>
using namespace std;

void sortYear(int *arr,int n){
	for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
	int *m = nullptr;
	int n;
	cout<<"How many children: ";
	cin>>n;
	m = new int[n];
	cout<<"Enter "<<n<<" birth years:"<<endl;
	for(int i=0;i<n;i++)
	cin>>m[i];

    sortYear(m,n);
	cout<<endl<<"After sorting:"<<endl;
	for(int i=0;i<n;i++)
		cout<<m[i]<<"\t";
	delete[] m;
	return 0;
}