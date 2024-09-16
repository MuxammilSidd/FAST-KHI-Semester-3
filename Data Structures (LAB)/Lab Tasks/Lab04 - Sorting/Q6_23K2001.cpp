//23K2001 - Muzammil
#include<iostream>
using namespace std;

int binSearch(int *arr,int n,int key){
    int left = 0;
    int right = n-1;
    while(left <= right) {
        int mid = left + (right - left)/2;

        if (arr[mid] == key) 
            return mid;
        else if (arr[mid] < key) 
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1;
}
void sortArr(int *arr,int n){
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
	cout<<"How many elements: ";
	cin>>n;
	m = new int[n];
	cout<<"Enter "<<n<<" elements:"<<endl;
	for(int i=0;i<n;i++)
	cin>>m[i];
    sortArr(m,n);
    cout<<endl;
    for(int i=0;i<n;i++)
	cout<<m[i]<<"\t";

    int x;
    cout<<endl<<"Enter value to search for: ";
    cin>>x;
    int res = binSearch(m,n,x);
    if(res!=-1)
    cout<<"Value present at index#"<<res<<endl;
    else
    cout<<"Value couldn't be found."<<endl;
	delete[] m;
	return 0;
}