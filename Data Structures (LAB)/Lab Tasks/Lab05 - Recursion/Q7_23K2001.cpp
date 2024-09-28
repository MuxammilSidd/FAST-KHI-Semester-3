//23K2001 - Muzammil
#include<iostream>
using namespace std;

bool canPlace(int board[],int row,int col){
    for(int i=0; i<row; i++){
        if(board[i]==col || abs(board[i]-col)==abs(i-row))
            return false;
    }
    return true;
}
bool maxFlags(int board[],int n,int row=0){
    if(row==n) 
        return true;
    
    for(int col=0;col<n;col++){
        if(canPlace(board,row,col)){
            board[row] = col;
            if(maxFlags(board,n,row+1))
                return true;

            board[row] = -1;
        }
    }
    return false;
}
void display(int *arr,int n){
    int f=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]==j){
                cout<<"F ";
                f++; }
            else
                cout<<"- ";
        }
        cout<<endl;
    }
    cout<<"Maximum number of flags that can be placed: "<<f<<endl;
}
int main(){
    int* ground=new int[4];
    for(int i=0;i<4;i++)
        ground[i] = -1;
    maxFlags(ground,4);
    display(ground,4);
    delete[] ground;
    return 0;
}