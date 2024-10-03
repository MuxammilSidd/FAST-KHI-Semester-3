//23K2001 - Muzammil
#include<iostream>
using namespace std;
class queue{
    private:
		int front,rear,size;
	public:
		int *ids;
		queue():front(-1),rear(-1),size(0),ids(nullptr){}
		queue(int s):front(-1),rear(-1),size(s){
			ids = new int[size];
			for(int i=0;i<size;i++)
				ids[i]=-1;
		}
		void enqueue(int q){
			if(isFull()){
				cout<<"Queue is full!"<<endl;
				return;
			}
            else if(isEmpty())
                front = rear = 0;
            else
                rear++;
			ids[rear]=q;
		}
		void dequeue(){
			if(isEmpty()){
                cout<<"Queue is empty!"<<endl;
                return;
            }
            else if(front == rear){
                cout<<"CustomerID#"<<ids[front]<<" processed!"<<endl;
                front = rear = -1;
            }
            else{
                cout<<"CustomerID#"<<ids[front]<<" processed!"<<endl;
                front++;
            }
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
            cout<<endl<<"Customer IDs in the queue are: "<<endl;
            for(int i=front;i<=rear;i++)
                cout<<i<<". "<<ids[i]<<endl;
        }
		~queue(){ delete[] ids; }
};
int main(){
    int s;
	cout<<"Enter number of customers: ";
	cin>>s;
	queue flex(s);
    int q;
	cout<<"Enter "<<s<<" IDs:"<<endl;
	for(int i=0;i<s;i++){
		cin>>q;
		flex.enqueue(q);
	}
    flex.display();
    cout<<endl<<"Making checkouts.."<<endl;
    while(!flex.isEmpty())
        flex.dequeue();
    
    if(flex.isEmpty())
        cout<<endl<<"All checkouts have been processed!"<<endl;
    else
        cout<<endl<<"All checkouts have NOT been processed yet!"<<endl;
    return 0;
}