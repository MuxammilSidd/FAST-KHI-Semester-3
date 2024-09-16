//23K2001 - Muzammil
#include<iostream>
using namespace std;

void sortString(string *s,int n){
	for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(s[j] > s[j+1]){
                string temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}
int main(){
    string *m = nullptr;
	int n;
	cout<<"How many elements: ";
	cin>>n;
	m = new string[n];
	cout<<"Enter "<<n<<" words:"<<endl;
	for(int i=0;i<n;i++)
	cin>>m[i];

	sortString(m,n);
	cout<<endl<<"After sorting:"<<endl;
	for(int i=0;i<n;i++)
		cout<<m[i]<<"\t";
	delete[] m;
	return 0;
}