#include <bits/stdc++.h>
using namespace std;

// Hashnode class
class HashNode {
public:
    int key;
    int value;

    // Constructor of hashnode
    HashNode(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

// Our own Hashmap class
class HashMap {
    // hash element array
    HashNode** arr;
    int capacity;
    // current size
    int size;
    // dummy node
    HashNode* dummy;

public:
    HashMap()
    {
        // Initial capacity of hash array
        capacity = 20;
        size = 0;
        arr = new HashNode*[capacity];

        // Initialise all elements of array as NULL
        for (int i = 0; i < capacity; i++)
            arr[i] = NULL;

        // dummy node with value and key -1
        dummy = new HashNode(-1, -1);
    }

    // Hash function to find index for a key
    int hashCode(int key) { return key % capacity; }

    // Function to add key value pair
    void insertNode(int key, int value)
    {
        HashNode* temp = new HashNode(key, value);

        // Apply hash function to find index for given key
        int hashIndex = hashCode(key);

        // Find next free space
        while (arr[hashIndex] != NULL
               && arr[hashIndex]->key != key
               && arr[hashIndex]->key != -1) {
            hashIndex++;
            hashIndex %= capacity;
        }

        // If new node to be inserted, increase the current size
        if (arr[hashIndex] == NULL || arr[hashIndex]->key == -1)
            size++;
        arr[hashIndex] = temp;
    }

    // Function to delete a key-value pair
    int deleteNode(int key)
    {
        // Apply hash function to find index for given key
        int hashIndex = hashCode(key);

        // Find the node with the given key
        while (arr[hashIndex] != NULL) {
            // If node found
            if (arr[hashIndex]->key == key) {
                HashNode* temp = arr[hashIndex];

                // Insert dummy node here for further use
                arr[hashIndex] = dummy;

                // Reduce size
                size--;
                return temp->value;
            }
            hashIndex++;
            hashIndex %= capacity;
        }

        // If not found return -1
        return -1;
    }

    // Function to search the value for a given key
    int get(int key)
    {
        // Apply hash function to find index for given key
        int hashIndex = hashCode(key);
        int counter = 0;

        // Find the node with the given key
        while (arr[hashIndex] != NULL) {
            if (counter++ > capacity) // To avoid infinite loop
                return -1;

            // If node found, return its value
            if (arr[hashIndex]->key == key)
                return arr[hashIndex]->value;

            hashIndex++;
            hashIndex %= capacity;
        }

        // If not found, return -1
        return -1;
    }

    // Return current size
    int sizeofMap() { return size; }

    // Return true if size is 0
    bool isEmpty() { return size == 0; }

    // Function to display the stored key-value pairs
    void display()
    {
        for (int i = 0; i < capacity; i++) {
            if (arr[i] != NULL && arr[i]->key != -1)
                cout << "key = " << arr[i]->key
                     << "  value = " << arr[i]->value
                     << endl;
        }
    }
};

// Driver method to test map class
int main()
{
    HashMap h;
    h.insertNode(1, 1);
    h.insertNode(2, 2);
    h.insertNode(2, 3);
    h.display();
    cout << h.sizeofMap() << endl;
    cout << h.deleteNode(2) << endl;
    cout << h.sizeofMap() << endl;
    cout << h.isEmpty() << endl;
    cout << h.get(2);

    return 0;
}
