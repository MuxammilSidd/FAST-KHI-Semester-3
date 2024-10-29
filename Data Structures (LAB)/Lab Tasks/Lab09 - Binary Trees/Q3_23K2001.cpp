//23K2001 - Muzammil
#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node():left(nullptr),right(nullptr){}
        node(int data):data(data),left(nullptr),right(nullptr){}
};
class tree{
    public:
        node* root;
        tree():root(nullptr){}

        void insertNode(int d){
            if(root == nullptr){
                node* n = new node(d);
                root = n;
                return;
            }
            node* temp = root;
            while(1){
                if(temp->data <= d){
                    if(temp->right != nullptr)
                        temp = temp->right;
                    else{
                        temp->right = new node(d);
                        break; 
                    }
                }
                else{
                    if(temp->left != nullptr)
                        temp = temp->left;
                    else{
                        temp->left = new node(d);
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
            if(root->data == key){
                node* deletedNode = root;
                root = helper(root);
                return deletedNode;
            }

            node* temp = root;
            while(temp != nullptr){
                if (temp->data > key) {
                    if(temp->left != nullptr && temp->left->data == key){
                        node* deletedNode = temp->left;
                        temp->left = helper(temp->left);
                        return deletedNode;
                    } 
                    else
                        temp = temp->left;
                } 
                else{
                    if(temp->right != nullptr && temp->right->data == key){
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
        bool search(int val){
            if(root == nullptr) 
                return false;
            node* temp = root;
            while(temp != nullptr){
                if(temp->data == val)
                    return true;
                else if(temp->data < val)
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
		    cout<<r->data<<" ";
		    inOrder(r->right);
		}

        int greatestLeft(node* root){
            if(root == nullptr)
                return -2147483648;
            while(root->right)
                root = root->right;
            
            return root->data;
        }
        int lowestRight(node* root){
            if(root == nullptr)
                return 2147483647;
            while(root->left)
                root = root->left;
            
            return root->data;
        }
        bool checkBST(){ return checkBST(root); }
        bool checkBST(node* root){
            if(root == nullptr)
                return true;
            
            int leftMax = greatestLeft(root->left);
            int rightMin = lowestRight(root->right);
            if((root->left && leftMax >= root->data) || (root->right && rightMin <= root->data))
                return false;
            return checkBST(root->left) && checkBST(root->right);
        }
};
int main(){
    tree flex;
    flex.insertNode(10);
    flex.insertNode(5);
    flex.insertNode(20);
    flex.insertNode(25);
    flex.insertNode(30);

    cout<<"Elements in the tree through inOrder traversal:"<<endl;
    flex.inOrder();
    
    cout<<endl<<endl;
    if(flex.checkBST(flex.root))
        cout<<"This tree is a Binary-Search Tree!"<<endl;
    else
        cout<<"NOT a Binary-Search Tree!"<<endl;

    node* flex2 = new node(10);
    flex2->left = new node(6);
    flex2->right = new node(13);
    flex2->left->left = new node(1);
    flex2->left->right = new node(12);
    flex2->right->left = new node(9);
    flex2->right->right = new node(14);

    cout<<endl<<"Elements in the tree through inOrder traversal:"<<endl;
    flex.inOrder(flex2);
    
    cout<<endl<<endl;
    if(flex.checkBST(flex2))
        cout<<"This tree is a Binary-Search Tree!"<<endl;
    else
        cout<<"NOT a Binary-Search Tree!"<<endl;
    return 0;
}