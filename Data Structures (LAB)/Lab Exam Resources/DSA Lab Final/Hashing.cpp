#include <iostream>
#include <list>
#include <vector>
#include <algorithm> // For std::find
using namespace std;

class hashing {
public:
    vector<list<int>> hashtable;
    int size;

    hashing(int val) {
        size = val;
        hashtable.resize(size);
    }

    int hashfunc(int val) {
        return val % size;  // Division method: h(k) = k mod m
    }

    void insertkey(int val) {
        int index = hashfunc(val);
        hashtable[index].push_back(val);
    }

    list<int>::iterator searchkey(int key) {
        int index = hashfunc(key);
        return find(hashtable[index].begin(), hashtable[index].end(), key);
    }

    void deletekey(int val) {
        int index = hashfunc(val);
        auto it = searchkey(val); // Store the iterator
        if (it != hashtable[index].end()) { 
            hashtable[index].erase(it); // Use the stored iterator
            cout << " " << val << " deleted" << endl;
        } else {
            cout << "Key not present in hashtable" << endl;
        }
    }

    void displayHash() {
    for (int i = 0; i < size; i++) {
        cout << "Index "<< i;
        for (int x : hashtable[i]) {
            cout << " --> " << x;
        }
        cout << endl;
    }
}
};

int main() {
    hashing h(10);

    h.insertkey(55);
    h.insertkey(14);
    h.insertkey(44);
    h.insertkey(23);
    h.insertkey(98);
    h.deletekey(44);

    h.displayHash();

    return 0;
}