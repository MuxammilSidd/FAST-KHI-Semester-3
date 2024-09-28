//23K2001 - Muzammil
#include<iostream>
using namespace std;
class stacks{
	private:
		int top,size;
	public:
		char *arr;
		stacks():top(-1),size(0),arr(nullptr){}
		stacks(int s):top(-1),size(s){
			arr = new char[size];
			for(int i=0;i<size;i++)
				arr[i]='!';
		}
		
		void push(char e){
			if(top>=(size-1)){
				cout<<"Stack overflow occured!"<<endl;
				return;
			}
			arr[++top] = e;
		}
		char pop(){
			if(top<0){
				cout<<"Stacks underflow occured!"<<endl;
				return '!';
			}
			char last = arr[top--];
			return last;
		}
		
		bool checkPalindrome(){
			stacks reversed(this->size);
			for(int i=0;i<size;i++)
				reversed.push(this->arr[i]);
			
			for(int i=0;i<size;i++){
				if(this->arr[i]!=reversed.pop())
					return false;
			}
			return true;
		}
		~stacks(){ delete[] arr; }
};
int main(){
	int s;
	cout<<"Enter size of stack: ";
	cin>>s;
	stacks flex(s);
	char e;
	cout<<"Enter "<<s<<" elements:"<<endl;
	for(int i=0;i<s;i++){
		cin>>e;
		flex.push(e);
	}
	cout<<endl<<"Checking for Palindrome:"<<endl;
	if(flex.checkPalindrome())
		cout<<"Yes!"<<endl;
	else
		cout<<"No!"<<endl;
	return 0;
}