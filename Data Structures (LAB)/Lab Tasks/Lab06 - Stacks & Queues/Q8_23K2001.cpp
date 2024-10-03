// 23K2001 - Muzammil
#include<iostream>
using namespace std;

class queue {
    private:
        int front, rear, size;
    public:
        string *arr;
        queue(): front(-1), rear(-1), size(0), arr(nullptr){}
        queue(int s): front(-1), rear(-1), size(s){
            arr = new string[size];
            for(int i = 0; i < size; i++)
                arr[i] = "!";
        }
        void enqueue(string message){
            if(isFull()){
                cout << "Message queue is full!" << endl;
                return;
            } 
            else if(isEmpty()) 
                front = rear = 0;
            else 
                rear++;
            arr[rear] = message;
            cout<<"Message '"<<message<<"' has been added to queue."<<endl;
        }
        void dequeue(){
            if(isEmpty()){
                cout<<"Message queue is empty!"<<endl;
                return;
            } 
            else if(front == rear) 
                front = rear = -1;
            else 
                front++;
        }
        string atFront(){
            if(isEmpty()){
                cout<<"Message queue is empty!"<<endl;
                return "!";
            }
            return arr[front];
        }
        bool isEmpty(){ return front == -1 || front > rear; }
        bool isFull(){ return rear == size - 1; }
        void display(){
            if(isEmpty()){
                cout<<"Message queue is empty!"<<endl;
                return;
            }
            cout<<endl<<"Messages in queue: "<<endl;
            for(int i = front;i<=rear;i++)
                cout<<i<<". "<<arr[i]<<endl;   
        }
        ~queue(){ delete[] arr; }
};

const int maxMessages = 15;

int main(){
    queue messages(maxMessages);
    int choice;
    string s;
    do{
        cout<<endl<<"\t\tFAST NU WHATSAPP LITE FYP"<<endl;
        cout<<"1. Add message to queue"<<endl;
        cout<<"2. Process message"<<endl;
        cout<<"3. Display messages in queue"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1: {
                cout<<"Enter message: ";
                cin.ignore();
                getline(cin,s);
                messages.enqueue(s);
                break;
            }
            case 2: {
                if(!messages.isEmpty()){
                    cout<<"Processing message: "<<messages.atFront() << endl;
                    messages.dequeue();
                } 
                else 
                    cout<<"No messages in the queue."<<endl;
                break;
            }
            case 3: {
                if(messages.isEmpty())
                    cout<<"The message queue is empty."<<endl;
                else 
                    messages.display();
                break;
            }
            case 4:
                break;
            default:
                cout<<"Invalid choice! Please try again."<<endl;
        }
    } while(choice != 4);

    return 0;
}
