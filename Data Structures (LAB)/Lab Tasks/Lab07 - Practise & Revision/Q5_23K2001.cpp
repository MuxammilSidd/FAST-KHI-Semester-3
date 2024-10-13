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
		void deleteMiddle(int count=0){
			if (count == (size)/2){
				cout<<endl<<"Middle element: "<<pop()<<endl;
				return;
			}
			int val = pop();
			deleteMiddle(count + 1);
			push(val);
		}

		~stacks(){ delete[] arr; }
};

int main(){
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
    flex.deleteMiddle();
    cout<<endl<<"After deleting middle element:"<<endl;
    flex.display();
}