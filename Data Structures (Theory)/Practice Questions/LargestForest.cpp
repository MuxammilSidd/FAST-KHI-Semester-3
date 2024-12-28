#include <iostream>
#include <vector>
using namespace std;

int helper(char arr[][5], int size, int i, int j) {
    if (i < size && j < size && i >= 0 && j >= 0) {
        if (arr[i][j] == 't') {
            arr[i][j] = 'N'; 
            return helper(arr, size, i + 1, j) + helper(arr, size, i, j + 1) +helper(arr, size, i, j - 1)+helper(arr, size, i-1, j)+ 1;
        } else {
            return 0;
        }
    }
    return 0; 
}

int CheckTrees(char arr[][5], int size, int count = 0) {
    vector<int> countarray; 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == 't') {
                countarray.push_back(helper(arr, size, i, j));
            }
        }
    }
    
    int highest = 0;
    for (auto a : countarray) {
        if (a > highest) {
            highest = a;
        }
    }
    return highest; 
}

int main() {
    char arr[5][5] = {
        {'t','t','t','w','w'},
        {'t','w','w','t','t'},
        {'t','w','w','t','t'},
        {'t','w','t','t','t'},
        {'w','w','t','t','t'}
    };

    cout << CheckTrees(arr, 5);
    return 0; 
}
