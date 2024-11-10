//23K2001 - Muzammil
#include<iostream>
using namespace std;

class node{
    public:
        int data,height,subTree;
        node* left;
        node* right;
        node():left(nullptr),right(nullptr){}
        node(int data):data(data),height(1),subTree(1),left(nullptr),right(nullptr){}
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
            root->subTree = 1 + subTreeSize(root->left) + subTreeSize(root->right);
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
        int subTreeSize(node* root){ return root ? root->subTree : 0; }

        node* rightRotate(node* y){
            node* x = y->left;
            node* temp = x->right;

            x->right = y;
            y->left = temp;

            y->height = 1 + max(getHeight(y->left) , getHeight(y->right));
            y->subTree = 1 + subTreeSize(y->left) + subTreeSize(y->right);
            x->height = 1 + max(getHeight(x->left) , getHeight(x->right));
            x->subTree = 1 + subTreeSize(x->left) + subTreeSize(x->right);

            return x;
        }

        node* leftRotate(node* x){
            node* y = x->right;
            node* temp = y->left;

            y->left = x;
            x->right = temp;
            
            x->height = 1 + max(getHeight(x->left) , getHeight(x->right));
            x->subTree = 1 + subTreeSize(x->left) + subTreeSize(x->right);
            y->height = 1 + max(getHeight(y->left) , getHeight(y->right));
            y->subTree = 1 + subTreeSize(y->left) + subTreeSize(y->right);

            return y;
        }

        int getSmallest(node*root , int k){
            if(root==nullptr || k < 1 || k > root->subTree)
                return -1;

            int left = subTreeSize(root->left);
            if(k <= left)
                return getSmallest(root->left,k);
            else if(k == left + 1)
                return root->data;
            else
                return getSmallest(root->right,k-left-1);
        }

        int getLargest(node*root , int k){
            if(root==nullptr || k < 1 || k > root->subTree)
                return -1;

            int right = subTreeSize(root->right);
            if(k <= right)
                return getLargest(root->right,k);
            else if(k == right + 1)
                return root->data;
            else
                return getLargest(root->left,k-right-1);
        }
};
int main(){
    tree flex;
    flex.insertNode(10);
    flex.insertNode(5);
    flex.insertNode(15);
    flex.insertNode(3);
    flex.insertNode(7);
    flex.insertNode(12);

    cout<<endl<<"Elements in the tree through preOrder traversal:"<<endl;
    flex.preOrder();

    int k = 2;
    int l = flex.getLargest(flex.root,k);
    if(l != -1)
        cout<<endl<<"Kth (k=2) Largest: "<<l<<endl;
    else
        cout<<endl<<"Out of bound!"<<endl;

    k = 3;
    int s = flex.getSmallest(flex.root,k);
    if(s != -1)
        cout<<endl<<"Kth (k=3) Smallest: "<<s<<endl;
    else
        cout<<endl<<"Out of bound!"<<endl;
    return 0;
}
