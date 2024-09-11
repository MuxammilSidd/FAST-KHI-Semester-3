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
class flightNode{
	private:
		string name;
		flightNode* next;
		singleList* passengers;
	public:
		flightNode() : next(nullptr),passengers(nullptr){}
		flightNode(string val){
			name = val;
			next = nullptr;
			passengers = nullptr;
		}
		
		string getData(){ return name;}
		void setData(string n){name = n;}
		flightNode* getNext(){return next;}
		void setNext(flightNode* update){next = update;}

		void insertPassenger(string val){ 
            if(passengers == nullptr){ passengers = new singleList(); }
			passengers->insertAtEnd(val); 
			passengers->sortNames();
		}
        void insertPassengers(singleList p){ passengers = &p; }
		void removePassenger(string val){ passengers->deleteNode(val);}
		void checkPassenger(string val){ passengers->check(val); }
		void displayPassengers(){ passengers->display(); }
};
class flightList{
	private:
		flightNode* head;
		flightNode* tail;
	public:
		flightList(){
			head = nullptr;
			tail = nullptr;
		}
		void display(){
			if(head==nullptr){
				cout<<"No flights present in the list."<<endl;
				return;
			}
			flightNode* temp = head;
			while(temp!=nullptr)
			{
				cout<<temp->getData()<<"\n";
				temp=temp->getNext();
			}
			cout<<endl;
		}
		void insertAtEnd(string val)
		{
			flightNode* temp = head;
			flightNode* n = new flightNode(val);
			if(head == NULL){
				head = n;
				tail = n;
			}
			else{
				tail->setNext(n);
				tail = n;
			}
			cout<<"Flight under name: "<<val<<" has been added."<<endl;
		}
		void deleteNode(string val){
			if(head==nullptr){
			cout<<"No flights present in the list."<<endl;
            return;
        	}
        	if (head->getData()==val){
            flightNode* temp = head;
            head = head->getNext();
            delete temp;
			cout<<"Flight under name: "<<val<<" has been cancelled."<<endl;
            return;
        	}

			flightNode* before = nullptr;
			flightNode* temp = head;
			while(temp!=nullptr && temp->getData()!=val){
				before = temp;
				temp = temp->getNext();
				}
			if(temp==nullptr){
				cout<<"No flight was found under name: "<<val<<endl;
				return;
				}

			before->setNext(temp->getNext());
			delete temp;
			cout<<"Flight under name: "<<val<<" has been cancelled."<<endl;
		}
        void checkFlight(string val){
			flightNode* temp = head;
			while(temp!=nullptr && temp->getData()!=val)
				temp = temp->getNext();
			
			if(temp==nullptr)
				cout<<"No flight was found under name: "<<val<<endl;
			else
				cout<<"Flight is approved under name: "<<val<<endl;
		}
        void insert(string fname,string pname){
			flightNode* temp = head;
			while(temp!=nullptr && temp->getData()!=fname)
				temp = temp->getNext();
			
			if(temp==nullptr)
				cout<<"No flight was found under name: "<<fname<<endl;
			else{ temp->insertPassenger(pname); }
		}
        void cancelTicket(string fname,string pname){
			flightNode* temp = head;
			while(temp!=nullptr && temp->getData()!=fname)
				temp = temp->getNext();
			
			if(temp==nullptr)
				cout<<"No flight was found under name: "<<fname<<endl;
			else{ temp->removePassenger(pname); }
		}
        void checkTicket(string fname,string pname){
			flightNode* temp = head;
			while(temp!=nullptr && temp->getData()!=fname)
				temp = temp->getNext();
			
			if(temp==nullptr)
				cout<<"No flight was found under name: "<<fname<<endl;
			else{ temp->checkPassenger(pname); }
		}
};
int main(){
	int c;
	string n1,n2;
    flightList flights;
	singleList passengers;
    cout<<"\t\t***Welcome to SHAANDAAR Airlines Ticket Reservation System***"<<endl;
    do{
        cout<<"1. Add a flight"<<endl;
        cout<<"2. Reserve a ticket"<<endl;
        cout<<"3. Cancel reservation"<<endl;
        cout<<"4. Check a ticket"<<endl;
        cout<<"5. Check a flight"<<endl;
        cout<<"6. Display flights"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Input choice: ";
        cin>>c;

        switch(c){
            case 1:{
                cout<<"Enter flight name: ";
                cin>>n1;
                flights.insertAtEnd(n1);
                break;
			}
            case 2:{
                cout<<"Enter flight name: ";
                cin>>n1;
				cout<<"Enter name to reserve a ticket: ";
				cin>>n2;
                
                flights.insert(n1,n2);
                break;
			}
            case 3:{
                cout<<"Enter flight name: ";
                cin>>n1;
				cout<<"Enter name to cancel a ticket: ";
				cin>>n2;
                
                flights.cancelTicket(n1,n2);
                break;
			}
            case 4:{
                cout<<"Enter flight name: ";
                cin>>n1;
				cout<<"Enter name to check a reservation: ";
				cin>>n2;
                
                flights.checkTicket(n1,n2);
                break;
			}
            case 5:{
                cout<<"Enter flight name: ";
                cin>>n1;
                flights.checkFlight(n1);
                break;
			}
            case 6:{
                flights.display();
                break;				
			}
            case 7:
                break;
            default:{
                cout<<"Invalid choice!"<<endl;
                break;
			}
        }
        cout<<endl;
    } while(c != 7);

    return 0;
}