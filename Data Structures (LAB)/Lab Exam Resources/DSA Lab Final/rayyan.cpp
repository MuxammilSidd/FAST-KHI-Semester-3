#define Table_Size 10

class HashNode {
public:
    pair<char, string> data;
    HashNode *next;

    HashNode(char key, string value) {
        this->data = make_pair(key, value);
        this->next = nullptr;
    }
};

class HashTable {
    HashNode* table[Table_Size];

public:
    HashTable() {
        for (int i = 0; i < Table_Size; i++) {
            table[i] = nullptr;
        }
    }

    int HashFunction(char key) {
        return key % Table_Size;
    }

    void insert(char key, string value) {
        int hash = HashFunction(key);

        if (table[hash] == nullptr) {
            table[hash] = new HashNode(key, value);
            return;
        }

        HashNode* temp = table[hash];
        while (temp != nullptr) {
            if (temp->data.first == key) {
                temp->data.second = value;
                return;
            }
            temp = temp->next;
        }

        HashNode* newNode = new HashNode(key, value);
        newNode->next = table[hash];
        table[hash] = newNode;
    }

    void display_table() const {
        for (int i = 0; i < Table_Size; i++) {
            HashNode* temp = table[i];
            while (temp != nullptr) {
                cout << temp->data.first << " " << temp->data.second << endl;
                temp = temp->next;
            }
        }
    }

    void search(char key) {
        int hash = HashFunction(key);
        HashNode* temp = table[hash];
        while (temp != nullptr) {
            if (temp->data.first == key) {
                cout << "Key found: Value: " << temp->data.second << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Key not found" << endl;
    }

    void remove(char key) {
        int hash = HashFunction(key);
        HashNode* temp = table[hash];
        HashNode* prev = nullptr;

        while (temp != nullptr) {
            if (temp->data.first == key) {
                if (prev == nullptr) {
                    table[hash] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Key found and removed" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Key not found for removal" << endl;
    }
};