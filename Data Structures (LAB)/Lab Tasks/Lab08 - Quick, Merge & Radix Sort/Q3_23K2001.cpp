//23K2001 - Muzammil
#include<iostream>
using namespace std;

class runner{
    public:
        string name;
        float time;

        runner(){}
        runner(string n,float t):name(n),time(t){}
};

void merge(runner *a, int beg, int mid, int end){    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    runner LeftArray[n1], RightArray[n2];  
 
    for (int i = 0; i < n1; i++){
    LeftArray[i].time = a[beg + i].time;    
    LeftArray[i].name = a[beg + i].name;
    }    
    for (int j = 0; j < n2; j++){
    RightArray[j].time = a[mid + 1 + j].time;    
    RightArray[j].name = a[mid + 1 + j].name;
    }  
      
    i = 0;
    j = 0; 
    k = beg; 
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i].time <= RightArray[j].time)    
        {
            a[k].name = LeftArray[i].name;    
            a[k].time = LeftArray[i].time;    
            i++;    
        }    
        else    
        {    
            a[k].name = RightArray[j].name;
            a[k].time = RightArray[j].time;    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k].time = LeftArray[i].time;
        a[k].name = LeftArray[i].name;    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        a[k].time = RightArray[j].time;
        a[k].name = RightArray[j].name;  
        j++;    
        k++;    
    }    
}    
void mergeSort(runner *a, int beg, int end){  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        mergeSort(a, beg, mid);  
        mergeSort(a, mid + 1, end);  
        merge(a, beg, mid, end);  
    }  
}
void display(runner *a, int n){  
    for(int i = 0; i < n; ++i)
        cout<<i+1<<". "<<a[i].name<<"\t"<<a[i].time<<" (sec)"<<endl;  
    cout<<endl;  
}  
  
int main(){  
    int n;
    cout<<"How many runners: ";
    cin>>n;
    runner *runners = new runner[n];
    for(int i=0;i<n;i++){
        cout<<"Input name & finish time (sec) for runner#"<<i+1;
        cout<<": ";
        cin>>runners[i].name>>runners[i].time;
    }
    cout<<endl;
    display(runners,n);
    cout<<endl<<"After sorting top#5 fastest runners:"<<endl;
    mergeSort(runners,0,n-1);
    display(runners,5);
    return 0;
}  
