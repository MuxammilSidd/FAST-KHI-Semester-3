//23K2001 - Muzammil
#include<iostream>
using namespace std;

int binSearch(string *arr,int n,string key,int &c){
    int left = 0;
    int right = n-1;
    while(left <= right) {
        int mid = left + (right - left)/2;
        c++;
        if (arr[mid] == key) 
            return mid;
        else if (arr[mid] < key) 
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1;
}
int linearSearch(string *arr,int n,string key,int &c){
    for(int i=0;i<n;i++){
        c++;
        if(arr[i]==key)
        return i;
    }
    return -1;
}

int main(){
	string *m = nullptr;
	int n;
	cout<<"How many elements: ";
	cin>>n;
	m = new string[n];
	cout<<"Enter "<<n<<" elements:"<<endl;
	for(int i=0;i<n;i++)
	cin>>m[i];

    string x;
    cout<<endl<<"Enter value to search for: ";
    cin>>x;

    cout<<endl<<"By binary search:"<<endl;
    int c1 = 0;
    int res1 = binSearch(m,n,x,c1);
    if(res1!=-1)
        cout<<"Value present at index#"<<res1<<endl;
    else
        cout<<"Value couldn't be found."<<endl;
    cout<<"Steps taken: "<<c1<<endl;

    cout<<endl<<"By linear search:"<<endl;
    int c2 = 0;
    int res2 = linearSearch(m,n,x,c2);
    if(res2!=-1)
        cout<<"Value present at index#"<<res2<<endl;
    else
        cout<<"Value couldn't be found."<<endl;
    cout<<"Steps taken: "<<c2<<endl;

	delete[] m;
	return 0;
}