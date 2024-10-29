//23K2001 - Muzammil
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

int random(int i,int j){
    return (i + rand()%(j-i+1));
}
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
int count = 0;
int partition(int a[], int start, int end, int pivot){
    int i = start; 
    int j = end;

    while (i < j){
        while (a[i] <= a[pivot] && i < end){
            i++;
            count++;
        }
        while (a[j] > a[pivot] && j > start){
            j--;
            count++;
        }
        if (i < j) 
            swap(a[i], a[j]);
    }
    swap(a[start], a[j]);
    return j;
    
}
void qSort_FirstElement(int a[],int start,int end){
    if (start < end)  
    {  
        int pivot = start;
        int p = partition(a, start, end, pivot); 
        qSort_FirstElement(a, start, p - 1);  
        qSort_FirstElement(a, p + 1, end);  
    }
}
void qSort_RandomElement(int a[],int start,int end){
    if (start < end)  
    {  
        int r = random(start,end);
        swap(a[start],a[r]);
        int pivot = start;
        int p = partition(a, start, end, pivot); 
        qSort_RandomElement(a, start, p - 1);  
        qSort_RandomElement(a, p + 1, end);  
    }
}
void qSort_MidElement(int a[],int start,int end){
    if (start < end)  
    {  
        int mid = start+(end-start)/2;
        swap(a[start],a[mid]);
        int pivot = start;
        int p = partition(a, start, end, pivot); 
        qSort_MidElement(a, start, p - 1);  
        qSort_MidElement(a, p + 1, end);  
    }
}
void qSort_Median(int a[],int start,int end){
    if (start < end)  
    {  
        int mid = start + (end-start)/2;
        if ((a[start] <= a[mid] && a[mid] <= a[end]) || (a[end] <= a[mid] && a[mid] <= a[start])) 
            swap(a[start], a[mid]);
        else if ((a[mid] <= a[start] && a[start] <= a[end]) || (a[end] <= a[start] && a[start] <= a[mid])) 
            swap(a[start], a[start]);
        else 
            swap(a[start], a[end]);
        
        int pivot = start;
        int p = partition(a, start, end, pivot); 
        qSort_Median(a, start, p - 1);  
        qSort_Median(a, p + 1, end);  
    }
}
void display(int *p,int n){
    for(int i=0;i<n;i++)
        cout<<p[i]<<"\t";
    cout<<endl;
}

int main(){
    srand(time(0));

    int flex1[] = {5,1,4,2,3};
    cout<<"QuickSort (pivot: first element) on Randomized Array:"<<endl;
    qSort_FirstElement(flex1,0,4);
    display(flex1,5);
    cout<<"\t\tComparisons made: "<<count<<endl<<endl;
    count = 0;

    int flex2[] = {5,1,4,2,3};
    cout<<"QuickSort (pivot: middle element) on Randomized Array:"<<endl;
    qSort_MidElement(flex2,0,4);
    display(flex2,5);
    cout<<"\t\tComparisons made: "<<count<<endl<<endl;
    count = 0;

    int flex3[] = {5,1,4,2,3};
    cout<<"QuickSort (pivot: median element) on Randomized Array:"<<endl;
    qSort_Median(flex3,0,4);
    display(flex3,5);
    cout<<"\t\tComparisons made: "<<count<<endl<<endl;
    count = 0;
    cout<<"-------------------------------------------------"<<endl;
//-----------------------------------------------------------------------------------------------
    int flex4[] = {1,2,3,4,5};
    cout<<"QuickSort (pivot: first element) on Sorted Array:"<<endl;
    qSort_FirstElement(flex4,0,4);
    display(flex4,5);
    cout<<"\t\tComparisons made: "<<count<<endl<<endl;
    count = 0;

    int flex5[] = {1,2,3,4,5};
    cout<<"QuickSort (pivot: middle element) on Sorted Array:"<<endl;
    qSort_MidElement(flex5,0,4);
    display(flex5,5);
    cout<<"\t\tComparisons made: "<<count<<endl<<endl;
    count = 0;

    int flex6[] = {1,2,3,4,5};
    cout<<"QuickSort (pivot: median element) on Sorted Array:"<<endl;
    qSort_Median(flex6,0,4);
    display(flex6,5);
    cout<<"\t\tComparisons made: "<<count<<endl<<endl;
    count = 0;
    cout<<"-------------------------------------------------"<<endl;
//-----------------------------------------------------------------------------------------------
    int flex7[] = {5,4,3,2,1};
    cout<<"QuickSort (pivot: first element) on Reverse-Sorted Array:"<<endl;
    qSort_FirstElement(flex7,0,4);
    display(flex7,5);
    cout<<"\t\tComparisons made: "<<count<<endl<<endl;
    count = 0;

    int flex8[] = {5,4,3,2,1};
    cout<<"QuickSort (pivot: middle element) on Reverse-Sorted Array:"<<endl;
    qSort_MidElement(flex8,0,4);
    display(flex8,5);
    cout<<"\t\tComparisons made: "<<count<<endl<<endl;
    count = 0;

    int flex9[] = {5,4,3,2,1};
    cout<<"QuickSort (pivot: median element) on Reverse-Sorted Array:"<<endl;
    qSort_Median(flex9,0,4);
    display(flex9,5);
    cout<<"\t\tComparisons made: "<<count<<endl<<endl;
    count = 0;
    return 0;
}  
