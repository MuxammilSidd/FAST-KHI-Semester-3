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
			node* before = nullptr;
			node* temp = head;
			int i=0;
			while(temp->getData()!=val){
				before = temp;
				temp = temp->getNext();
			}
			before->setNext(temp->getNext());
			delete temp;
		}
        void rotateList(int e) {
            if (head == nullptr || e <= 0) { return; }

            node* temp = head;
            node* before = nullptr;
            int n=1;
            while(temp->getNext()!=nullptr){
                temp=temp->getNext();
                n++;
            }
            
            e=e%n;
            if(e==0){ return;}
            
            temp=head;
            for (int i=0; i<e; i++){
                before = temp;
                temp = temp->getNext();
            }

            node* newHead = temp;
            before->setNext(nullptr);

            node* end = newHead;
            while (end->getNext() != nullptr)
                end = end->getNext();

            end->setNext(head);
            head = newHead;
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
    cout<<"How many elements to move to end? ";
    cin>>e;
    flex.rotateList(e);

    cout<<"After rotation:"<<endl;
    flex.display();
    return 0;
}