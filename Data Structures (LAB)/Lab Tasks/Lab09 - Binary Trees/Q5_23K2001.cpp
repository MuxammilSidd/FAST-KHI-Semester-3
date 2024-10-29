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
        void inOrder(){ inOrder(root); }
        void inOrder(node* r){
    		if(r == nullptr)
        		return;

		    inOrder(r->left);
		    cout<<r->data<<" ";
		    inOrder(r->right);
		}
        void getSize(node* r,int &count){
            if(r == nullptr)
                return;
            count++;
            getSize(r->left, count);
            getSize(r->right, count);
        }
        void move(node* r, node*& curr, node*& prev, int &count, int pos, int &val){
            if(r == nullptr || val != -1) 
                return;
            
            move(r->left, curr, prev, count, pos, val);
            prev = curr;    
            curr = r;   
            count++;

            if (count == pos)
                val = curr->data;
            else if (count == pos + 1)
                val = (prev->data + curr->data) / 2;
            
            move(r->right, curr, prev, count, pos, val);
        }
        int getMedian(){
            int count = 0;
            getSize(root, count);

            node* curr = nullptr;
            node* prev = nullptr;
            int pos = (count+1)/2; 
            int val = -1;
            count = 0;  

            move(root, curr, prev, count, pos, val);
            return val;
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
    
    cout<<endl<<endl<<"Median value:"<<flex.getMedian()<<endl;
    return 0;
}