//23K2001 - Muzammil
#include<iostream>
#include <cstring> 
using namespace std;

const int MAX_SUM = 10000;

void equalSumPairs(int arr[],int n){
    int hashTable[MAX_SUM][2]; 
    memset(hashTable,-1,sizeof(hashTable));
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            int sum = arr[i]+arr[j];
            if (hashTable[sum][0]!=-1){
                int key1 = hashTable[sum][0];
                int key2 = hashTable[sum][1];
                if (key1!=i && key1!=j && key2!=i && key2!=j){
                    cout << "\n\tPairs found: (" << arr[key1] << ", " << arr[key2]
                         << ") and (" << arr[i] << ", " << arr[j] << ")\n";
                    return;
                }
            }
            hashTable[sum][0] = i;
            hashTable[sum][1] = j;
        }
    }
    cout << "\n\tNo pairs with equal sum were found.\n";
}

int main(){
    int flex1[] = {3, 4, 7, 1, 2, 9, 8};
    int flex2[] = {3,4,7,1,12,9};
    int flex3[] = {65,30,7,90,1,9,8};
    cout << "\nInput-1: {3, 4, 7, 1, 2, 9, 8}"<<endl;
    equalSumPairs(flex1,7);
    cout << "\nInput-2: {3, 4, 7, 1, 12, 9}"<<endl;
    equalSumPairs(flex2,6);
    cout << "\nInput-3: {65, 30, 7, 90, 1, 9, 8}"<<endl;
    equalSumPairs(flex3,7);
    return 0;
}
