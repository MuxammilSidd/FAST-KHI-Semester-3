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
		int getpeek(){ return top; }
		int getSize() { return size; }
		
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
		char peek(){
			if(top < 0){
				cout << "Stack is Empty";
				return 0;
			} else{
				int x = arr[top];
				return x;
			}
		}
		bool isEmpty(){ return (top<0); }
};
int precedence(char c){
    if(c == '^') 
        return 3;
    else if(c == '*' || c == '/') 
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string infixToPostfix(string infix){
    string postfix = "";
    stacks s(infix.length());

    for(int i = 0; i < infix.length(); i++){
        char c = infix[i];

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            postfix += c;
        else if(c == '(')
            s.push(c);
        else if(c == ')'){
            while(!s.isEmpty() && s.peek() != '('){
                char op = s.pop();
                postfix += op;
            }
            if(s.peek() == '(') 
                s.pop();
        } else{
            while(!s.isEmpty() && precedence(c) <= precedence(s.peek())){
                char op = s.pop();
                postfix += op;
            }
            s.push(c);
        }
    }
    while(!s.isEmpty()){
        char op = s.pop();
        postfix += op;
    }

    return postfix;
}
int main(){
	cout<<"\t\tWelcome to Infix to Postfix expression converter!"<<endl;
	cout<<endl<<"Enter you infix expression: "<<endl;
	string e;
	cin>>e;
	cout<<endl<<"After conversion :-"<<endl;
	cout<<"Postfix: "<<infixToPostfix(e)<<endl;
	// “((A + B) – C * (D / E)) + F”
	return 0;
}