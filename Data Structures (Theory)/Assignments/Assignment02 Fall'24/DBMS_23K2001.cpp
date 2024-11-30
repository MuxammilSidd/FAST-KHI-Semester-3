//23K2001 - Muzammil - Assignment02: In-memory DBMS using Trees
#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<random>
#include<algorithm>
#include<chrono>
using namespace std;

class table{
    public:
        int id, age;
        string name;

        table():id(0),age(0),name(""){}
        table(int id, string name, int age):id(id),age(age),name(name){}
        void display(){ cout<<"ID: "<<id<<"\tName: "<<name<<"\tAge: "<<age<<endl; }
        void operator=(const table &t){
            this->id = t.id;
            this->age = t.age;
            this->name = t.name;
        }
        table(const table &t){      //Constructor to use when creating node
            this->id = t.id;
            this->age = t.age;
            this->name = t.name;
        }
};

class BSTnode{
    public:
        table bst_table;
        BSTnode* left;
        BSTnode* right;
        BSTnode():left(nullptr),right(nullptr){}
        BSTnode(table T):bst_table(T),left(nullptr),right(nullptr){}
};
class BST{
    public:
        BSTnode* root;
        BST():root(nullptr){}

        void insertNode(table T){
            if(root == nullptr){
                BSTnode* n = new BSTnode(T);
                root = n;
                return;
            }
            BSTnode* temp = root;
            while(1){
                if(temp->bst_table.id <= T.id){
                    if(temp->right != nullptr)
                        temp = temp->right;
                    else{
                        temp->right = new BSTnode(T);
                        break; 
                    }
                }
                else{
                    if(temp->left != nullptr)
                        temp = temp->left;
                    else{
                        temp->left = new BSTnode(T);
                        break;
                    }
                }
            }
        }
        BSTnode* getFarRight(BSTnode* root){
            while(root->right != nullptr)
                root = root->right;
            return root;
        }
        BSTnode* helper(BSTnode*root){
            if(root->left==nullptr)
                return root->right;
            if(root->right==nullptr)
                return root->left;

            BSTnode* rightSideRoot = root->right;
            BSTnode* leftSideMax = getFarRight(root->left);
            leftSideMax->right = rightSideRoot;
            return root->left;
        }
        BSTnode* deleteNode(int id){
            if(root == nullptr)
                return nullptr;
            if(root->bst_table.id == id){
                BSTnode* deletedBSTnode = root;
                root = helper(root);
                return deletedBSTnode;
            }

            BSTnode* temp = root;
            while(temp != nullptr){
                if (temp->bst_table.id > id) {
                    if(temp->left != nullptr && temp->left->bst_table.id == id){
                        BSTnode* deletedBSTnode = temp->left;
                        temp->left = helper(temp->left);
                        return deletedBSTnode;
                    } 
                    else
                        temp = temp->left;
                } 
                else{
                    if(temp->right != nullptr && temp->right->bst_table.id == id){
                        BSTnode* deletedBSTnode = temp->right;
                        temp->right = helper(temp->right);
                        return deletedBSTnode;
                    } 
                    else
                        temp = temp->right;
                }
            }
            return nullptr;
        }
        bool search(int id){
            if(root == nullptr) 
                return false;
            BSTnode* temp = root;
            while(temp != nullptr){
                if(temp->bst_table.id == id)
                    return true;
                else if(temp->bst_table.id < id)
                    temp = temp->right;
                else
                    temp = temp->left;
            }
            return false;
        }
        void inOrder(){ inOrder(root); }
        void inOrder(BSTnode* r){
    		if(r == nullptr)
        		return;

		    inOrder(r->left);
		    r->bst_table.display();
		    inOrder(r->right);
		}
};

class AVLnode{
    public:
        table avl_table;
        int height;
        AVLnode* left;
        AVLnode* right;
        AVLnode():left(nullptr),right(nullptr){}
        AVLnode(table T):avl_table(T),height(1),left(nullptr),right(nullptr){}
};
class AVLTree{
    public:
        AVLnode* root;
        AVLTree():root(nullptr){}

        AVLnode* insertNode(AVLnode* root,table T){
            if(root == nullptr) return new AVLnode(T);
            
            if(T.id < root->avl_table.id)
                root->left = insertNode(root->left , T);
            else if(T.id > root->avl_table.id)
                root->right = insertNode(root->right , T);
            
            root->height = 1 + max(getHeight(root->left) , getHeight(root->right));
            int balance = getBalance(root);

            if (balance > 1 && T.id < root->left->avl_table.id)
                return rightRotate(root);
            if (balance < -1 && T.id > root->right->avl_table.id)
                return leftRotate(root);

            if (balance > 1 && T.id > root->left->avl_table.id){
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            if (balance < -1 && T.id < root->right->avl_table.id){
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root; 
        }
        void insertNode(table T){ root = insertNode(root,T);  }
        void preOrder(){ preOrder(root); }
        void preOrder(AVLnode* r){
    		if(r == nullptr)
        		return;

		    r->avl_table.display();
		    preOrder(r->left);
		    preOrder(r->right);
		}
        int getHeight(AVLnode* r){
            if(r == nullptr) 
                return 0;
            return r->height;
        }
        int getBalance(AVLnode* root){  return(getHeight(root->left) - getHeight(root->right)); }

        AVLnode* rightRotate(AVLnode* y){
            AVLnode* x = y->left;
            AVLnode* temp = x->right;

            x->right = y;
            y->left = temp;

            y->height = 1 + max(getHeight(y->left) , getHeight(y->right));
            x->height = 1 + max(getHeight(x->left) , getHeight(x->right));
            return x;
        }

        AVLnode* leftRotate(AVLnode* x){
            AVLnode* y = x->right;
            AVLnode* temp = y->left;

            y->left = x;
            x->right = temp;
            
            x->height = 1 + max(getHeight(x->left) , getHeight(x->right));
            y->height = 1 + max(getHeight(y->left) , getHeight(y->right));
            return y;
        }

        AVLnode* farLeft(AVLnode* r){   //Helper for deleteNode() function
            AVLnode* curr = r;
            while (curr->left)
                curr = curr->left;
            return curr;
        }
        AVLnode* deleteNode(AVLnode* r, int id) {
            if (!r) return r;

            if (id < r->avl_table.id)
                r->left = deleteNode(r->left, id);
            else if (id > r->avl_table.id)
                r->right = deleteNode(r->right, id);
            else {
                if (!r->left || !r->right) {
                    AVLnode* temp = r->left ? r->left : r->right;
                    if (!temp) {
                        temp = r;
                        r = nullptr;
                    } else
                        *r = *temp;
                    delete temp;
                } else {
                    AVLnode* temp = farLeft(r->right);
                    r->avl_table.id = temp->avl_table.id;
                    r->right = deleteNode(r->right, temp->avl_table.id);
                }
            }

            if (!r) return r;

            r->height = max(getHeight(r->left), getHeight(r->right)) + 1;
            int balance = getBalance(r);

            if (balance > 1 && getBalance(r->left) >= 0)
                return rightRotate(r);
            if (balance > 1 && getBalance(r->left) < 0) {
                r->left = leftRotate(r->left);
                return rightRotate(r);
            }
            if (balance < -1 && getBalance(r->right) <= 0)
                return leftRotate(r);
            if (balance < -1 && getBalance(r->right) > 0) {
                r->right = rightRotate(r->right);
                return leftRotate(r);
            }

            return r;
        }
        void deleteNode(int id){ root = deleteNode(root, id); }

        bool search(int id){
            if(root == nullptr) 
                return false;
            AVLnode* temp = root;
            while(temp != nullptr){
                if(temp->avl_table.id == id)
                    return true;
                else if(temp->avl_table.id < id)
                    temp = temp->right;
                else
                    temp = temp->left;
            }
            return false;
        }
};

const int DEGREE = 3;
class BTreeNode{
    public:
    int numKeys;
    table keys[2 * DEGREE - 1];
    BTreeNode* children[2 * DEGREE];
    bool isLeaf;

    BTreeNode(bool leaf) : numKeys(0), isLeaf(leaf) { memset(children, 0, sizeof(children)); }

    table* search(int id) {
        int i = 0;
        while (i < numKeys && id > keys[i].id)
            i++;
        if (i < numKeys && keys[i].id == id)
            return &keys[i];
        if (isLeaf)
            return nullptr;
        return children[i]->search(id);
    }

    void insertNonFull(table T){
        int i = numKeys - 1;
        if (isLeaf) {
            while (i >= 0 && keys[i].id > T.id) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = T;
            numKeys++;
        } else {
            while (i >= 0 && keys[i].id > T.id)
                i--;
            if (children[i + 1]->numKeys == 2 * DEGREE - 1) {
                splitChild(i + 1, children[i + 1]);
                if (keys[i + 1].id < T.id)
                    i++;
            }
            children[i + 1]->insertNonFull(T);
        }
    }
    void splitChild(int i, BTreeNode* y){
        BTreeNode* z = new BTreeNode(y->isLeaf);
        z->numKeys = DEGREE - 1;

        for (int j = 0; j < DEGREE - 1; j++)
            z->keys[j] = y->keys[j + DEGREE];
        if (!y->isLeaf) {
            for (int j = 0; j < DEGREE; j++)
                z->children[j] = y->children[j + DEGREE];
        }
        y->numKeys = DEGREE - 1;

        for (int j = numKeys; j >= i + 1; j--)
            children[j + 1] = children[j];
        children[i + 1] = z;

        for (int j = numKeys - 1; j >= i; j--)
            keys[j + 1] = keys[j];
        keys[i] = y->keys[DEGREE - 1];
        numKeys++;
    }
    void remove(int id){
        int idx = findKey(id);
        if (idx < numKeys && keys[idx].id == id) {
            if (isLeaf)
                removeFromLeaf(idx);
            else
                removeFromNonLeaf(idx);
        } else {
            if (isLeaf)
                return;
            bool isLastChild = (idx == numKeys);
            if (children[idx]->numKeys < DEGREE)
                fill(idx);
            if (isLastChild && idx > numKeys)
                children[idx - 1]->remove(id);
            else
                children[idx]->remove(id);
        }
    }
    void removeFromLeaf(int idx){
        for (int i = idx + 1; i < numKeys; i++)
            keys[i - 1] = keys[i];
        numKeys--;
    }
    void removeFromNonLeaf(int idx){
        int id = keys[idx].id;
        if (children[idx]->numKeys >= DEGREE) {
            table pred = getPred(idx);
            keys[idx] = pred;
            children[idx]->remove(pred.id);
        } else if (children[idx + 1]->numKeys >= DEGREE) {
            table succ = getSucc(idx);
            keys[idx] = succ;
            children[idx + 1]->remove(succ.id);
        } else {
            merge(idx);
            children[idx]->remove(id);
        }
    }
    int findKey(int id){
        int idx = 0;
        while (idx < numKeys && keys[idx].id < id)
            idx++;
        return idx;
    }
    table getPred(int idx){
        BTreeNode* cur = children[idx];
        while (!cur->isLeaf)
            cur = cur->children[cur->numKeys];
        return cur->keys[cur->numKeys - 1];
    }
    table getSucc(int idx){
        BTreeNode* cur = children[idx + 1];
        while (!cur->isLeaf)
            cur = cur->children[0];
        return cur->keys[0];
    }
    void fill(int idx){
        if (idx != 0 && children[idx - 1]->numKeys >= DEGREE)
            borrowFromPrev(idx);
        else if (idx != numKeys && children[idx + 1]->numKeys >= DEGREE)
            borrowFromNext(idx);
        else {
            if (idx != numKeys)
                merge(idx);
            else
                merge(idx - 1);
        }
    }
    void borrowFromPrev(int idx){
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx - 1];
        for (int i = child->numKeys - 1; i >= 0; i--)
            child->keys[i + 1] = child->keys[i];
        if (!child->isLeaf) {
            for (int i = child->numKeys; i >= 0; i--)
                child->children[i + 1] = child->children[i];
        }
        child->keys[0] = keys[idx - 1];
        if (!child->isLeaf)
            child->children[0] = sibling->children[sibling->numKeys];
        keys[idx - 1] = sibling->keys[sibling->numKeys - 1];
        child->numKeys++;
        sibling->numKeys--;
    }
    void borrowFromNext(int idx){
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx + 1];
        child->keys[child->numKeys] = keys[idx];
        if (!child->isLeaf)
            child->children[child->numKeys + 1] = sibling->children[0];
        keys[idx] = sibling->keys[0];
        for (int i = 1; i < sibling->numKeys; i++)
            sibling->keys[i - 1] = sibling->keys[i];
        if (!sibling->isLeaf) {
            for (int i = 1; i <= sibling->numKeys; i++)
                sibling->children[i - 1] = sibling->children[i];
        }
        child->numKeys++;
        sibling->numKeys--;
    }
    void merge(int idx){
        BTreeNode* child = children[idx];
        BTreeNode* sibling = children[idx + 1];
        child->keys[DEGREE - 1] = keys[idx];
        for (int i = 0; i < sibling->numKeys; i++)
            child->keys[i + DEGREE] = sibling->keys[i];
        if (!child->isLeaf) {
            for (int i = 0; i <= sibling->numKeys; i++)
                child->children[i + DEGREE] = sibling->children[i];
        }
        for (int i = idx + 1; i < numKeys; i++)
            keys[i - 1] = keys[i];
        for (int i = idx + 2; i <= numKeys; i++)
            children[i - 1] = children[i];
        child->numKeys += sibling->numKeys + 1;
        numKeys--;
        delete sibling;
    }
};
class BTree{
    public:
    BTreeNode* root;
    BTree() : root(nullptr) {}

    void insert(table T){
        if (!root) {
            root = new BTreeNode(true);
            root->keys[0] = T;
            root->numKeys = 1;
        } else {
            if (root->numKeys == 2 * DEGREE - 1) {
                BTreeNode* s = new BTreeNode(false);
                s->children[0] = root;
                s->splitChild(0, root);
                int i = (s->keys[0].id < T.id) ? 1 : 0;
                s->children[i]->insertNonFull(T);
                root = s;
            } else 
                root->insertNonFull(T);
            
        }
    }
    table* search(int id){ return root ? root->search(id) : nullptr; }
    void remove(int id){
        if (!root)
            return;
        root->remove(id);
        if (root->numKeys == 0) {
            BTreeNode* temp = root;
            if (root->isLeaf)
                root = nullptr;
            else
                root = root->children[0];
            delete temp;
        }
    }
};

void generateIDs(int *arr,int size,int low,int high){
    vector<int> numbers;
    for (int i = low; i <= high; ++i)
        numbers.push_back(i);

    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(rand()));

    for (int i = 0; i < size; ++i)
        arr[i] = numbers[i];
}
void generateAges(int *arr, int size, int low, int high) {
    for (int i = 0; i < size; i++)
        arr[i] = low + rand() % (high - low + 1);
}

void printTable(string treeName, double times[3][3]){
    cout << "-----------------------------------------------\n";
    cout << "Tree Type: " << treeName << "\n";
    cout << "-----------------------------------------------\n";
    cout << "Dataset\t\tInsert (ms)\tSearch (ms)\tDelete (ms)\n";
    cout << "-----------------------------------------------\n";

    string dataSets[] = {"1000", "10,000", "50,000"};
    for(int i = 0; i < 3; i++){
        cout << dataSets[i] << "\t\t"
             << times[i][0] << "\t\t"
             << times[i][1] << "\t\t"
             << times[i][2] << "\n";
    }
    cout << "-----------------------------------------------\n";
}

int n = 50000;
int* dummyID = new int[n];
int* dummyAge = new int[n];

int main(){
    BST flex1;
    AVLTree flex2;
    BTree flex3;

    int dataSets[3] = {1000, 10000, 50000};
    srand(static_cast<unsigned>(time(0)));

    generateIDs(dummyID, n, 1000, 100000);
    generateAges(dummyAge, n, 18, 70);

    double BSTtimes[3][3];     // insert - search - delete
    double AVLtimes[3][3];     // insert - search - delete
    double BTreetimes[3][3];   // insert - search - delete

    for (int i = 0; i < 3; i++) {
        //---------------------------------BST Execution-----------------------------------------------//
        //insertion time for BST
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSets[i]; j++) {
            table t(dummyID[j], " ", dummyAge[j]);
            flex1.insertNode(t);
        }
        auto end = std::chrono::high_resolution_clock::now();
        BSTtimes[i][0] = std::chrono::duration<double, std::nano>(end - start).count() / 1e6;

        //search time for BST
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 50000; j++)
            flex1.search(dummyID[j]);
        end = std::chrono::high_resolution_clock::now();
        BSTtimes[i][1] = std::chrono::duration<double, std::nano>(end - start).count() / 1e6;

        //deletion time for BST
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSets[i]; j++)
            flex1.deleteNode(dummyID[j]);
        end = std::chrono::high_resolution_clock::now();
        BSTtimes[i][2] = std::chrono::duration<double, std::nano>(end - start).count() / 1e6;

        //---------------------------------AVL Tree Execution------------------------------------------//
        //insertion time for AVL
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSets[i]; j++) {
            table t(dummyID[j], " ", dummyAge[j]);
            flex2.insertNode(t);
        }
        end = std::chrono::high_resolution_clock::now();
        AVLtimes[i][0] = std::chrono::duration<double, std::nano>(end - start).count() / 1e6;

        //search time for AVL
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 50000; j++)
            flex2.search(dummyID[j]);
        end = std::chrono::high_resolution_clock::now();
        AVLtimes[i][1] = std::chrono::duration<double, std::nano>(end - start).count() / 1e6;

        //deletion time for AVL
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSets[i]; j++)
            flex2.deleteNode(dummyID[j]);
        end = std::chrono::high_resolution_clock::now();
        AVLtimes[i][2] = std::chrono::duration<double, std::nano>(end - start).count() / 1e6;

        //---------------------------------BTree Execution---------------------------------------------//
        //insertion time for B-Tree
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSets[i]; j++) {
            table t(dummyID[j], " ", dummyAge[j]);
            flex3.insert(t);
        }
        end = std::chrono::high_resolution_clock::now();
        BTreetimes[i][0] = std::chrono::duration<double, std::nano>(end - start).count() / 1e6;

        //search time for B-Tree
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 50000; j++)
            flex3.search(dummyID[j]);
        end = std::chrono::high_resolution_clock::now();
        BTreetimes[i][1] = std::chrono::duration<double, std::nano>(end - start).count() / 1e6;

        //deletion time for B-Tree
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < dataSets[i]; j++)
            flex3.remove(dummyID[j]);
        end = std::chrono::high_resolution_clock::now();
        BTreetimes[i][2] = std::chrono::duration<double, std::nano>(end - start).count() / 1e6;
    }

    printTable("Binary Search Tree (BST)", BSTtimes);
    printTable("AVL Tree", AVLtimes);
    printTable("B-Tree", BTreetimes);

    delete[] dummyID;
    delete[] dummyAge;
    return 0;
}