//23K2001 - Muzammil
#include<iostream>
using namespace std;

class MaxHeap{
private:
    int* heap;
    int capacity;
    int currentSize;

    void swap(int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    }
    void heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < currentSize && heap[left] > heap[largest])
            largest = left;

        if (right < currentSize && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }
public:
    MaxHeap():heap(nullptr),capacity(0),currentSize(0){}
    MaxHeap(int cap) {
        capacity = cap;
        heap = new int[capacity];
        currentSize = 0;
    }

    void insert(int value) {
        if (currentSize == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }

        heap[currentSize] = value;
        int i = currentSize;
        currentSize++;

        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int deleteMax() {
        if (currentSize <= 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }

        int root = heap[0];
        heap[0] = heap[currentSize - 1];
        currentSize--;

        heapify(0);
        return root;
    }

    int peek(){
        if (currentSize <= 0) {
            cout << "Heap is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    void buildHeap(int arr[], int n){
        if (n > capacity) {
            cout << "Array size exceeds heap capacity!" << endl;
            return;
        }

        for (int i = 0; i < n; i++) 
            heap[i] = arr[i];
        currentSize = n;

        for (int i = currentSize / 2 - 1; i >= 0; i--) 
            heapify(i);
    }

    void printHeap(){
        for (int i = 0; i < currentSize; i++)
            cout << heap[i] << " ";
        cout << endl;
    }

    int extractMax(){  return deleteMax(); }
    int size(){  return currentSize; }
    bool isEmpty(){  return currentSize == 0;    }
};

int main(){
    MaxHeap flex(10);
    flex.insert(3);
    flex.insert(1);
    flex.insert(5);
    flex.insert(4);
    flex.insert(2);
    cout << "Heap: ";
    flex.printHeap();

    cout << "Highest priority data: " << flex.extractMax() << endl;
    cout << "Heap after extraction: ";
    flex.printHeap();

    cout<<endl<<"Adding new data with priority: 2."<<endl;
    flex.insert(2);
    cout<<"Updated heap: ";
    flex.printHeap();
    return 0;
}