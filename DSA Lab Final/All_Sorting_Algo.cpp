#include <iostream>
using namespace std;

void BubbleSort(int arr[] , int size) {
    for (int i=0;i<size;i++) {
        for (int j=0;j<size-1-i;j++) {
            if (arr[j]>arr[j+1]) {
                //swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void SelectionSort(int arr[] , int size) {
    for (int i=0;i<size-1;i++) {
        int lowest=arr[i];
        int lowest_index=i;
        for (int j=i+1;j<size;j++) {
            if (arr[j]<lowest) {
                lowest =arr[j];
                lowest_index=j;
            }
        }
        // swap
                int temp = arr[i];
                arr[i] = arr[lowest_index];
                arr[lowest_index] = temp;
    }
}


void InsertionSort(int arr[] , int size) {
    for (int i=1;i<size;i++) {
        int j = i-1;
        int key=arr[i];
        while (j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void ShellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int key = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > key) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = key;
        }
    }
}


void CountSort(int arr[] ,int size) {
    //find the highest value in the arr
    int highest =0;
    for (int i=0;i<size;i++) {
        if (arr[i] > highest) {
            highest = arr[i];
        }
    }    
    //we will count the number of distant elements in the arr
    int* countarray=new int[highest+1];
    // setting the counting array to zero
    for (int i=0;i<highest+1;i++) {
        countarray[i]=0;
    }
    //counting the elements
    for (int i=0;i<size;i++) {
        countarray[arr[i]]++;
    }
    //doing a cummulative sum on the count array this will give us the index+1 of each elements 
    for (int i=1;i<highest+1;i++) {
        countarray[i] += countarray[i-1];
    }
    //creating a new array of the orginal size and putting values into the correct index
    int* outputarray =new int [size];
    for (int i=0;i<size;i++) {
        outputarray[countarray[arr[i]]-1] =arr[i];
        countarray[arr[i]]--;
    }
    //copying the new arr into the old one
    for (int i = 0; i < size; i++) {
        arr[i] = outputarray[i];
    }

    delete[] countarray;  // Free dynamically allocated memory
    delete[] outputarray; // Free dynamically allocated memory


}

void CountSortExp(int arr[],int size,int exp) {
    int countarray[10] {0};
    for (int i=0;i<size;i++) {
        int val = (arr[i] /exp) % 10;
        countarray[val]++;  
    }
    for (int i=1;i<10;i++) {
        countarray[i] += countarray[i-1];
    }
    int* outputarray = new int[size];
    for (int i=size-1;i>=0;i--) {
        int val =(arr[i]/exp)% 10;
        outputarray[countarray[val]-1] = arr[i];
        countarray[val]--;
    }
    for (int i=0;i<size;i++) {
        arr[i]=outputarray[i];
    }
    delete outputarray;

}

void RedixSort(int arr[],int n) {
    int max {0};
    for (int i=0;i<n;i++) {
        if (arr[i]>max) {
            max = arr[i];
        }
    }

    for (int exp=1;max/exp>0;exp *=10) {
        CountSortExp(arr,n,exp);
    }
}


void Display(int arr[],int size) {
    for (int i=0;i<size;i++) {
        cout << arr[i] <<" ";
    }
    cout << "\n";
}

int main() {
    int arr[] {121, 432, 564, 23, 1, 45, 788};
    Display(arr,7);
    RedixSort(arr,7);
    Display(arr,7);

}