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
        void search(int val){
            if(root == nullptr){
                cout<<"Tree empty!"<<endl;
                cout<<"Inserting root node with value: "<<val<<endl;
                insertNode(val);
                return;
            } 
            node* temp = root;
            while(temp != nullptr){
                if(temp->data == val){
                    cout<<"Node with value: "<<val<<" is present in the tree!"<<endl;
                    return;
                }
                else if(temp->data < val)
                    temp = temp->right;
                else
                    temp = temp->left;
            }
            cout<<"Node with value: "<<val<<" was not found!"<<endl;
            cout<<"Inserting node with value: "<<val<<endl;
            insertNode(val);
        }
        void inOrder(){ inOrder(root); }
        void inOrder(node* r){
    		if(r == nullptr)
        		return;

		    inOrder(r->left);
		    cout<<r->data<<" ";
		    inOrder(r->right);
		}
};
int main(){
    tree flex;
    flex.insertNode(27);
    flex.insertNode(25);
    flex.insertNode(90);
    flex.insertNode(15);
    flex.insertNode(42);

    cout<<"Elements in the tree through inOrder traversal:"<<endl;
    flex.inOrder();
    int x;
    cout<<endl<<"Enter element to search: ";
    cin>>x;
    cout<<endl;
    flex.search(x);
    cout<<endl<<"Elements in the tree after search() function:"<<endl;
    flex.inOrder();
    return 0;
}