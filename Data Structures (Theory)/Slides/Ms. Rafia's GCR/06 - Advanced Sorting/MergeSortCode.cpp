#include<iostream>

using namespace std;

void merge(int array[], int low,int mid, int high){
	int i=low, j=mid+1, k=0; 
	int* temp=new int[high - low + 1];

	while(i<=mid && j<=high){
		if(array[i]<=array[j]){
			temp[k]=array[i];
			i++;
		}
		else{
			temp[k]=array[j];
			j++;
		}
		k++;
	}
	//copy remaining data from array 
	while(i<=mid){
		temp[k]=array[i];
		i++;
		k++;
	}
	while(j<=high){
		temp[k]=array[j];
		j++;
		k++;
	}

	for(int index=0; index<k; index++){
		array[low+index]=temp[index];
	}

	delete[] temp;
}
void mergeSort(int array[], int low, int high){
	if(low>=high) return;
	int mid=low+(high-low)/2;
	mergeSort(array, low, mid);
	mergeSort(array, mid+1, high);
	merge(array, low, mid, high);
}

void printArray(int arr[], int size){
	for(int i=0; i<size; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int arrayTest[]={4,11,1,6,12,44,1,9};
	int size=sizeof(arrayTest)/sizeof(arrayTest[0]);
	cout<<"Original array\n";
	printArray(arrayTest, size);
	mergeSort(arrayTest, 0, size-1);
	cout<<"Sorted array\n";
	printArray(arrayTest, size);
	return 0;
}