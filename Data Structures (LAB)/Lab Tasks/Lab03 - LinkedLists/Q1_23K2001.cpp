//23K2001 Muzammil
#include<iostream>
using namespace std;
class node{
	private:
		int data;
		node* next;
	public:
		node(){next = nullptr;}
		node(int val){
			data = val;
			next = nullptr;
		}
		
		int getData(){ return data;}
		node* getNext(){return next;}
		void setNext(node* update){next = update;}
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
			node* temp =  head;
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
			if(head == nullptr){
				head = n;
				tail = n;
			}
			else{
				tail->setNext(n);
				tail = tail->getNext();
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

int main(){
	int arr[] = {3,1,2,5,8};
	cout<<"Array:"<<endl;
	for(int i:arr)
	cout<<i<<endl;
	
	singleList arrList;
	for(int i:arr)
	arrList.insertAtEnd(i);
	
	cout<<endl<<"SingleLinked List:"<<endl;
	arrList.display();
	
	cout<<endl<<"Adding 9 in end:"<<endl;
	arrList.insertAtEnd(9);
	arrList.display();
	
	cout<<endl<<"Adding 11 at pos 3:"<<endl;
	arrList.insertAtIndex(3,11);
	arrList.display();
	
	cout<<endl<<"Adding 4 at start:"<<endl;
	arrList.insertAtStart(4);
	arrList.display();
	
	cout<<endl<<"Deleting 1,2 & 5:"<<endl;
	arrList.deleteNode(1);
	arrList.deleteNode(2);
	arrList.deleteNode(5);
	arrList.display();
	
	return 0;
}