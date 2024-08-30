//23K2001 - Muzammil
#include<iostream>
using namespace std;

class jaggedArray{
    private:
    int **a;
    int *jaggedSizes;
    int rows;

    public:
    jaggedArray(){a=NULL;
    jaggedSizes=NULL;
    rows=0; }
    ~jaggedArray(){
        for(int i=0;i<rows;i++)
            delete[] a[i];
        delete[] a;
        delete[] jaggedSizes;
    }

    jaggedArray(int r){
        rows = r;
        a = new int*[rows];
        jaggedSizes = new int[rows];
        
        int c;
        for(int i=0;i<rows;i++){
            cout<<"\nColoumns for Row#"<<i+1<<" ? ";
            cin>>c;
            a[i] = new int[c];
            jaggedSizes[i]=c;
            cout<<"Enter "<<c<<" values for Row#"<<i+1<<": ";
            for(int j=0;j<c;j++)
                cin>>a[i][j];
        }
    }

    void resize(int c){
        int **old = new int*[rows];
        int *oldSizes = new int[rows];
        for(int i=0;i<rows;i++){
            old[i] = new int[jaggedSizes[i]];
            oldSizes[i] = jaggedSizes[i];
            for(int j=0;j<jaggedSizes[i];j++)
            old[i][j] = a[i][j];
        }

        for(int i=0;i<rows;i++)
            delete[] a[i];
        delete[] jaggedSizes;
        jaggedSizes = new int[rows];
        
        for(int i=0;i<rows;i++){
            a[i] = new int[c];
            jaggedSizes[i]=c;
            for(int j=0;j<(oldSizes[i] < c ? oldSizes[i]: c);j++)
            a[i][j] = old[i][j];

            if(c>oldSizes[i]){
            cout<<"Enter "<<c-oldSizes[i]<<" new values for Row#"<<i+1<<": ";
            for(int j=oldSizes[i];j<c;j++)
                cin>>a[i][j];
            }
        }

        for(int i=0;i<rows;i++)
            delete[] old[i];
        delete[] old;
        delete[] oldSizes;
    }

    void display(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<jaggedSizes[i];j++)
            cout<<a[i][j]<<"  ";

            cout<<endl;
        }
        cout<<endl;
    }
};

int main(){
    jaggedArray meow(5);
    meow.display();
    meow.resize(10);
    cout<<"After resized:"<<endl;
    meow.display();
    return 0;
}