#include <iostream>
using namespace std;

void swap(int &a, int &b){
	int temp=a;
	a=b;
	b=temp;
}
//find pivot element index number or partition index
int findPivotIndex(int A[], int low, int high){
	int i=low, j=high;
	int pivot=A[low];
	while(i<j){
		while(A[i]<=pivot && i<=high-1){
			i++;
		}
		while(A[j]>pivot && j>=low+1){
			j--;
		}
		if(i<j)
			swap(A[i], A[j]);
	}

	swap(A[low], A[j]);
	return j;
}

void quickSort(int A[], int low, int high){
	//base condition
	if(low<high){
		int pivotPos=findPivotIndex(A, low, high);
		quickSort(A,low, pivotPos-1);
		quickSort(A, pivotPos+1, high);

	}
}

void printArray(int A[], int size){
	for(int index=0; index<size; index++)
		cout<<A[index]<<" ";
	cout<<endl;
}
int main(){
	int A[]={3,4,7,1,66,0,2,10,11};
	int size=sizeof(A)/sizeof(A[0]);
	cout<<"Original Array : \n";
	printArray(A,size);
	//quick sort
	quickSort(A,0,size-1);
	cout<<"After quick sort Array : \n";
	printArray(A,size);

	return 0;
}