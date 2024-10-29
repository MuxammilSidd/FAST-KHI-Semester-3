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
        void getCount(int a,int b,node* r,int &count){
            if(r == nullptr)
                return;
            if(r->data >= a &&  r->data <= b)
                count++;
            
            getCount(a,b,r->left , count);
            getCount(a,b,r->right , count);
        }
        int nodesInRange(int a,int b){
            int n=0;
            getCount(a,b,root,n);
            return n;
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
    cout<<endl<<endl<<"Provide range: [a,b]"<<endl;
    int x,y;
    cin>>x>>y;
    int count = flex.nodesInRange(x,y);
    cout<<endl<<"Nodes present in the range ["<<x<<","<<y<<"] : "<<count<<endl;
    return 0;
}