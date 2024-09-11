//23K2001 Muzammil
#include<iostream>
using namespace std;
class node{
	private:
		int data;
		node* next;
		node* prev;
	public:
		node(){next = nullptr;
		prev = nullptr; }
		node(int val){
			data = val;
			next = nullptr;
			prev = nullptr;
		}
		
		int getData(){ return data; }
		node* getNext(){return next;}
		node* getPrev(){return prev;}
		void setNext(node* update){next = update;}
		void setPrev(node* update){prev = update;}
};
class doubleList{
	private:
		node* head;
		node* tail;
	public:
		doubleList(){
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
        node* getHead(){ return head; }
		node* getTail(){ return tail; }
        void setHead(node* update){head = update;}
		void setTail(node* update){tail = update;}

		void insertAtStart(int val)	
		{
			node* n = new node(val);
			n->setNext(head);
            head->setPrev(n);
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
                n->setPrev(tail);
				tail = n;
			}
		}

		friend void concatenate(doubleList &l,doubleList &m);
};

void concatenate(doubleList &l,doubleList &m){
    if(l.getHead()==nullptr || m.getHead()==nullptr){
        cout<<"One of the provided list was empty."<<endl;
        return;
    }

    l.getTail()->setNext(m.getHead());
    m.getHead()->setPrev(l.getTail());
    l.setTail(m.getTail());
}

int main(){
	doubleList flex1,flex2;
    cout<<"How many elements for list#1: ";
    int e;
	int v;
    cin>>e;
    cout<<"Enter "<<e<<" elements: ";
    for(int i=0;i<e;i++){
        cin>>v;
        flex1.insertAtEnd(v);
    }
	cout<<"How many elements for list#2: ";
    cin>>e;
    cout<<"Enter "<<e<<" elements: ";
    for(int i=0;i<e;i++){
        cin>>v;
        flex2.insertAtEnd(v);
    }
    cout<<endl<<"your List#1:"<<endl;
	flex1.display();
	cout<<endl<<"your List#2:"<<endl;
	flex2.display();

	cout<<endl<<"After concatenation:"<<endl;
	concatenate(flex1,flex2);
	cout<<"List 1: ";
	flex1.display();
	cout<<"List 2: ";
	flex2.display();
	return 0;
}