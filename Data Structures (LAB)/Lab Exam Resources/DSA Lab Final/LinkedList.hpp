#pragma once
#include <iostream>
#include <vector>
#include <stdexcept> // For std::out_of_range
using namespace std;

template<class T>
class Node {
    T data;
    Node* next_ptr = nullptr;

public:
    Node(T data, Node* ptr = nullptr) : data(data), next_ptr(ptr) {}

    T& getData() { return data; }
    void setData(T data_) { data = data_; }
    
    Node* nextPtr() const { return next_ptr; }
    void setNextPtr(Node* nextPtr) { next_ptr = nextPtr; }
};

template<class T>
class Linked_List {
    int size;
    Node<T>* head;
    Node<T>* tail;

public:
    int getSize() const { return size; }

    Linked_List() : size(0), head(nullptr), tail(nullptr) {}

    Linked_List(vector<T> arr):Linked_List() {
        for (auto a : arr) {
            Append(a);
        }
    }

    Linked_List(T data) : size(1) {
        head = new Node<T>(data);
        tail = head;
    }

    ~Linked_List() {
        Node<T>* current = head;
        Node<T>* nextNode;
        while (current != nullptr) {
            nextNode = current->nextPtr();
            delete current;
            current = nextNode;
        }
    }

    void Append(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (tail != nullptr) {
            tail->setNextPtr(newNode);
        } else {
            head = newNode;
        }
        tail = newNode;
        size++;
    }

    void InsertAtPos(T val, T data) {
        Node<T>* temp = head;
        Node<T>* previous = nullptr;

        while (temp != nullptr && temp->getData() != val) {
            previous = temp;
            temp = temp->nextPtr();
        }

        if (temp == nullptr) {
            throw invalid_argument("Value not found in list");
        }

        Node<T>* newNode = new Node<T>(data, temp);
        if (previous != nullptr) {
            previous->setNextPtr(newNode);
        } else {
            head = newNode;
        }
        size++;
    }

    void InsertAtBeginning(T data) {
        Node<T>* newNode = new Node<T>(data, head);
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
        size++;
    }

    void display() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->getData() << " ";
            temp = temp->nextPtr();
        }
        cout << endl;
    }

    void remove(T val) {
        Node<T>* temp = head;
        Node<T>* previous = nullptr;

        while (temp != nullptr && temp->getData() != val) {
            previous = temp;
            temp = temp->nextPtr();
        }

        if (temp == nullptr) {
            throw invalid_argument("Value not found in list");
        }

        if (previous != nullptr) {
            previous->setNextPtr(temp->nextPtr());
            if (temp == tail) {
                tail = previous;
            }
        } else {
            head = head->nextPtr();
            if (head == nullptr) {
                tail = nullptr;
            }
        }
        delete temp;
        size--;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }

        Node<T>* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->nextPtr();
        }
        return temp->getData();
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }

        Node<T>* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->nextPtr();
        }
        return temp->getData();
    }

   void Reverse() {
    Node<T>* previous = nullptr;
    Node<T>* current = head;
    Node<T>* next = nullptr;

    while (current != nullptr) {
        next = current->nextPtr();
        current->setNextPtr(previous);
        previous = current;
        current = next;
    }
    tail = head;
    head = previous;
}

void Merge(Linked_List<T>& list) {
    if (tail != nullptr) {
        tail->setNextPtr(list.getHead());
        if (list.getHead() != nullptr) {
            list.getTail()->setNextPtr(nullptr);
        }
        tail = list.getTail();
    } else {
        head = list.getHead();
        tail = list.getTail();
    }
    size += list.getSize();
}

Node<T>* getHead()  { return head; }

Node<T>* getTail() { return tail; }
void setTail(Node<T>* tail_) { tail = tail_; }

void setHead(Node<T>* head_) { head = head_; }

Linked_List(const Linked_List<T>& other) : size(other.size), head(nullptr), tail(nullptr) {
        if (other.head == nullptr) return;

        head = new Node<T>(other.head->getData());
        Node<T>* current = head;
        Node<T>* otherCurrent = other.head->nextPtr();

        while (otherCurrent != nullptr) {
            current->setNextPtr(new Node<T>(otherCurrent->getData()));
            current = current->nextPtr();
            otherCurrent = otherCurrent->nextPtr();
        }
        tail = current;
    }

    Linked_List<T>& operator=(const Linked_List<T>& other) {
        if (this == &other) return *this; // Handle self-assignment

        // Clean up existing nodes
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* nextNode = current->nextPtr();
            delete current;
            current = nextNode;
        }

        size = other.size;
        head = tail = nullptr;

        if (other.head == nullptr) return *this;

        head = new Node<T>(other.head->getData());
        Node<T>* newCurrent = head;
        Node<T>* otherCurrent = other.head->nextPtr();

        while (otherCurrent != nullptr) {
            newCurrent->setNextPtr(new Node<T>(otherCurrent->getData()));
            newCurrent = newCurrent->nextPtr();
            otherCurrent = otherCurrent->nextPtr();
        }
        tail = newCurrent;

        return *this;
    }


};


template<class T>
class Circular_List {
    int size;
    Node<T>* head;

public:
    int getSize() const { return size; }

    Circular_List() : size(0), head(nullptr) {}

    Circular_List(vector<T> arr) : Circular_List() {
        for (const auto& a : arr) {
            Append(a);
        }
    }

    Circular_List(T data) : size(1) {
        head = new Node<T>(data);
        head->setNextPtr(head); 
    }

    ~Circular_List() {
        if (size == 0) return;
        
        Node<T>* current = head;
        Node<T>* nextNode;

        do {
            nextNode = current->nextPtr();
            delete current;
            current = nextNode;
        } while (current != head);
    }

    void Append(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            head->setNextPtr(head); 
        } else {
            Node<T>* temp = head;
            while (temp->nextPtr() != head) {
                temp = temp->nextPtr();
            }
            temp->setNextPtr(newNode);
            newNode->setNextPtr(head);
        }
        size++;
    }

    void InsertAtBeginning(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            head->setNextPtr(head); 
        } else {
            Node<T>* temp = head;
            while (temp->nextPtr() != head) {
                temp = temp->nextPtr();
            }
            newNode->setNextPtr(head);
            head = newNode;
            temp->setNextPtr(head);
        }
        size++;
    }

    void InsertAtPos(int pos, T data) {
        if (pos < 0 || pos >= size) {
            throw out_of_range("Position out of bounds");
        }

        if (pos == 0) {
            InsertAtBeginning(data);
            return;
        }

        Node<T>* newNode = new Node<T>(data);
        Node<T>* temp = head;
        for (int i = 0; i < pos - 1; ++i) {
            temp = temp->nextPtr();
        }
        newNode->setNextPtr(temp->nextPtr());
        temp->setNextPtr(newNode);
        size++;
    }

    void remove(T val) {
        if (head == nullptr) {
            throw invalid_argument("List is empty");
        }

        Node<T>* temp = head;
        Node<T>* prev = nullptr;
        do {
            if (temp->getData() == val) {
                break;
            }
            prev = temp;
            temp = temp->nextPtr();
        } while (temp != head);

        if (temp->getData() != val) {
            throw invalid_argument("Value not found in list");
        }

        if (prev == nullptr) { 
            Node<T>* last = head;
            while (last->nextPtr() != head) {
                last = last->nextPtr();
            }
            if (head == head->nextPtr()) { 
                delete head;
                head = nullptr;
            } else {
                head = head->nextPtr();
                last->setNextPtr(head);
                delete temp;
            }
        } else {
            prev->setNextPtr(temp->nextPtr());
            delete temp;
        }
        size--;
    }

    void display() const {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node<T>* temp = head;
        do {
            cout << temp->getData() << " ";
            temp = temp->nextPtr();
        } while (temp != head);
        cout << endl;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }

        Node<T>* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->nextPtr();
        }
        return temp->getData();
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }

        Node<T>* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->nextPtr();
        }
        return temp->getData();
    }
};

template<class T>
class DoubleNode {
    T data;
    DoubleNode* next_ptr = nullptr;
    DoubleNode* prev_ptr = nullptr;

public:
    DoubleNode(T data, DoubleNode* next_ptr = nullptr, DoubleNode* prev_ptr = nullptr)
        : data(data), next_ptr(next_ptr), prev_ptr(prev_ptr) {}

    T& getData() { return data; }
    void setData(T data_) { data = data_; }
    
    DoubleNode* nextPtr() const { return next_ptr; }
    void setNextPtr(DoubleNode* nextPtr) { next_ptr = nextPtr; }
    
    DoubleNode* prevPtr() const { return prev_ptr; }
    void setPrevPtr(DoubleNode* prevPtr) { prev_ptr = prevPtr; }
};

template<class T>
class Doubly_List {
    int size;
    DoubleNode<T>* head;
    DoubleNode<T>* tail;

public:
    Doubly_List() : size(0), head(nullptr), tail(nullptr) {}

    Doubly_List(const vector<T>& arr) : Doubly_List() {
        for (const auto& a : arr) {
            Append(a);
        }
    }

    Doubly_List(T data) : size(1) {
        head = new DoubleNode<T>(data);
        tail = head;
    }

    ~Doubly_List() {
        DoubleNode<T>* current = head;
        DoubleNode<T>* nextDoubleNode;
        while (current != nullptr) {
            nextDoubleNode = current->nextPtr();
            delete current;
            current = nextDoubleNode;
        }
    }

    int getSize() const { return size; }

    void Append(T data) {
        DoubleNode<T>* newDoubleNode = new DoubleNode<T>(data, nullptr, tail);
        if (tail != nullptr) {
            tail->setNextPtr(newDoubleNode);
        } else {
            head = newDoubleNode;
        }
        tail = newDoubleNode;
        size++;
    }

    void InsertAtPos(T val, T data) {
        DoubleNode<T>* temp = head;
        DoubleNode<T>* previous = nullptr;

        while (temp != nullptr && temp->getData() != val) {
            previous = temp;
            temp = temp->nextPtr();
        }

        if (temp == nullptr) {
            throw invalid_argument("Value not found in list");
        }

        DoubleNode<T>* newDoubleNode = new DoubleNode<T>(data, temp, previous);
        if (previous != nullptr) {
            previous->setNextPtr(newDoubleNode);
        } else {
            head = newDoubleNode;
        }
        temp->setPrevPtr(newDoubleNode);
        size++;
    }

    void InsertAtBeginning(T data) {
        DoubleNode<T>* newDoubleNode = new DoubleNode<T>(data, head, nullptr);
        if (head != nullptr) {
            head->setPrevPtr(newDoubleNode);
        } else {
            tail = newDoubleNode;
        }
        head = newDoubleNode;
        size++;
    }

    void display() const {
        DoubleNode<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->getData() << " ";
            temp = temp->nextPtr();
        }
        cout << endl;
    }

    void remove(T val) {
        DoubleNode<T>* temp = head;
        DoubleNode<T>* previous = nullptr;

        while (temp != nullptr && temp->getData() != val) {
            previous = temp;
            temp = temp->nextPtr();
        }

        if (temp == nullptr) {
            throw invalid_argument("Value not found in list");
        }

        if (previous != nullptr) {
            previous->setNextPtr(temp->nextPtr());
        } else {
            head = temp->nextPtr();
            if (head != nullptr) {
                head->setPrevPtr(nullptr);
            }
        }

        if (temp->nextPtr() != nullptr) {
            temp->nextPtr()->setPrevPtr(previous);
        } else {
            tail = previous;
        }

        delete temp;
        size--;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }

        DoubleNode<T>* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->nextPtr();
        }
        return temp->getData();
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }

        DoubleNode<T>* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->nextPtr();
        }
        return temp->getData();
    }

    void Merge(Doubly_List<T>& List) {
        tail->setNextPtr(List.getHead());
        List.getHead()->setPrevPtr(tail);
        tail =List.getTail();
    }

    DoubleNode<T>* getHead() const { return head; }

    DoubleNode<T>* getTail() const { return tail; }

    void setHead(DoubleNode<T>* head_) { head = head_; }

    void setTail(DoubleNode<T>* tail_) { tail = tail_; }
    
};

