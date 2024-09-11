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
			if(head == nullptr){
				head = n;
				tail = n;
			}
			else{
				tail->setNext(n);
				tail = n;
			}
		}
        void deletenode(int val){
			node* before = nullptr;
			node* temp = head;
			while(temp->getData()!=val){
				before = temp;
				temp = temp->getNext();
			}
			before->setNext(temp->getNext());
			delete temp;
		}
        void question9(){
            if(head==nullptr || head->getNext()==nullptr || head->getNext()->getNext()==nullptr){
                cout<<"Not enough nodes in the list."<<endl;
                return;
            }
            node* ones = head;
            node* twos = ones->getNext();

            ones->setNext(ones->getNext()->getNext());
            ones = ones->getNext();
            twos->setNext(nullptr);

            while(ones->getNext()!=nullptr){
                node* temp = ones->getNext()->getNext();
                ones->getNext()->setNext(twos);
                twos = ones->getNext();
                ones->setNext(temp);

                if(temp!=nullptr)
                    ones = temp;
            }
            ones->setNext(twos);
        }
};
int main(){
	singleList flex;
    cout<<"How many elements: ";
    int e;
	int v;
    cin>>e;
    cout<<"Enter "<<e<<" elements: ";
    for(int i=0;i<e;i++){
        cin>>v;
        flex.insertAtEnd(v);
    }
    cout<<endl<<"your List:"<<endl;
	flex.display();

    cout<<"After applying q9 operations:"<<endl;
    flex.question9();
    flex.display();
}