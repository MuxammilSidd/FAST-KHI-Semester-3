//23K2001 - Muzammil
#include<iostream>
using namespace std;
class order{
    private:
    int qty;
    string item;
    public:
    order(){}
    order(string i, int q):qty(q),item(i){}
    void setQty(int q){ qty = q; }
    void setItem(string i){ item = i; }
    string getItem(){ return item; }
    int getQty(){ return qty; }
    void setOrder(string i, int q){
        setQty(q);
        setItem(i);
    }
    void getOrder(){ cout<<"Item: "<<getItem()<<" - Quantity: "<<getQty()<<endl; }
};
class queue{
    private:
		int front,rear,size;
	public:
		order *arr;
		queue():front(-1),rear(-1),size(0),arr(nullptr){}
		queue(int s):front(-1),rear(-1),size(s){
			arr = new order[size];
			for(int i=0;i<size;i++)
				arr[i].setOrder("",0);
		}
		void enqueue(string i,int q){
			if(isFull()){
				cout<<"Queue is full!"<<endl;
				return;
			}
            else if(isEmpty())
                front = rear = 0;
            else
                rear++;
			arr[rear].setOrder(i,q);
		}
		void dequeue(){
			if(isEmpty()){
                cout<<"Queue is empty!"<<endl;
                return;
            }
            else if(front == rear){
                arr[front].getOrder();
                front = rear = -1;
            }
            else{
                arr[front].getOrder();
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
            cout<<endl<<"Orders in the queue are: "<<endl;
            for(int i=front;i<=rear;i++){
                cout<<i<<". ";
                arr[i].getOrder();
            }
        }
		~queue(){ delete[] arr; }
};
int main(){
    int s;
	cout<<"Enter number of orders: ";
	cin>>s;
	queue orders(s);
	string o;
    int q;
	cout<<"Place "<<s<<" orders: [Item] [Quantity]"<<endl;
	for(int i=0;i<s;i++){
		cin>>o>>q;
		orders.enqueue(o,q);
	}
    orders.display();
    cout<<endl<<"Processing orders.."<<endl;
    while(!orders.isEmpty())
        orders.dequeue();
    
    if(orders.isEmpty())
        cout<<endl<<"All orders have been processed!"<<endl;
    else
        cout<<endl<<"All orders have NOT been processed yet!"<<endl;
    return 0;
}