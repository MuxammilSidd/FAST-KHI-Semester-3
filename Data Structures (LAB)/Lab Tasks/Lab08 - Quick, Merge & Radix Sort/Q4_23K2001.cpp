//23K2001 - Muzammil
#include<iostream>
using namespace std;

class product{
    public:
        string name,desc;
        float price;
        bool availability;
    
        product(){}
        product(string n,float p,string d,bool a): name(n),desc(d),price(p),availability(a){}
};

int partition(product a[], int start, int end){  
    float pivot = a[end].price;
    int i = start - 1; 

    for(int j = start; j < end; j++) {  
        if (a[j].price <= pivot) {  
            i++;  
            product t = a[i];  
            a[i] = a[j];  
            a[j] = t;
        }  
    }  
    product t = a[i + 1];  
    a[i + 1] = a[end];  
    a[end] = t;  

    return i + 1;
}
void quickSort(product a[], int start, int end){  
    if (start < end)  
    {  
        int p = partition(a, start, end); 
        quickSort(a, start, p - 1);  
        quickSort(a, p + 1, end);  
    }  
}  
void display(product *p,int n){
    for(int i=0;i<n;i++)
        cout<<p[i].name<<" - "<<p[i].price<<endl;
    cout<<endl;
}
  
int main(){  
    product p1 = {"Product 1",10.99,"This is product 1.",true};
    product p2 = {"Product 2",5.99,"This is product 2.",false};
    product p3 = {"Product 3",2.99,"This is product 3.",true};

    product products[] = {p1,p2,p3};
    cout<<"Original entries before sorting:"<<endl;
    display(products,3);

    cout<<"Products sorted by price (ascending):"<<endl;
    quickSort(products,0,2);
    display(products,3);
    return 0;
}  
