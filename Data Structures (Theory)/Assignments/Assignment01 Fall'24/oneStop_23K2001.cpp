//23K2001 - Muzammil - Assignment01: OneStop Ticket Management System
#include<iostream>
#include<conio.h> //Used for clear screen function
#include<ctime> //Used for the time functions below, to give time taken by a function
using namespace std;

clock_t startingTime,endingTime;
void startClock(){ startingTime = clock(); }
void endClock(){ endingTime = clock(); }
void getTimeTaken(){ cout<<"\n\tProccessed in "<<double(endingTime - startingTime) / CLOCKS_PER_SEC<<" second."<<endl; }
string getCurrentTime(){    //To get current time while creating a ticket
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);
    char timeStr[9];
    strftime(timeStr, sizeof(timeStr), "%H-%M-%S", localTime);
    return timeStr;
}

class ticket{
    public:
        int id, priority;   // 1 - Hi, 2 - Med, 3 - Lo (Priority)
        string name, desc;
        string creation, close;
        bool status;

        ticket(){   //Default constructor for ticket, setting as open everytime one is created, creation time = current time
            id = -1;
            priority = 0;
            name = desc = "";
            creation = getCurrentTime();
            close = "XX-XX-XX";
            status = true;
        }
        ticket(int id,int priority,string name,string desc,string creation,string close,bool status){
            this->id = id;
            this->priority = priority;
            this->name = name;
            this->desc = desc;
            this->creation = creation;
            this->close = close;
            this->status = status;
        }
        void const operator =(const ticket t){  // = Operator overloading as precaution
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
            cout<<"Status: ";
            status ? cout<<"Open"<<endl : cout<<"Closed"<<endl;
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
        bool display(){ //Bool is being used to facilitate later checks (break the case if list is empty)
            if(!head){
                cout<<"Ticket list is empty!"<<endl;
                return false;
            }
            node* temp = head;
            int i=0;
            while(temp){
                cout<<"Ticket#"<<++i<<endl;
                temp->getData();
                cout<<endl;
                temp = temp->getNext();
            }
            return true;
        }
        void insertAtEnd(ticket d){
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
        void deleteNode(int id){    //For removing ticket, find & then delete
            if(!head){
                cout<<"Ticket list is empty!"<<endl;
                return;
            }
            node* before = nullptr;
            node* temp = head;
            while(temp->t.id!=id){
                before = temp;
                temp = temp->next;
            }
            if(!temp){
                cout<<"Ticket with ID#: "<<id<<" not found."<<endl;
                return;
            }
            if(temp == head) 
                head = head->next;
            else
                before->next = temp->next;
            
            delete temp;
            cout<<"Ticket with ID#: "<<id<<" removed.\n";
        }
        bool search(){  //With prompt to search according to user's choice
            cout<<"Would you like to search by ID or Name ? 1 (ID) : 0 (Name)"<<endl;
            int ch;
            cin>>ch;
            if(ch){
                int id;
                cout<<"Enter ID to search: ";
                cin>>id;
                startClock();
                node* temp = head;
                while(temp!=nullptr && temp->t.id!=id)
                    temp = temp->next;
                
                if(temp==nullptr)
                    cout<<"No ticket was found with ID#: "<<id<<endl;
                else
                    cout<<"Ticket with ID#: "<<id<<" is present."<<endl;

                endClock();
                getTimeTaken();
            }
            else{
                string name;
                cout<<"Enter name to search: ";
                cin>>name;
                startClock();
                node* temp = head;
                while(temp!=nullptr && temp->t.name!=name)
                    temp = temp->next;
                
                if(temp==nullptr)
                    cout<<"No ticket was found with Name: "<<name<<endl;
                else
                    cout<<"Ticket with Name: "<<name<<" is present."<<endl;

                endClock();
                getTimeTaken();
            }
        }
        void sortTickets(){ //With prompt to sort according to user's choice
            cout<<endl<<"Prioritize Creation Time or Customer Name ? 1 (Time) : 0 (Name)"<<endl;
            int ch;
            cin>>ch;
            if (head==nullptr || head->next==nullptr){
                cout<<"Ticket list is empty."<<endl;
                return;
            }
            startClock();
			bool swapped;
            if(ch){
                do{
                    swapped = false;
                    node* current = head;
                    node* prev = nullptr;
                    while(current!=nullptr && current->next!=nullptr) {
                        if(current->t.creation > current->next->t.creation){
                            ticket temp = current->t;
                            current->t = current->next->t;
                            current->next->t = temp;
                            swapped = true;
                        }
                        prev = current;
                        current = current->next;
                    }
                } while(swapped);
            }
            else{
                do{
                    swapped = false;
                    node* current = head;
                    node* prev = nullptr;
                    while(current!=nullptr && current->next!=nullptr) {
                        if(current->t.name > current->next->t.name){
                            ticket temp = current->t;
                            current->t = current->next->t;
                            current->next->t = temp;
                            swapped = true;
                        }
                        prev = current;
                        current = current->next;
                    }
                } while(swapped);
            }
            cout<<"Tickets have been sorted!"<<endl;
            endClock();
            getTimeTaken();
        }
        bool closeTicket(int id){   //Current time assigned to closing time
            node* temp = head;
            while(temp!=nullptr){
                if(temp->t.id==id){
                    temp->t.status = 0;
                    temp->t.close = getCurrentTime();
                    cout<<"Ticket with ID#: "<<id<<" was closed."<<endl;
                    return true;
                }
                temp = temp->next;
            }
            cout<<"No ticket with ID#: "<<id<<" was found!"<<endl;
            return false;
        }
        ticket getTicket(int id){   //Assuming this will always work as list won't be empty
            node* temp = head;
            while(temp!=nullptr){
                if(temp->t.id==id){
                    return temp->t;
                }
                temp = temp->next;
            }
        }
        int topPriorityTicket(){    //Helper function to get the best match ticket (prioritized)
            node* temp = head;
            node* topPriorityNode = nullptr;
            while (temp != nullptr) {
                if ((topPriorityNode == nullptr || temp->t.priority < topPriorityNode->t.priority) && temp->t.status)
                    topPriorityNode = temp;
                temp = temp->next;
            }
            return topPriorityNode != nullptr ? topPriorityNode->t.id : -1;
        }
};

class agent{    //Defined assuming one agent can be assigned no more than 5 tickets
    public: 
        int id,n;
        string name;
        bool availability;
        int *AssignedTickets;

        agent(){
            id = n = 0;
            name = "";
            availability = true;
            AssignedTickets = nullptr;
        }
        agent(int id,string name,bool a){
            this->id = id;
            this->name = name;
            this->availability = a;
            n = 0;
        }
        void assign(int id){ //Assign to agent if they have less than 5 tickets, availability turns false if tickets reached 5
            if(n==0){
                AssignedTickets = new int[1];
                AssignedTickets[0] = id;
                cout<<endl<<"Ticket with ID#: "<<id<<" assigned to Agent: "<<name<<" (ID#: "<<this->id<<")"<<endl;
                n++;
                return;
            }
            if(n>=5){
                cout<<endl<<"No more open tickets available for Agent: Agent: "<<name<<" (ID#: "<<this->id<<")"<<endl;
                return;
            }
            int *temp = new int[n+1];
            for(int i=0;i<n;i++)
                temp[i] = AssignedTickets[i];

            delete[] AssignedTickets;
            temp[n] = id;
            n++;
            AssignedTickets = new int[n];
            for(int i=0;i<n;i++)
                AssignedTickets[i] = temp[i];
            delete[] temp;
            cout<<"Ticket with ID#: "<<id<<" assigned to Agent: "<<name<<" (ID#: "<<this->id<<")"<<endl;
            
            if(n==5)
                availability = false;
        }
        agent(const agent& a){ //copy constructor for agent objects as precaution
            this->id = a.id;
            this->n = a.n;
            this->name = a.name;
            this->availability = a.availability;

            if (a.AssignedTickets != nullptr && n > 0) {
                AssignedTickets = new int[n];
                for (int i = 0; i < n; i++)
                    AssignedTickets[i] = a.AssignedTickets[i]; 
            } 
            else 
                AssignedTickets = nullptr;
        }
        agent& operator=(const agent& a){  // = operator overloading for agent objects as precaution
            if (this != &a) {
                delete[] AssignedTickets;
                this->id = a.id;
                this->n = a.n;
                this->name = a.name;
                this->availability = a.availability;

                if (a.AssignedTickets != nullptr && n > 0) {
                    AssignedTickets = new int[n];
                    for (int i = 0; i < n; i++) 
                        AssignedTickets[i] = a.AssignedTickets[i];
                } 
                else 
                    AssignedTickets = nullptr;
            }
            return *this;
        }
        void getStatus(){ //Display agent availability details
            if(availability)
                cout<<"Agent#: "<<id<<" "<<name<<" is Available for support!"<<endl;
            else
                cout<<"Agent#: "<<id<<" "<<name<<" is Unavailable for support!"<<endl;
        }
        ~agent(){ delete[] AssignedTickets; }    
};

class stacks{
	public:
		node* top;
		stacks():top(nullptr){}
		void push(ticket e){
			node* n = new node;
			if(n==nullptr){
				cout<<"Logs overflow occured!"<<endl;
				return;
			}
			n->setData(e);
			n->setNext(top);
			top = n;
            cout<<"Ticket#: "<<top->t.id<<" under Name: "<<top->t.name<<" added to logs."<<endl;
		}
		ticket pop(){ //Pop the ticket on top of logs
			if(top==nullptr)
				throw std::underflow_error("Logs underflow occurred!");
			
			ticket last = top->t;
			node* temp = top;
			top=top->getNext();
            cout<<"Ticket#: "<<last.id<<" under Name: "<<last.name<<" cleared."<<endl;
			delete temp;
			return last;
		}
		void peek(){
			if(isEmpty())
				throw std::underflow_error("Logs underflow occurred!");
            top->getData();
		}
		void viewLogs(){
			if(top==nullptr){
				cout<<"Logs empty!"<<endl;
				return;
			}
            cout<<endl<<"(Displaying recent logs first)"<<endl;
			node* temp = top;
			while(temp!=nullptr){
                cout<<endl;
				temp->getData();
				temp=temp->getNext();
			}
            cout<<endl;
		}
		bool isEmpty(){
			if(top==nullptr)
				return true;
			return false;
		}
};
class queues{
    public:
        int size;
        node* front;
        node* rear;
        queues():front(nullptr),rear(nullptr),size(0){}
		void enqueue(ticket val){
            node* n = new node(val);
            if(isEmpty())
                front = rear = n;
            else{
                rear->next = n;
			    rear = n;
            }
            cout<<"Ticket#: "<<val.id<<" under Name: "<<val.name<<" enqueued!"<<endl;
            size++;
		}
		void dequeue(){
			if(isEmpty()){
                cout<<"Queue is empty!"<<endl;
                return;
            }
            node* temp = front;
            cout << "Dequeued Ticket#: "<<temp->t.id<<" under Name: "<<temp->t.name<< endl;
            front = front->next;
            if (front == nullptr)
                rear = nullptr;
            delete temp;
            size--;
		}
		bool isEmpty(){ return front == nullptr; }
        void atFront(){
            if(isEmpty())
                throw std::underflow_error("Queue is empty!");
            cout<<"Ticket at front:"<<endl;
            front->getData();
        }
        void displayQueue(){
            if(isEmpty()){
                cout<<"Queue is empty!"<<endl;
                return;
            }
            node* temp = front;
            cout <<endl<< "Ticket in queue: "<<endl;
            while (temp != nullptr) {
                cout<<endl;
                temp->getData();
                temp = temp->next;
            }
            cout << endl;
        }
};

class onestop{  //system class to facilitate all requirements in one place
    public:
        singleList tickets;
        agent *agents;
        int nAgents;
        stacks resolutionLog;
        queues pendingQueue;
    
        onestop(){
            agents = nullptr;
            nAgents = 0;
        }
        void addAgent(const agent a){
            if(nAgents==0){
                agents = new agent[1];
                agents[0] = a;
                cout<<endl<<"Agent#: "<<agents[0].id<<" "<<agents[0].name<<" added to the system!"<<endl;
                nAgents++;
                return;
            }
            agent *temp = new agent[nAgents+1];
            for(int i=0;i<nAgents;i++)
                temp[i] = agents[i];

            delete[] agents;
            temp[nAgents] = a;
            nAgents++;
            agents = new agent[nAgents];
            for(int i=0;i<nAgents;i++)
                agents[i] = temp[i];
            delete[] temp;
            cout<<endl<<"Agent#: "<<agents[nAgents-1].id<<" "<<agents[nAgents-1].name<<" added to the system!"<<endl;
        }

        void ListOpenTickets(){ //Display open tickets with prompty to sort according to user's choice
            singleList openTickets;
            //search tickets
            node* temp = tickets.head;
            while(temp!=nullptr){
                if(temp->t.status)
                    openTickets.insertAtEnd(temp->t);
                temp = temp->next;
            }
            if(openTickets.head==nullptr){
                cout<<endl<<"No open tickets were found!"<<endl;
                return;
            }
            cout<<endl<<"Open tickets have been found!"<<endl;
            cout<<"(Decide how do you want to sort ?)"<<endl;
            openTickets.sortTickets();
            cout<<"Displaying tickets after sorting:"<<endl;
            openTickets.display();
        }
        void AgentsInfo(){  //Agent Ticket Load
            if (agents==nullptr || nAgents==0){
                cout<<endl<<"No agents are present in the system!"<<endl;
                return;
            }
			for (int i = 0; i < nAgents - 1; i++) {
                for (int j = 0; j < nAgents - i - 1; j++) {
                    if (agents[j].n > agents[j + 1].n) {
                        agent temp = agents[j];
                        agents[j] = agents[j + 1];
                        agents[j + 1] = temp;
                    }
                }
            }
            cout<<endl<<"Displaying agents info:"<<endl;
            displayAgents();
        }
        bool displayAgents(){ //Helper for AgentsInfo(), displaying agents with their assigned tickets
            if(nAgents==0){
                cout<<"No agents are present in the system!"<<endl;
                return false;
            }

            for(int i=0;i<nAgents;i++){
                cout<<endl<<"Agent#:"<<i+1<<" Name: "<<agents[i].name<<"\tID: "<<agents[i].id<<endl;
                cout<<"Assigned Tickets:  ";
                for(int j=0;j<agents[i].n;j++){
                    cout<<"#"<<agents[i].AssignedTickets[j]<<", ";
                }
                cout<<"\b\b "<<endl;
            }
            return true;
        }
        void agentStatus(int id){ //getting agentStatus by providing an Agent ID
            for(int i=0;i<nAgents;i++){
                if(agents[i].id==id){
                    agents[i].getStatus();
                    return;
                }
            }
            cout<<"No results for Agent with ID#: "<<id<<" were found!"<<endl;
        }
        int freeAgent(){    //Helper function to get the best match agent (lesser # of tickets already assigned)
            int index = 0;
            for (int i = 1; i < nAgents; i++) { 
                if (agents[i].n < agents[index].n)
                    index = i;
            }
            return index;
        }
};

int main(){
    onestop system;
    int c;
    do{
        cout<<endl<<"(CUSTOMERS)"<<endl;
        cout<<"\t1. Add a ticket"<<endl;
        cout<<"\t2. Remove a ticket"<<endl;
        cout<<"\t3. Search a ticket"<<endl;
        cout<<"\t4. Sort tickets"<<endl;

        cout<<"(AGENTS)"<<endl;
        cout<<"\t5. Add an agent"<<endl;
        cout<<"\t6. Assign a ticket to agent"<<endl;
        cout<<"\t7. Check agent status"<<endl;

        cout<<"(SYSTEM)"<<endl;
        cout<<"\t8. List open-tickets in system"<<endl;
        cout<<"\t9. Display agents in system"<<endl;
        cout<<"\t10. Display pending tickets queue"<<endl;
        cout<<"\t11. Display ticket resolution history"<<endl;  //View logs
        cout<<"\t12. Close a ticket"<<endl; //Add to logs
        
        cout<<"0. EXIT"<<endl;
        cout<<"Input your choice: ";
        cin>>c;
        switch(c){
            case 1:{
                std::system("cls");
                ticket t;
                cout<<"Input Ticket ID#: ";
                cin>>t.id;
                cout<<"Input Ticket Priority: ";
                cin>>t.priority;
                cout<<"Input Name: ";
                cin>>t.name;
                cout<<"Input Ticket Description: ";
                cin>>t.desc;

                startClock();
                system.tickets.insertAtEnd(t);
                cout<<endl<<"Ticket added succesfully!"<<endl;
                system.pendingQueue.enqueue(t);
                endClock();
                getTimeTaken();
                break;
            }
            case 2:{
                std::system("cls");
                cout<<"Tickets:"<<endl;
                if(!system.tickets.display())
                    break;
                cout<<endl<<"Please enter a ticket id#: ";
                int x;
                cin>>x;
                startClock();
                system.tickets.deleteNode(x);
                endClock();
                getTimeTaken();
                break;
            }
            case 3:{
                std::system("cls");
                system.tickets.search();
                break;
            }
            case 4:{
                std::system("cls");
                system.tickets.sortTickets();
                break;
            }
            case 5:{
                std::system("cls");
                agent a;
                cout<<"Input Agent ID#: ";
                cin>>a.id;
                cout<<"Input Agent Name: ";
                cin>>a.name;

                startClock();
                system.addAgent(a);
                endClock();
                getTimeTaken();
                break;
            }
            case 6:{
                std::system("cls");
                cout<<"Agents:"<<endl;
                if(!system.displayAgents())
                    break;
                int bestAgent = system.freeAgent();
                int priorID = system.tickets.topPriorityTicket();
                if(priorID==-1){
                    cout<<"No ticket can be prioritized to be assigned right now!"<<endl;
                    break;
                }
                startClock();
                system.agents[bestAgent].assign(priorID);
                system.tickets.closeTicket(priorID); // if ticket is not closed after assigning, the same ticket will be assigned the next time
                // assign ticket is used, this is a major loophole in the assignment that hasn't been cleared the slightest ;(
                system.pendingQueue.dequeue();
                endClock();
                getTimeTaken();
                break;
            }
            case 7:{
                std::system("cls");
                cout<<"Agents:"<<endl;
                if(!system.displayAgents())
                    break;
                cout<<endl<<"Please enter an agent id# to check status: ";
                int x;
                cin>>x;
                system.agentStatus(x);
                break;
            }
            case 8:{
                std::system("cls");
                startClock();
                system.ListOpenTickets();
                endClock();
                getTimeTaken();
                break;
            }
            case 9:{
                std::system("cls");
                cout<<"Agents:"<<endl;
                startClock();
                system.displayAgents();
                endClock();
                getTimeTaken();
                break;
            }
            case 10:{
                std::system("cls");
                startClock();
                system.pendingQueue.displayQueue();
                endClock();
                getTimeTaken();
                break;
            }
            case 11:{
                std::system("cls");
                startClock();
                system.resolutionLog.viewLogs();
                endClock();
                getTimeTaken();
                break;
            }
            case 12:{
                std::system("cls");
                cout<<"Tickets:"<<endl;
                if(!system.tickets.display())
                    break;
                cout<<"Please enter a ticket id#: ";
                int x;
                cin>>x;
                if(!system.tickets.closeTicket(x))
                    break;
                system.resolutionLog.push(system.tickets.getTicket(x));
                break;
            }
            case 0:{
                break;
            }
            default:
                cout<<"Invalid input!"<<endl;
        }
    } while(c!=0);
    return 0;
}