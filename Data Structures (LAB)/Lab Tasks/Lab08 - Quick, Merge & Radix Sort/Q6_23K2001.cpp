//23K2001 - Muzammil
#include<iostream>
using namespace std;

int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max;
}  
  
void countingSort(int a[], int n, int place){  
  int output[n + 1];  
  int count[10] = {0};    

  for (int i = 0; i < n; i++)  
    count[(a[i] / place) % 10]++;  

  for (int i = 1; i < 10; i++)  
    count[i] += count[i - 1];  

  for (int i = n - 1; i >= 0; i--){  
    output[count[(a[i] / place) % 10] - 1] = a[i];  
    count[(a[i] / place) % 10]--;  
  }  
  
  for (int i = 0; i < n; i++)  
    a[i] = output[i];  
}  

void radixsort(int a[], int n){  
  int max = getMax(a, n);  

  for (int place = 1; max / place > 0; place *= 10)  
    countingSort(a, n, place);  
}

void merge(int a[], int beg, int mid, int end){    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2];
    for (int i = 0; i < n1; i++)    
        LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
        RightArray[j] = a[mid + 1 + j];    
      
    i = 0;
    j = 0;  
    k = beg;
    while (i < n1 && j < n2){    
        if(LeftArray[i] <= RightArray[j]){    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else{    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1){    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2){    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
  
void mergeSort(int a[], int beg, int end){  
    if (beg < end){  
        int mid = (beg + end) / 2;  
        mergeSort(a, beg, mid);  
        mergeSort(a, mid + 1, end);  
        merge(a, beg, mid, end);  
    }  
}  

void combineArr(int *&dest,int arr1[],int arr2[],int n1,int n2,int &destSize){
    dest = new int[n1+n2];
    destSize = n1+n2;
    int i;
    for(i=0;i<n1;i++)
        dest[i] = arr1[i];
    for(int j=0;j<n2;j++)
        dest[i+j] = arr2[j];
}

void display(int arr[],int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}
  
int main(){  
    int arr1[10] = {1,10,2,9,3,8,4,7,5,6};
    int arr2[10] = {0,11,20,12,19,13,18,17,14,16};

    cout<<"Array#1:"<<endl;
    display(arr1,10);
    cout<<endl<<"Array2:"<<endl;
    display(arr2,10);
    int newSize;
    int *combined;
    combineArr(combined,arr1,arr2,10,10,newSize);
    cout<<endl<<"Combined Array:"<<endl;
    display(combined,newSize);

    int rSorted[newSize];
    int mSorted[newSize];
    for(int i=0;i<newSize;i++){
        rSorted[i] = combined[i];
        mSorted[i] = combined[i];
    }

    cout<<endl<<"After sorting with Radix Sort:"<<endl;
    radixsort(rSorted,newSize);
    display(rSorted,newSize);

    cout<<"After sorting with Merge Sort:"<<endl;
    mergeSort(mSorted,0,newSize-1);
    display(mSorted,newSize);
    return 0;
}  
