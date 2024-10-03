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
		int size;
	public:
		singleList(){
			head = nullptr;
			tail = nullptr;
			size = 0;
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
			size++;
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
			size++;
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
			size++;
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
			size--;
		}
		void reverseMN(int m,int n){
			if (head==nullptr || m < 1 || n > size || m >= n){
				cout<<"Error applying function!"<<endl;
            	return; 
			} 
        
        node* current = head;
        node* before = nullptr;
        node* newTail = nullptr;

        for (int i = 1; i < m; i++) {
            before = current;
            current = current->getNext();
        }

        newTail = current;
        node* next = nullptr; 
        for (int i = m; i <= n; i++) {
            next = current->getNext(); 
            current->setNext(before); 
            before = current;           
            current = next;         
        }

        if (before != nullptr) {
            if (m == 1)
                head = before; 
            else 
			{
                node* temp = head;
                for (int i = 1; i < m - 1; i++)
                    temp = temp->getNext();
                
                temp->setNext(before);
            }
        }

        newTail->setNext(current);
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

	cout<<"Enter indexes MxN to reverse: ";
	int m,n;
	cin>>m>>n;
	cout<<endl<<"After reversing from M to N:"<<endl;
	flex.reverseMN(m,n);
	flex.display();
	return 0;
}