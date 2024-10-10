//23K2001 - Muzammil
#include <iostream>
using namespace std;
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sort(int arr[], int size, int arr2[], int size2) {
    int count = 0;
    for (int i = 0; i < size2; i++) {
        int val = arr2[i];
        for (int j = 0; j < size; j++) {
            if (val == arr[j]) {
                swap(arr[count], arr[j]);
                count++;
            }
        }
    }
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int arr2[] = {1, 2, 3};

    int size = sizeof(arr) / sizeof(arr[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    sort(arr, size, arr2, size2);

    std::cout << "Sorted array based on arr2: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
