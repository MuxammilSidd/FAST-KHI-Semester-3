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
class circularList{
	private:
		node* head;
		node* tail;
	public:
		circularList(){
			head = nullptr;
			tail = nullptr;
		}
		void display(){
			node* temp = head;
			if(temp!=nullptr){
				do{
					cout<<temp->getData()<<"\t";
					temp=temp->getNext();
				} while(temp!=tail->getNext());
			}
			cout<<endl;
		}
		
		void insertAtStart(int val)	
		{
            node* n = new node(val);
            if(head==nullptr){
                head = n;
                tail = n;
                tail->setNext(head);
            } 
			else{
                n->setNext(head);
                head = n;
                tail->setNext(head);
            }
		}
		void insertAtEnd(int val)
		{
			node* n = new node(val);
			if(head == NULL){
				head = n;
				tail = n;
                tail->setNext(head);
			}
			else{
				tail->setNext(n);
				tail = n;
                tail->setNext(head);
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

        	if(head->getData()==val){
				node* temp = head;

				if(head->getNext()==head){
					head = nullptr;
					tail = nullptr;
				} 
				else{
					head = head->getNext();
					tail->setNext(head);
				}

				delete temp;
				return;
			}

        node* before = nullptr;
        node* temp = head;
        while(temp->getNext()!=head && temp->getData()!=val){
            before = temp;
            temp = temp->getNext();
        	}

        if(temp->getNext()==head && temp->getData()!=val){
            cout<<val<<" was not found in this list."<<endl;
            return;
        	}

        before->setNext(temp->getNext());
		if(temp==tail)
        	tail = before;
        delete temp;
    	}
};
int main(){
    circularList flex;
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

    cout<<endl<<"Adding 9 in end:"<<endl;
	flex.insertAtEnd(9);
	flex.display();
	
	cout<<endl<<"Adding 11 at pos 3:"<<endl;
	flex.insertAtIndex(3,11);
	flex.display();
	
	cout<<endl<<"Adding 4 at start:"<<endl;
	flex.insertAtStart(4);
	flex.display();
	
	cout<<endl<<"Deleting 1,2 & 9:"<<endl;
	flex.deleteNode(1);
	flex.deleteNode(2);
	flex.deleteNode(9);
	flex.display();
    return 0;
}