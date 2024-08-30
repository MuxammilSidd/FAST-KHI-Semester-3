//23K2001 - Muzammil
#include<iostream>
using namespace std;
int main(){
    string **theatre;
    cout<<"How many rows: ";
    int m;
    cin>>m;
    theatre = new string*[m];
    int *seats = new int[m];
    
    int n;
    for(int i=0;i<m;i++){
        cout<<"\nHow many seats in row#"<<i+1<<": ";
        cin>>n;
        theatre[i] = new string[n];
        seats[i] = n;
        cout<<"Enter "<<n<<" names: "<<endl;

        for(int j=0;j<n;j++)
        cin>>theatre[i][j];
    }

    cout<<"\n\tWelcome to Askari Theatre"<<endl;
    for(int i=0;i<m;i++){
        cout<<"Row#"<<i+1<<": ";
        for(int j=0;j<seats[i];j++)
        cout<<theatre[i][j]<<"\t";

        cout<<endl;
    }

    for(int i=0;i<m;i++)
        delete[] theatre[i];

    delete[] theatre;    
    delete[] seats;
    return 0;
}