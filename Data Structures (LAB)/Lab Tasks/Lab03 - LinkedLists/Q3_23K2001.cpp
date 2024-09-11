//23K2001 Muzammil
#include<iostream>
using namespace std;
class node{
	private:
		string name;
		node* next;
	public:
		node(){next = nullptr;}
		node(string val){
			name = val;
			next = nullptr;
		}
		
		string getData(){ return name;}
		void setData(string n){name = n;}
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
			if(head==nullptr){
				cout<<"No names present in the list."<<endl;
				return;
			}
			node* temp = head;
			while(temp!=nullptr)
			{
				cout<<temp->getData()<<"\n";
				temp=temp->getNext();
			}
			cout<<endl;
		}
		
		void insertAtStart(string val)	
		{
			node* n = new node(val);
			n->setNext(head);
			head = n;
		}
		void insertAtEnd(string val)
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
			cout<<"Reservation under name: "<<val<<" has been created."<<endl;
		}
		void insertAtIndex(int index,string val){
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
		void deleteNode(string val){
			if(head==nullptr){
			cout<<"No names present in the list."<<endl;
            return;
        	}
        	if (head->getData()==val){
            node* temp = head;
            head = head->getNext();
            delete temp;
			cout<<"Reservation under name: "<<val<<" has been cancelled."<<endl;
            return;
        	}

			node* before = nullptr;
			node* temp = head;
			while(temp!=nullptr && temp->getData()!=val){
				before = temp;
				temp = temp->getNext();
				}
			if(temp==nullptr){
				cout<<"No reservation was found under name: "<<val<<endl;
				return;
				}

			before->setNext(temp->getNext());
			delete temp;
			cout<<"Reservation under name: "<<val<<" has been cancelled."<<endl;
		}
		void check(string val){
			node* temp = head;
			while(temp!=nullptr && temp->getData()!=val)
				temp = temp->getNext();
			
			if(temp==nullptr)
				cout<<"No reservation was found under name: "<<val<<endl;
			else
				cout<<"Ticket is reserved under name: "<<val<<endl;
		}
		void sortNames(){
			if (head==nullptr || head->getNext()==nullptr) return;
			bool swapped;
			do{
				swapped = false;
				node* current = head;
				node* prev = nullptr;
				
				while(current!=nullptr && current->getNext()!=nullptr) {
					if(current->getData() > current->getNext()->getData()){
						string temp = current->getData();
						current->setData(current->getNext()->getData());
						current->getNext()->setData(temp);
						swapped = true;
					}
					prev = current;
					current = current->getNext();
				}
			} while(swapped);
		}
};
int main(){
	int c;
	string n;
	singleList passengers;
    cout<<"\t\t***Welcome to SHAANDAAR Airlines Ticket Reservation System***"<<endl;
    do{
        cout<<"1. Reserve a ticket"<<endl;
        cout<<"2. Cancel reservation"<<endl;
        cout<<"3. Check ticket"<<endl;
        cout<<"4. Display passengers"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Input choice: ";
        cin>>c;

        switch(c){
            case 1:{
				cout<<"Enter name to reserve a ticket: ";
				cin>>n;
                passengers.insertAtEnd(n);
				passengers.sortNames();
                break;
			}
            case 2:{
                cout<<"Enter name to cancel a reservation: ";
				cin>>n;
                passengers.deleteNode(n);
                break;
			}
            case 3:{
                cout<<"Enter name to check a reservation: ";
				cin>>n;
                passengers.check(n);
                break;
			}
            case 4:{
                passengers.display();
                break;				
			}
            case 5:
                break;
            default:{
                cout<<"Invalid choice!"<<endl;
                break;
			}
        }
        cout<<endl;
    } while(c != 5);
    return 0;
}