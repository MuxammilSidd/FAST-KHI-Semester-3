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
			if(head == NULL){
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
			if(head==nullptr){
			cout<<"The list is empty."<<endl;
            return;
        	}

        	if (head->getData()==val){
            node* temp = head;
            head = head->getNext();
            delete temp;
            return;
        	}

        node* before = nullptr;
        node* temp = head;
        while(temp!=nullptr && temp->getData()!=val){
            before = temp;
            temp = temp->getNext();
        	}

        if(temp==nullptr){
            cout<<val<<" was not found in this list."<<endl;
            return;
        	}

        before->setNext(temp->getNext());
        delete temp;
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
    cout<<"Which element to delete? ";
    cin>>e;
    flex.deleteNode(e);

    cout<<"After deletion:"<<endl;
    flex.display();
    return 0;
}