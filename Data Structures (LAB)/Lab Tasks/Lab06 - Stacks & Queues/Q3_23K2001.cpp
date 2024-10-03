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
class stacks{
	private:
		node* top;
	public:
		stacks():top(nullptr){}
		void push(string e){
			node* n = new node;
			if(n==nullptr){
				cout<<"Stack overflow occured!"<<endl;
				return;
			}
			n->setData(e);
			n->setNext(top);
			top = n;
		}
		string pop(){
			if(top==nullptr){
				cout<<"Stacks underflow occured!"<<endl;
				return "!";
			}
			string last = top->getData();
			node* temp = top;
			top=top->getNext();
			delete temp;
			return last;
		}
		string peek(){
			if(isEmpty())
				return "!";
			string last = top->getData();
			return last;
		}
		void display(){
			if(top==nullptr){
				cout<<"Stack empty!"<<endl;
				return;
			}
			node* temp = top;
			while(temp!=nullptr){
				cout<<temp->getData()<<endl;
				temp=temp->getNext();
			}

		}
		bool isEmpty(){
			if(top==nullptr)
				return true;
			return false;
		}
};
int main(){
	stacks flex;
	flex.push("Google");
	flex.push("Facebook");
	flex.push("Twitter");
	flex.push("LinkedIn");
	flex.push("Instagram");

	cout<<"Stack list:"<<endl;
	flex.display();
	cout<<endl<<"Popped two sites:"<<endl;
	cout<<flex.pop()<<endl;
	cout<<flex.pop()<<endl;
	cout<<"Top: "<<flex.peek()<<endl;

	cout<<endl<<"Stack list:"<<endl;
	flex.display();
	return 0;
}