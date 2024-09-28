//23K2001 - Muzammil
#include<iostream>
using namespace std;
class node{
	private:
		string data;
		node* next;
	public:
		node() : next(nullptr){}
		node(string s) : next(nullptr), data(s){}
		string getData(){ return data; }
		void setData(string s){ data=s; }
		node* getNext(){ return next; }
		void setNext(node* n){ next=n; } 
};
class singleList{
	private:
		node* head;
		node* tail;
	public:
		singleList(){
			head = nullptr;
			tail = nullptr;
		}
		void display(){
			node* temp = head;
			while(temp!=nullptr)
			{
				cout<<temp->getData()<<"\t";
				temp=temp->getNext();
			}
			cout<<endl;
		}
		void insertAtStart(int val)	
		{
			node* n = new node(val);
			n->setNext(head);
			head = n;
		}
		void insertAtEnd(int val)
		{
			node* temp = head;
			node* n = new node(val);
			if(head == NULL){
				head = n;
				tail = n;
			}
			else{
				tail->setNext(n);
				tail = n;
			}
		}
		void insertAtIndex(int index,int val){
			node* update = new node(val);
			node* temp = head;
			node* before = nullptr;
			for(int i=0;i<index-1;i++){
				before = temp;
				temp=temp->getNext();
			}
			before->setNext(update);
			update->setNext(temp);
		}
		void deleteNode(int val){
			node* before = nullptr;
			node* temp = head;
			while(temp->getData()!=val){
				before = temp;
				temp = temp->getNext();
			}
			before->setNext(temp->getNext());
			delete temp;
		}
};
class stacks{
	private:
		int top,size;
	public:
		singleList list;
		stacks():top(-1),size(0),list(nullptr){}
		stacks(int s):top(-1),size(s){
			// arr = new string[size];
			// for(int i=0;i<size;i++)
			// 	arr[i]="!";
			
		}
		
		void push(string e){
			if(top>=(size-1)){
				cout<<"Stack overflow occured!"<<endl;
				return;
			}
			arr[++top] = e;
		}
		string pop(){
			if(top<0){
				cout<<"Stacks underflow occured!"<<endl;
				return "!";
			}
			string last = arr[top--];
			return last;
		}
		
		bool checkPalindrome(){
			stacks reversed(this->size);
			for(int i=0;i<size;i++)
				reversed.push(this->arr[i]);
			
			for(int i=0;i<size;i++){
				if(this->arr[i]!=reversed.pop())
					return false;
			}
			return true;
		}
		bool isEmpty(){
			if(top<0)
				return true;
			return false;
		}
		~stacks(){ delete[] arr; }
};
int main(){
	int s;
	cout<<"Enter to-do list size: ";
	cin>>s;
	stacks flex(s);
	string e;
	cout<<"Enter "<<s-1<<" tasks:"<<endl;
	for(int i=0;i<s-1;i++){
		cin>>e;
		flex.push(e);
	}
	cout<<endl<<"Enter a task to add to top:"<<endl;
	cin>>e;
	flex.push(e);
	cout<<endl<<"Checking if stack is empty:"<<endl;
	if(flex.isEmpty())
		cout<<"Yes!"<<endl;
	else
		cout<<"No!"<<endl;
		
	cout<<endl<<"Removing top task from the list."<<endl;
	e = flex.pop();
	cout<<"Last task was: "<<e<<endl;
	return 0;
}