//23K2001 - Muzammil
#include<iostream>
using namespace std;
class queue{
    private:
		int front,rear,size;
	public:
		string *arr;
		queue():front(-1),rear(-1),size(0),arr(nullptr){}
		queue(int s):front(-1),rear(-1),size(s){
			arr = new string[size];
			for(int i=0;i<size;i++)
				arr[i]="!";
		}
		void enqueue(string s){
			if(isFull()){
				cout<<"Queue is full!"<<endl;
				return;
			}
            else if(isEmpty())
                front = rear = 0;
            else
                rear++;
			arr[rear]=s;
            cout<<s<<" has been added to the queue."<<endl;
		}
		void dequeue(){
			if(isEmpty()){
                cout<<"Queue is empty!"<<endl;
                return;
            }
            else if(front == rear)
                front = rear = -1;
            else
                front++;
		}
        string atFront(){
            if(isEmpty()){
                cout<<"Queue is empty!"<<endl;
                return "!";
            }
            return arr[front];
        }
		bool isEmpty(){
			if(front==-1 || front>rear)
				return true;
			return false;
		}
        bool isFull(){
            if(rear==size-1)
                return true;
            return false;
        }
        void display(){
            if(isEmpty()){
                cout<<"Queue is empty!"<<endl;
                return;
            }
            cout<<endl<<"Patrons in waiting queue are: "<<endl;
            for(int i=front;i<=rear;i++){
                cout<<i<<". "<<arr[i]<<endl;
            }
        }
		~queue(){ delete[] arr; }
};

const int maxPatrons = 15;

int main(){
    queue patrons(maxPatrons);
    int choice;
    string name;
    do{
        cout<<endl<<"\t\tFAST NU KHI LIBRARY"<<endl;
        cout<<"1. Add patron to queue"<<endl;
        cout<<"2. Remove patron from queue"<<endl;
        cout<<"3. Display patrons in queue"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:{
                cout<<"Enter patron's name: ";
                cin>>name;
                patrons.enqueue(name);
                
                break; }
            case 2:{
                if(!patrons.isEmpty()){
                    cout<<patrons.atFront()<<"'s transaction is completed."<<endl;
                    patrons.dequeue();
                } 
                else 
                    cout<<"No patrons in the queue."<<endl;
                break; }
            case 3:{
                if(patrons.isEmpty())
                    cout<<"The queue is empty."<<endl;
                else
                    patrons.display();
                break; }
            case 4:
                break;
            default:
                cout<<"Invalid choice! Please try again."<<endl;
        }
    } while(choice != 4);

    return 0;
}