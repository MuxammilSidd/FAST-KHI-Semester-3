//23K2001 - Muzammil
#include<iostream>
using namespace std;

void largestToMiddle(int *arr,int n){
	for(int i=1;i<n;i++){
		int key = arr[i];
		int j = i-1;
		
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	int mid = n/2;
    int temp = arr[n-1];
	int j=n-1;
    while(j>mid){
        arr[j] = arr[j - 1];
        j--;
    }
    arr[mid] = temp;
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

	largestToMiddle(m,n);
	cout<<endl<<"After sorting, & largest to middle:"<<endl;
	for(int i=0;i<n;i++)
		cout<<m[i]<<"\t";
	delete[] m;
	return 0;
}