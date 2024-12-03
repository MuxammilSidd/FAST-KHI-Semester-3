#include<iostream>
using namespace std;

class hashmap{
    public:
     int* hashtable;
     int size;

     hashmap(int c){
        size=c;
        hashtable= new int [size];
        for(int i=0; i<size;i++){
            hashtable[i]=-1;
        }
     }
     
     int hashfunc(int val){
        return val%size;
     }

     void insertkey(int val){
        int index= hashfunc(val);

        for(int i=0; i<size; i++){
            int probeindex= (index+i)%size;
            if(hashtable[probeindex]==-1 || hashtable[probeindex]==-2){
                hashtable[probeindex]=val;
                cout<<"Value added at index: "<<probeindex<<endl;
                return;
            }
        }
     }

     void deletekey(int val){
        int index= hashfunc(val);

        for(int i=0; i<size; i++){
            int probeindex= (index+i)%size;
            if(hashtable[probeindex]==val){
                hashtable[probeindex]=-2;
                cout<<"Value found and deleted at index: "<<probeindex<<endl;
                return;
            }
        }
     }

     bool searchkey(int val){
       int index= hashfunc(val);
        for(int i=0; i<size; i++){
            int probeindex= (index+i)%size;
            if(hashtable[probeindex]==val){
                cout<<"value found at index: "<<probeindex<<endl;
                return true;
            }
        }
        cout<<"value not found"<<endl;
        return false;
     }
    
       void displayHash() {
    for (int i = 0; i < size; i++) {
        if(hashtable[i]!=-1 && hashtable[i]!=-2){
        cout << hashtable[i]<<endl;
        }
    }
}

};

int main(){
    hashmap h(10);
    h.insertkey(10);
    h.insertkey(3);
    h.insertkey(5);
    h.insertkey(7);  
    h.insertkey(33);
    h.deletekey(3);
    h.searchkey(1);
    
    h.displayHash();
}