#include <iostream>
#include <vector>
using namespace std;

// Initial size of the hash table
#define INITIAL_SIZE 20

// Load factor threshold for resizing
#define LOAD_FACTOR_THRESHOLD 0.7

// DataItem struct represents an element in the hash table, containing a key and data
struct DataItem {
   int data;
   int key;
};

// HashTable class implementing a hash table with open addressing and linear probing
class HashTable {
private:
    vector<DataItem*> hashArray; // Vector holding pointers to DataItems
    DataItem* dummyItem;         // Dummy item used to mark deleted slots
    int currentSize;             // Current number of elements in the table
    int tableSize;               // Current capacity of the table

    // Hash function that returns the index based on the key
    int hashCode(int key) {
        return key % tableSize;
    }

    // Function to resize the hash table when the load factor exceeds the threshold
    void resizeTable() {
        int oldSize = tableSize;
        tableSize *= 2;  // Double the table size
        vector<DataItem*> oldArray = hashArray; // Copy current table
        hashArray.clear();
        hashArray.resize(tableSize, nullptr); // Resize hash array to new size
        currentSize = 0; // Reset size for rehashing

        // Rehash each non-dummy item from old array into new table
        for (int i = 0; i < oldSize; i++) {
            if (oldArray[i] != nullptr && oldArray[i] != dummyItem) {
                insert(oldArray[i]->key, oldArray[i]->data);
                delete oldArray[i]; // Free memory for rehashed item
            }
        }
    }

    // Calculate the current load factor of the hash table
    double loadFactor() {
        return (double)currentSize / tableSize;
    }

public:
    // Constructor initializes the hash table with initial size and dummy item for deletions
    HashTable() : tableSize(INITIAL_SIZE), currentSize(0) {
        hashArray.resize(tableSize, nullptr); // Allocate space in the hash array
        dummyItem = new DataItem;             // Create dummy item for deleted slots
        dummyItem->data = -1;
        dummyItem->key = -1;
    }

    // Destructor to free memory for all dynamically allocated items
    ~HashTable() {
        for (auto item : hashArray) {
            if (item != nullptr && item != dummyItem) {
                delete item; // Delete each non-dummy item
            }
        }
        delete dummyItem; // Delete dummy item
    }

    // Search function for finding an item by its key
    DataItem* search(int key) {
        int hashIndex = hashCode(key); // Calculate initial hash index
        while (hashArray[hashIndex] != nullptr) { // Linear probing for collision resolution
            if (hashArray[hashIndex] != dummyItem && hashArray[hashIndex]->key == key)
                return hashArray[hashIndex]; // Return item if key matches
            hashIndex = (hashIndex + 1) % tableSize; // Move to next index
        }
        return nullptr; // Return null if key not found
    }

    // Insert function to add a new item to the hash table
    void insert(int key, int data) {
        // Check load factor and resize table if needed
        if (loadFactor() > LOAD_FACTOR_THRESHOLD) {
            resizeTable();
        }

        DataItem* item = new DataItem;
        item->data = data;
        item->key = key;
        int hashIndex = hashCode(key); // Calculate hash index

        // Find an empty slot or update an existing slot with the same key
        while (hashArray[hashIndex] != nullptr && hashArray[hashIndex] != dummyItem && hashArray[hashIndex]->key != -1) {
            if (hashArray[hashIndex]->key == key) {
                delete item; // If key exists, update data and free new item
                hashArray[hashIndex]->data = data;
                return;
            }
            hashIndex = (hashIndex + 1) % tableSize; // Linear probing
        }
        hashArray[hashIndex] = item; // Place item in found slot
        currentSize++; // Increment size
    }

    // Delete function removes an item with the specified key
    DataItem* deleteItem(int key) {
        int hashIndex = hashCode(key); // Calculate initial hash index
        while (hashArray[hashIndex] != nullptr) { // Linear probing to find the item
            if (hashArray[hashIndex] != dummyItem && hashArray[hashIndex]->key == key) {
                DataItem* temp = hashArray[hashIndex]; // Save item to return
                hashArray[hashIndex] = dummyItem; // Mark slot as deleted
                currentSize--; // Decrement size
                return temp; // Return deleted item
            }
            hashIndex = (hashIndex + 1) % tableSize; // Move to next index
        }
        return nullptr; // Return null if item not found
    }

    // Display function to print the contents of the hash table
    void display() const {
        for (int i = 0; i < tableSize; i++) {
            if (hashArray[i] != nullptr && hashArray[i] != dummyItem)
                cout << " (" << hashArray[i]->key << "," << hashArray[i]->data << ")"; // Print key-value pair
            else
                cout << " ~~ "; // Print placeholder for empty or deleted slot
        }
        cout << endl;
    }
};

// Main function to test the hash table
int main() {
    HashTable hashTable;

    // Insert items into the hash table
    hashTable.insert(1, 20);
    hashTable.insert(2, 70);
    hashTable.insert(42, 80);
    hashTable.insert(4, 25);
    hashTable.insert(12, 44);
    hashTable.insert(14, 32);
    hashTable.insert(17, 11);
    hashTable.insert(13, 78);
    hashTable.insert(37, 97);

    // Display the hash table contents
    cout << "Contents of Hash Table: ";
    hashTable.display();

    // Search for an element
    int ele = 37;
    cout << "Searching for element: " << ele;
    DataItem* item = hashTable.search(ele);
    if (item != nullptr) {
        cout << "\nElement found: (" << item->key << ", " << item->data << ")";
    } else {
        cout << "\nElement not found";
    }

    // Delete an element
    hashTable.deleteItem(ele);
    cout << "\nHash Table contents after deletion: ";
    hashTable.display();

    return 0;
}
