//23K2001 - Muzammil
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void evaluateGuess(int key,int p=0){
    int guess;
    cout<<"Enter guess (Player#"<<p<<"): ";
    cin>>guess;
	if(guess==key){
        cout<<"Player#"<<p<<" had the correct guess. ("<<guess<<")"<<endl;
        return;
    }
    else{
        if(guess>key) cout<<"Too high!"<<endl;
        else cout<<"Too low!"<<endl;
        evaluateGuess(key,1-p);
    }
}
int main(){
    srand(time(0));
	int k = (rand()%100)+1;
    cout<<"\t\tPLAYER#0 vs PLAYER#1"<<endl;
    cout<<"Guess a number between 1-100!"<<endl;
    evaluateGuess(k);
    return 0;
}