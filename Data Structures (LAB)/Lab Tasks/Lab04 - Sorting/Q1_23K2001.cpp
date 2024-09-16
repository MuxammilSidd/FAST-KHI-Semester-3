//23K2001 - Muzammil
#include<iostream>
using namespace std;

void sortByRange(int *arr,int n,int x,int y){
	if(x>n || y>n || x<0 || y<0){
		cout<<"Exceeded bounds!"<<endl;
		return;
	}
	if(x==y)
	return;
	
	if(x<y){
	    for(int i=x;i<y;i++){
	        int min_index = i;
	
	        for(int j=i+1;j<y+1;j++){
	            if(arr[j]<arr[min_index])
	                min_index = j;
	        }
	        int temp = arr[i];
	        arr[i] = arr[min_index];
	        arr[min_index] = temp;
	    }
	}
	else{
        for(int i=x;i<n-1;i++){
            int min_index = i;
            for(int j=i+1;j<n;j++)
                if(arr[j] < arr[min_index])
                    min_index = j;
            
            int temp = arr[i];
	        arr[i] = arr[min_index];
	        arr[min_index] = temp;
        }
		for(int i=0;i<y;i++){
            int min_index = i;
            for (int j=i+1;j<y+1;j++)
                if (arr[j] < arr[min_index])
                    min_index = j;
            
            int temp = arr[i];
	        arr[i] = arr[min_index];
	        arr[min_index] = temp;
        }
	}
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

	int a,b;
	cout<<endl<<"Enter range [a,b] to sort: ";
	cin>>a>>b;
	sortByRange(m,n,a,b);
	cout<<"After sorting in range:"<<endl;
	for(int i=0;i<n;i++)
		cout<<m[i]<<"\t";
	delete[] m;
	return 0;
}