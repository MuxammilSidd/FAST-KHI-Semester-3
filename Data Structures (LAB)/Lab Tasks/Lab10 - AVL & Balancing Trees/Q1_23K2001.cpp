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
        int getBalance(node*root){  return(getHeight(root->left) - getHeight(root->right)); }

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

        node* convertAVL(node* root){
            if(root == nullptr)
                return root;

            int balance = getBalance(root);
            if(balance > 1){
                if(getBalance(root->left) >= 0)
                    return  rightRotate(root);
                else{
                    root->left = leftRotate(root); 
                    return rightRotate(root);
                }
            }
            else if(balance < -1){
                    if(getBalance(root->right) <= 0)
                        return leftRotate(root);
                    else{
                            root->right = rightRotate(root->right);
                            return leftRotate(root);
                    }
            }
            
            return root;
        }
};
int main(){
    tree flexA;
    flexA.insertNode(10);
    flexA.insertNode(6);
    flexA.insertNode(8);
    flexA.insertNode(4);

    cout<<"Elements in the tree through preOrder traversal:"<<endl;
    flexA.preOrder();
    flexA.root = flexA.convertAVL(flexA.root);
    cout<<endl<<endl<<"After conversion to AVL:"<<endl;
    flexA.preOrder();

    tree flexB;
    flexB.insertNode(10);
    flexB.insertNode(16);
    flexB.insertNode(12);
    flexB.insertNode(18);

    cout<<endl<<endl<<"Elements in the tree through preOrder traversal:"<<endl;
    flexB.preOrder();
    flexB.root = flexB.convertAVL(flexB.root);
    cout<<endl<<endl<<"After conversion to AVL:"<<endl;
    flexB.preOrder();
    return 0;
}

// AVL trees keep themselves balanced, so they’re faster for searching, inserting,
// and deleting compared to regular binary trees. The balance makes them efficient,
// especially when data is constantly being added or removed.