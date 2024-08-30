//23K2001 - Muzammil
#include<iostream>
using namespace std;

bool checkFriend(bool arr[5][5], int r,int c){
    for(int i=0;i<5;i++){
            if(arr[r][i]==true && arr[c][i]==true)
            return true;
    }
    return false;
}

int main(){
    bool grid[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            grid[i][j] = false;
        }
    }
    
    grid[0][1] = true;
    grid[0][3] = true;
    grid[1][0] = true;
    grid[1][2] = true;
    grid[1][4] = true;
    grid[2][1] = true;
    grid[3][0] = true;
    grid[3][4] = true;
    grid[4][0] = true;
    grid[4][1] = true;
    grid[4][3] = true;
    grid[0][4] = true;

    if(checkFriend(grid,2,3))
    cout<<"They have a common friend."<<endl;
    else
    cout<<"They DON't have a common friend."<<endl;

    return 0;
}