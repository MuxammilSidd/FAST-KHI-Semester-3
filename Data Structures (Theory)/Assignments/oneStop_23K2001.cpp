//23K2001 - Muzammil
#include<iostream>
using namespace std;

class ticket{
    public:
        int id, priority;
        string name, desc;
        string creation, close;
        bool status;

        ticket(){}
        void const operator =(const ticket t){
            this->id = t.id;
            this->priority = t.priority;
            this->name = t.name;
            this->desc = t.desc;
            this->creation = t.creation;
            this->close = t.close;
            this->status = t.status;
        }
        void showTicketData(){
            cout<<"Ticket ID: "<<id<<endl;
            cout<<"Customer Name: "<<name<<endl;
            cout<<"Priority: "<<priority<<endl;
            cout<<"Description: "<<desc<<endl;
            cout<<"Creation Time: "<<creation;
            cout<<"\tClose Time: "<<close<<endl;
            cout<<"Status: "<<status<<endl;
        }
};

class node{
    public:
        ticket t;
        node* next;

        node():next(nullptr){}
        node(ticket t):t(t),next(nullptr){}
        void getData(){ t.showTicketData(); }
        node* getNext(){ return next; }
        void setNext(node* n){ next = n; }
        void setData(ticket t){ this->t = t; }
};

class singleList{
    public:
        node* head;
        node* tail;
        singleList() : head(nullptr), tail(nullptr){}
        void display(){
            if(!head){
                cout<<"List is empty!"<<endl;
                return;
            }
            node* temp = head;
            while(temp){
                cout<<temp->getData()<<"\t";
                temp = temp->getNext();
            }
            cout<<endl;
        }

        void insertAtStart(T d){
            node* n = new node(d);
            n->next = head;
            head = n;
        }
        void insertAtEnd(T d){
            node* n = new node(d);
            if(!head){
                head = n;
                tail = n;
            }
            else{
                tail->next = n;
                tail = n;
            }
        }
        void insertAtIndex(T val, int index){
            if (index < 0) {
                cout << "Invalid index!" << endl;
                return;
            }
            if (index == 0) {
                insertAtStart(val);
                return;
            }
            node* update = new node(val);
			node* temp = head;
			node* before = nullptr;
			for(int i=0;temp != nullptr && i<index-1;i++){
				before = temp;
				temp=temp->next;
			}
            if (!temp) {
                cout << "Index out of bounds!" << endl;
                delete update;
                return;
            }
			before->next = update;
			update->next = temp;
        }
        void deleteNode(T d){
            if(!head){
                cout<<"List is empty!"<<endl;
                return;
            }
            node* before = nullptr;
            node* temp = head;
            while(temp->getData()!=d){
                before = temp;
                temp = temp->next;
            }
            if(!temp){
                cout<<"Value "<<d<<" not found in the list."<<endl;
                return;
            }
            if(temp == head) 
                head = head->next;
            else
                before->next = temp->next;
            
            delete temp;
            cout<<"node with value "<<d<<" deleted.\n";
        }
};

class agent{
    public: 
        int id;
        string name;
        bool availability;

        agent(){}
        
};


int main(){
    cout<<"h";
    return 0;
}