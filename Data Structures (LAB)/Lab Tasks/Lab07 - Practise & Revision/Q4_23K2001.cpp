//23K2001 - Muzammil
#include <iostream>
using namespace std;

class stacks{
    private:
		int top,size;
	public:
		int *arr;
		stacks():top(-1),size(0),arr(nullptr){}
		stacks(int s):top(-1),size(s){
			arr = new int[size];
			for(int i=0;i<size;i++)
				arr[i]=0;
		}
        int getSize(){ return size; }
		void push(int e){
			if(top>=(size-1)){
				cout<<"Stack overflow occured!"<<endl;
				return;
			}
			arr[++top] = e;
		}
		int pop(){
			if(top<0){
				cout<<"Stacks underflow occured!"<<endl;
				return -1;
			}
			int last = arr[top--];
			return last;
		}
		int peek(){
			if(top < 0){
				cout<<"Stack is Empty";
				return 0;
			} else{
				int x = arr[top];
				return x;
			}
		}
        void display(){
            if(isEmpty()){
                cout<<"Stack is empty!"<<endl;
                return;
            }
            for(int i=0;i<=top;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
		bool isEmpty(){ return (top<0); }
		~stacks(){ delete[] arr; }
};

class queue{
    int *arr;
    int size;
    int rear;
    int front;
public:
    queue():front(-1),rear(-1),size(0),arr(nullptr){}
		queue(int s):front(-1),rear(-1),size(s){
			arr = new int[size];
			for(int i=0;i<size;i++)
				arr[i]=-1;
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
			arr[rear]=q;
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
        int peek(){ return arr[front]; }
        
		~queue(){ delete[] arr; }
};
void reverseByQueue(stacks &s){
    queue q(s.getSize());
    while (!s.isEmpty()){
        q.enqueue(s.peek());
        s.pop();
    }

    while (!q.isEmpty()){
        s.push(q.peek());
        q.dequeue();
    }
}
int main()
{
    int s;
	cout<<"Enter size of stack: ";
	cin>>s;
	stacks flex(s);
	int e;
	cout<<"Enter "<<s<<" elements:"<<endl;
	for(int i=0;i<s;i++){
		cin>>e;
		flex.push(e);
	}
    cout<<"Elements in stack: "<<endl;
    flex.display();
    reverseByQueue(flex);
    cout<<endl<<"After reversing using queue:"<<endl;
    flex.display();
}