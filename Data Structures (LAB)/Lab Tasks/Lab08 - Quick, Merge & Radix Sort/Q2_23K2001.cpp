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

void countingSortAsc(int a[], int n, int place){  
  int output[n + 1];  
  int count[10] = {0};    

  for (int i = 0; i < n; i++)  
    count[(a[i] / place) % 10]++;  
  for (int i = 1; i < 10; i++)  
    count[i] += count[i - 1];  
  for (int i = n - 1; i >= 0; i--) {  
    output[count[(a[i] / place) % 10] - 1] = a[i];  
    count[(a[i] / place) % 10]--;  
  }  
  for (int i = 0; i < n; i++)  
    a[i] = output[i];  
}  
void countingSortDesc(int a[], int n, int place){  
    int output[n + 1];  
    int count[10] = {0};

    for (int i = 0; i < n; i++)  
        count[(a[i] / place) % 10]++;  
    for (int i = 8; i >= 0; i--)  
        count[i] += count[i + 1];  
    for (int i = n - 1; i >= 0; i--) {  
        output[count[(a[i] / place) % 10] - 1] = a[i];  
        count[(a[i] / place) % 10]--;  
    }  
    for (int i = 0; i < n; i++)  
        a[i] = output[i];  
}  
 
void radixSortAscend(int a[], int n){  
  int max = getMax(a, n);  

  for (int place = 1; max / place > 0; place *= 10)  
    countingSortAsc(a, n, place);  
}
void radixSortDescend(int a[], int n){  
    int max = getMax(a, n);  

    for (int place = 1; max / place > 0; place *= 10)  
        countingSortDesc(a, n, place);  
}  

void display(int a[], int n) {  
    for(int i = 0; i < n; ++i)
        cout<<a[i]<<" ";  
    cout<<endl<<endl;  
}  
  
int main(){  
    int a[] = {36,987, 654, 2, 20, 99, 456, 957, 555, 420, 66, 3};  
    int b[] = {36,987, 654, 2, 20, 99, 456, 957, 555, 420, 66, 3};
    int n = sizeof(a) / sizeof(a[0]);  
    cout<<"Before sorting array elements are - \n";  
    display(a,n);  

    radixSortAscend(a, n);  
    cout<<"After applying Radix sort (ascending), the array elements are - \n";  
    display(a, n);  

    radixSortDescend(b, n);  
    cout<<"After applying Radix sort (descending), the array elements are - \n";  
    display(b, n); 
    return 0;
}  
