#include <iostream>
using namespace std;

class HashTable {
private:
    int* table;      // Dynamic array to store hash table
    int* freq;       // Dynamic array to track frequencies
    int size;        // Current size of the hash table
    int count;       // Number of elements in the table
    const float loadFactorThreshold = 0.75;

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

    // Helper function to find the next prime number
    int nextPrime(int n) {
        while (true) {
            n++;
            bool isPrime = true;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) return n;
        }
    }

    // Rehash the table
    void rehash() {
        cout << "\nRehashing...\n";
        int oldSize = size;
        size = nextPrime(2 * oldSize);

        // Create new table and frequency arrays
        int* oldTable = table;
        int* oldFreq = freq;
        table = new int[size];
        freq = new int[100];

        // Initialize the new table and frequency arrays
        for (int i = 0; i < size; i++) {
            table[i] = -1; // Initialize all slots as empty (-1)
            freq[i] = 0;
        }

        // Reinsert all elements into the new table
        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i] != -1) { // Ignore empty slots
                int key = oldTable[i];
                int index = hashFunction(key);
                for (int j = 0; j < size; j++) {
                    int probeIndex = (index + j) % size;
                    if (table[probeIndex] == -1) {
                        table[probeIndex] = key;
                        break;
                    }
                }
                for(int i=0; i<100;i++){
                    freq[i] = oldFreq[i]; // Copy frequency
                }
            }
        }

        // Free old table and frequency array
        delete[] oldTable;
        delete[] oldFreq;

        cout << "Rehashing complete. New size: " << size << endl;
    }

public:
    // Constructor
    HashTable(int initialSize) {
        size = initialSize;
        count = 0;
        table = new int[size];
        freq = new int[100];

        for (int i = 0; i < size; i++) {
            table[i] = -1; // Initialize all slots as empty (-1)
        }
         for (int i = 0; i < 100; i++) {
            freq[i] = 0; 
        }

    }

    // Insert a key
    void insert(int key) {
        if (count >= loadFactorThreshold * size) {
            rehash();
        }

        int index = hashFunction(key);
        for (int i = 0; i < size; i++) {
            if (count == size) {
                rehash();
            }
            int probeIndex = (index + i) % size;
            if (table[probeIndex] == -1) {
                table[probeIndex] = key;
                freq[key]++;
                count++;
                return;
            } 
        }
    }

    // Search for a key
    bool search(int key) {
        int index = hashFunction(key);
        int start = index;
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % size;
            if (index == start) break;
        }
        return false;
    }

    // Display the hash table
    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < size; i++) {
            if (table[i] == -1) {
                cout << "Index " << i << ": Empty" << endl;
            } else {
                cout << "Index " << i << ": " << table[i] << ", Frequency: " << freq[i] << endl;
            }
        }
    }

    // Destructor
    ~HashTable() {
        delete[] table;
        delete[] freq;
    }
};

int main() {
    HashTable ht(5); // Initial size of hash table

    // Insert keys
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(30);

    // Display the hash table
    ht.display();

    // Insert more keys to trigger rehashing
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(30);

    // Display the hash table after rehashing
    ht.display();

    // Search for keys
    cout << "\nSearch for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Search for 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;

    return 0;
}