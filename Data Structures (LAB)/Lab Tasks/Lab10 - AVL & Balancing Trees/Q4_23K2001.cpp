//23K2001 - Muzammil
#include<iostream>
using namespace std;

class node{
    public:
        int data,height;
        node* left;
        node* right;
        node():left(nullptr),right(nullptr){}
        node(int data):data(data),height(1),left(nullptr),right(nullptr){}
};
class tree{
    public:
        node* root;
        tree():root(nullptr){}

        node* insertNode(node* root,int d){
            if(root == nullptr) return new node(d);
            
            if(d < root->data)
                root->left = insertNode(root->left , d);
            else if(d > root->data)
                root->right = insertNode(root->right , d);
            
            root->height = 1 + max(getHeight(root->left) , getHeight(root->right));
            int balance = getBalance(root);

            if (balance > 1 && d < root->left->data)
                return rightRotate(root);
            if (balance < -1 && d > root->right->data)
                return leftRotate(root);

            if (balance > 1 && d > root->left->data){
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            if (balance < -1 && d < root->right->data){
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }

            return root; 
        }
        void insertNode(int d){ root = insertNode(root,d);  }
        void preOrder(){ preOrder(root); }
        void preOrder(node* r){
    		if(r == nullptr)
        		return;

		    cout<<r->data<<" ";
		    preOrder(r->left);
		    preOrder(r->right);
		}
        int getHeight(node* r){
            if(r == nullptr) 
                return 0;
            return r->height;
        }
        int getBalance(node* root){  return(getHeight(root->left) - getHeight(root->right)); }

        node* rightRotate(node* y){
            node* x = y->left;
            node* temp = x->right;

            x->right = y;
            y->left = temp;

            y->height = 1 + max(getHeight(y->left) , getHeight(y->right));
            x->height = 1 + max(getHeight(x->left) , getHeight(x->right));
            return x;
        }

        node* leftRotate(node* x){
            node* y = x->right;
            node* temp = y->left;

            y->left = x;
            x->right = temp;
            
            x->height = 1 + max(getHeight(x->left) , getHeight(x->right));
            y->height = 1 + max(getHeight(y->left) , getHeight(y->right));
            return y;
        }
};
int main(){
    tree flex;
    flex.insertNode(10);
    cout<<endl<<"Balance Factor of node with value '10' : "<<flex.getBalance(flex.root)<<endl;
    flex.insertNode(5);
    cout<<"Balance Factor of node with value '5' : "<<flex.getBalance(flex.root)<<endl;
    flex.insertNode(15);
    cout<<"Balance Factor of node with value '15' : "<<flex.getBalance(flex.root)<<endl;
    flex.insertNode(3);
    cout<<"Balance Factor of node with value '3' : "<<flex.getBalance(flex.root)<<endl;
    flex.insertNode(7);
    cout<<"Balance Factor of node with value '7' : "<<flex.getBalance(flex.root)<<endl;

    cout<<endl<<"Elements in the tree through preOrder traversal:"<<endl;
    flex.preOrder();
    flex.insertNode(12);
    cout<<endl<<endl<<"Balance Factor of node with value '12' : "<<flex.getBalance(flex.root)<<endl;
    cout<<endl<<"preOrder traversal after adding node with value '12':"<<endl;
    flex.preOrder();

    cout<<endl<<endl<<"Height of the AVL Tree: "<<flex.getHeight(flex.root);

    return 0;
}
