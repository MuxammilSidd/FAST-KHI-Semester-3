//23K2001 Muzammil
#include<iostream>
using namespace std;
class node{
	private:
		char data;
		node* next;
	public:
		node(){next = nullptr;}
		node(char val){
			data = val;
			next = nullptr;
		}
		char getData(){ return data;}
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
		
		void insertAtStart(char val)	
		{
			node* n = new node(val);
			n->setNext(head);
			head = n;
		}
		void insertAtEnd(char val)
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
		void checkPalindrome(){
			if(head==nullptr || head->getNext()==nullptr){
				cout<<"This list is a palindrome."<<endl;
				return;
			}
			node* one=head;
			singleList reversedList;
			while(one!=nullptr){
				reversedList.insertAtEnd(one->getData());
				one=one->getNext();
			}

            node* prev=nullptr;
            node* current=reversedList.head;
            node* next=nullptr;
            while(current!=nullptr){
                next=current->getNext();
                current->setNext(prev);
                prev=current;
                current=next;
            }
            reversedList.head=prev;
			one=head;
            while(one!=nullptr){
                if(one->getData()!=reversedList.head->getData()){
                cout<<"This list is NOT a palindrome."<<endl;
				return;
				}

                one=one->getNext();
                reversedList.head=reversedList.head->getNext();            
            }
            cout<<"This list is a palindrome."<<endl;
        }
};
int main(){
	singleList flex;
    cout<<"How many elements: ";
    int e;
	char v;
    cin>>e;
    cout<<"Enter "<<e<<" elements: ";
    for(int i=0;i<e;i++){
        cin>>v;
        flex.insertAtEnd(v);
    }
    cout<<endl<<"your List:"<<endl;
	flex.display();

	flex.checkPalindrome();
	return 0;
}