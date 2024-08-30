//23K2001 - Muzammil
#include<iostream>
using namespace std;

class dynamic{
    private:
    int rows,cols;
    int **matrix;

    public:
    dynamic(){matrix=NULL;}
    dynamic(int r,int c,int val=0){
        rows = r;
        cols = c;
        matrix = new int*[rows];
        
        for(int i=0;i<rows;i++){
        matrix[i] = new int[cols];
        for(int j=0;j<cols;j++)
            matrix[i][j] = val;
        }
    }

    void resize(int r,int c,int val=0){
        int **old = new int*[r];
        for(int i=0;i<r;i++){
        old[i] = new int[c];
        for(int j=0;j<c;j++)
            old[i][j] = val;
        }

        for(int i=0;i<(rows < r ? rows: r);i++)
            for(int j=0;j<(cols < c ? cols: c);j++)
                old[i][j] = matrix[i][j];

        for(int i=0;i<rows;i++)
        delete[] matrix[i];

        delete[] matrix;

        if(rows<r || cols<c){
            matrix = new int*[r];
            
            for(int i=0;i<r;i++)
            matrix[i] = new int[c];

            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    matrix[i][j] = old[i][j];
        }
        else{
            matrix = new int*[r];
            for(int i=0;i<r;i++){
                matrix[i] = new int[c];
                for(int j=0;j<c;j++)
                matrix[i][j] = old[i][j];
            }
        }

        for(int i=0;i<rows;i++)
            delete[] old[i];
        delete[] old;

        rows=r;
        cols=c;
    }

    void transpose(){
        int **old = new int*[rows];
        for(int i=0;i<rows;i++){
            old[i] = new int[cols];
            for(int j=0;j<cols;j++)
            old[i][j] = matrix[i][j];
        }

        for(int i=0;i<rows;i++)
            delete[] matrix[i];

        delete[] matrix;

        matrix = new int*[cols];
        for(int i=0;i<cols;i++){
            matrix[i] = new int[rows];
            for(int j=0;j<rows;j++)
            matrix[i][j] = old[j][i];
        }

        for(int i=0;i<rows;i++)
            delete[] old[i];

        delete[] old;

        rows += cols;
        cols = rows-cols;
        rows -= cols;
    }

    void fill(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++)
            cin>>matrix[i][j];
        }
        cout<<endl;
        display();
    }

    void display(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++)
            cout<<matrix[i][j]<<"  ";

            cout<<endl;
        }
        cout<<endl;
    }

    void Add2Odd(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(j%2!=0)
                    matrix[i][j]+=2;
            }
        }
    }

    ~dynamic(){
        for(int i=0;i<rows;i++)
            delete[] matrix[i];
        delete[] matrix;
    }
};

int main(){
    dynamic mat1(3,4);
    cout<<"Fill matrix:"<<endl;
    mat1.fill();

    cout<<"Transpose: "<<endl;
    mat1.transpose();
    mat1.display();

    cout<<"Adding 2 in odd indexes:"<<endl;
    mat1.Add2Odd();
    mat1.display();

    cout<<"Resizing:"<<endl;
    mat1.resize(2,5,27);
    mat1.display();
    return 0;
}