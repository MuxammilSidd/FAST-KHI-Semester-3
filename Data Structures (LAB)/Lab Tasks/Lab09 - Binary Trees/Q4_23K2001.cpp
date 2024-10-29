//23K2001 - Muzammil
#include<iostream>
#include<stack>
using namespace std;

class inventory{
    public:
        int id, qty;
        inventory():id(0),qty(0){}
        inventory(int i,int q):id(i),qty(q){}
        void operator =(const inventory &i){
            this->id = i.id;
            this->qty = i.qty;
        }
        void display(){
            cout<<"ID: "<<id<<"\tQuantity: "<<qty<<endl;
        }
};
class node{
    public:
        inventory inv;
        node* left;
        node* right;
        node():left(nullptr),right(nullptr){}
        node(inventory inv):inv(inv),left(nullptr),right(nullptr){}
};
class tree{
    public:
        node* root;
        tree():root(nullptr){}

        void insertNode(inventory i){
            if(root == nullptr){
                node* n = new node(i);
                root = n;
                return;
            }
            node* temp = root;
            while(1){
                if(temp->inv.id <= i.id){
                    if(temp->right != nullptr)
                        temp = temp->right;
                    else{
                        temp->right = new node(i);
                        break; 
                    }
                }
                else{
                    if(temp->left != nullptr)
                        temp = temp->left;
                    else{
                        temp->left = new node(i);
                        break;
                    }
                }
            }
        }
        node* getFarRight(node* root){
            while(root->right != nullptr)
                root = root->right;
            return root;
        }
        node* helper(node*root){
            if(root->left==nullptr)
                return root->right;
            if(root->right==nullptr)
                return root->left;

            node* rightSideRoot = root->right;
            node* leftSideMax = getFarRight(root->left);
            leftSideMax->right = rightSideRoot;
            return root->left;
        }
        node* deleteNode(int key){
            if(root == nullptr)
                return nullptr;
            if(root->inv.id == key){
                node* deletedNode = root;
                root = helper(root);
                return deletedNode;
            }

            node* temp = root;
            while(temp != nullptr){
                if (temp->inv.id > key) {
                    if(temp->left != nullptr && temp->left->inv.id == key){
                        node* deletedNode = temp->left;
                        temp->left = helper(temp->left);
                        return deletedNode;
                    } 
                    else
                        temp = temp->left;
                } 
                else{
                    if(temp->right != nullptr && temp->right->inv.id == key){
                        node* deletedNode = temp->right;
                        temp->right = helper(temp->right);
                        return deletedNode;
                    } 
                    else
                        temp = temp->right;
                }
            }
            return nullptr;
        }
        bool search(int i){
            if(root == nullptr) 
                return false;
            node* temp = root;
            while(temp != nullptr){
                if(temp->inv.id == i)
                    return true;
                else if(temp->inv.id < i)
                    temp = temp->right;
                else
                    temp = temp->left;
            }
            return false;
        }
        void inOrder(){ inOrder(root); }
        void inOrder(node* r){
    		if(r == nullptr)
        		return;

		    inOrder(r->left);
		    r->inv.display();
		    inOrder(r->right);
		}
        inventory getHighestQty(){
            if (root == nullptr) { 
                cout<<"No products in inventory!"<<endl;
                return inventory();
            }

            inventory temp; 
            int highest = 0;
            stack<node*> t;
            node* curr = root;
            while(curr != nullptr || !t.empty()){
                while(curr != nullptr){
                    t.push(curr);
                    curr = curr->left;
                }

                curr = t.top();
                t.pop();
                if (curr->inv.qty > highest){
                    highest = curr->inv.qty;  
                    temp = curr->inv;           
                }
                curr = curr->right;
            }
            return temp;
        }
};
int main(){
    int x;
    cout<<"How many products: ";
    cin>>x;
    inventory items[x];
    tree flex;
    cout<<"Input "<<x<<" product details..(ID:XXXX QTY:XX)"<<endl;
    for(int i=0;i<x;i++){
        cin>>items[i].id>>items[i].qty;
        flex.insertNode(items[i]);
    }

    cout<<endl<<"Displaying products through inOrder traverse:"<<endl;
    flex.inOrder();

    int c;
    do{
        cout<<endl<<"1. Insert new product"<<endl;
        cout<<"2. Update quantity of a product"<<endl;
        cout<<"3. Search product by ID"<<endl;
        cout<<"4. Display product with highest quantity"<<endl;
        cout<<"5. Exit"<<endl;
        cin>>c;

        switch(c){
            case 1:{
                cout<<"Input product details..(ID:XXXX QTY:XX)"<<endl;
                int id,q;
                cin>>id>>q;
                inventory newItem(id,q);
                flex.insertNode(newItem);
                break;
            }
            case 2:{
                cout<<"Enter ID of product to update: ";
                int id;
                cin>>id;
                if(flex.search(id)){
                    int q;
                    cout<<"Enter new quantity: ";
                    cin>>q;
                    flex.deleteNode(id);
                    inventory newItem(id,q);
                    flex.insertNode(newItem);
                    cout<<"Quantity updated!"<<endl;
                }
                else
                    cout<<"Could NOT find any Product with ID "<<id<<" in inventory!"<<endl;
                break;
            }
            case 3:{
                cout<<"Enter ID to search by: ";
                int id;
                cin>>id;
                if(flex.search(id))
                    cout<<"Product with ID "<<id<<" found in inventory!"<<endl;
                else
                    cout<<"Could NOT find any Product with ID "<<id<<" in inventory!"<<endl;
                break;
            }
            case 4:{
                inventory highest = flex.getHighestQty();
                cout<<"Highest quantity product in inventory:"<<endl;
                highest.display();
                break;
            }
            case 5:
                break;
            default:{
                cout<<"Invalid choice.";
                break;
            }
        }

    } while(c!=5);
    return 0;
}