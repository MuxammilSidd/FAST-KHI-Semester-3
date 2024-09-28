//23K2001 - Muzammil
#include<iostream>
using namespace std;

bool moveLion(bool *maze[],int x,int y,int s,bool **sol){
    if(x==s-1 && y==s-1){
        sol[x][y]=1;
        return true;
    }
    if((x<s && y<s && maze[x][y]==1) ? true : false){
        sol[x][y]=1;
        if(moveLion(maze,x+1,y,s,sol))
            return true;
        if(moveLion(maze, x, y+1, s, sol))
            return true;
    }
    sol[x][y]=0;
    return false;
}
void display(bool **arr,int r,int c){
    for(int i=0;i<r;i++){
        cout<<"-";
        for(int j=0;j<c;j++)
            cout<<arr[i][j]<<"-";
        cout<<endl;
    }
}
int main(){
    bool **map, **path;
    int m,n;
    cout<<"Enter map dimensions: ";
    cin>>m>>n;
    map = new bool*[m];
    path = new bool*[m];
    for(int i=0;i<m;i++){
        map[i] = new bool[n];
        path[i] = new bool[n];
    }
    cout<<"Create the maze:"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            path[i][j]=false;
        }
    }
    cout<<endl<<"Maze:"<<endl;
    display(map,m,n);

    if(moveLion(map,0,0,5,path)){
        cout<<endl<<"Path found!"<<endl;
        cout<<endl<<"Movable path:"<<endl;
        display(path,m,n);
    }
    else
        cout<<"No path could be found!"<<endl;

    for(int i=0;i<m;i++){
        delete[] map[i];
        delete[] path[i];
    }
    delete[] map;
    delete[] path;
    return 0;
}