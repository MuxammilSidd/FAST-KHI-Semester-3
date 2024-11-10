//23K2001 - Muzammil
#include<iostream>
using namespace std;

class student{
    public:
        string name;
        int rollnum;

        student():name(""),rollnum(0){}

        student(string name,int rollnum):name(name),rollnum(rollnum){}
};
class node{
    public:
        student s;
        int height;
        node* left;
        node* right;
        node():left(nullptr),right(nullptr){}
        node(student &s):s(s),height(1),left(nullptr),right(nullptr){}
};
class tree{
    public:
        node* root;
        tree():root(nullptr){}

        node* insertNode(node* root,student &st){
            if (root == nullptr) 
                return new node(st);
            
            if (st.rollnum < root->s.rollnum)
                root->left = insertNode(root->left, st);
            else if (st.rollnum > root->s.rollnum)
                root->right = insertNode(root->right, st);
            else
                return root;

            root->height = 1 + max(getHeight(root->left), getHeight(root->right));
            int balance = getBalance(root);

            if (balance > 1 && st.rollnum < root->left->s.rollnum)
                return rightRotate(root);
            if (balance < -1 && st.rollnum > root->right->s.rollnum)
                return leftRotate(root);

            if (balance > 1 && st.rollnum > root->left->s.rollnum){
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            if (balance < -1 && st.rollnum < root->right->s.rollnum) {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            return root;
        }
        void insertNode(student &st){ root = insertNode(root,st);  }
        void inOrder(){ inOrder(root); }
        void inOrder(node* r){
    		if(r == nullptr)
        		return;

		    inOrder(r->left);
		    cout<<"Name: "<<r->s.name<<"\tRoll#: "<<r->s.rollnum<<endl;
		    inOrder(r->right);
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
};
int main(){
    tree flex;
    student s1("Muzammil", 10);
    student s2("Ali", 20);
    student s3("Armagahan", 30);
    student s4("Danish", 40);
    student s5("Sohail", 50);
    flex.insertNode(s1);
    flex.insertNode(s2);
    flex.insertNode(s3);
    flex.insertNode(s4);
    flex.insertNode(s5);

    cout<<"Students in the tree through inOrder traversal:"<<endl;
    flex.inOrder();

    student s6("Huzaima",15);
    flex.insertNode(s6);
    cout<<endl<<"inOrder traversal after adding Student with Roll# 15:"<<endl;
    flex.inOrder();
    cout<<endl<<"Height of the AVL Tree: "<<flex.getHeight(flex.root);
    return 0;
}
