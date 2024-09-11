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
		void evenFirst(){
			node* temp = head;
			singleList evens;
			singleList odds;
			while(temp!=nullptr){
				if(temp->getData()%2==0)
					evens.insertAtEnd(temp->getData());
				else
					odds.insertAtEnd(temp->getData());
				temp = temp->getNext();
			}
			temp = head;
			while(temp!=nullptr){
				node* next = temp->getNext();
				delete temp;
				temp = next;
			}
			head = nullptr;

			if(evens.head==nullptr){
				cout<<"No even elements were found!"<<endl;
				head = odds.head;
			}
			else{
				head = evens.head;
				evens.tail->setNext(odds.head);
			}

			if(odds.tail==nullptr){
				cout<<"No odd elements were found!"<<endl;
				tail = evens.tail;
			}
			else
				tail = odds.tail;
		}
};
int main(){
	singleList flex;
    cout<<"How many elements: ";
    int e,v;
    cin>>e;
    cout<<"Enter "<<e<<" elements: ";
    for(int i=0;i<e;i++){
        cin>>v;
        flex.insertAtEnd(v);
    }
    cout<<endl<<"your List:"<<endl;
	flex.display();

	cout<<endl<<"After arranging even elements first:"<<endl;
	flex.evenFirst();
	flex.display();
	return 0;
}