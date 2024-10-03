#include<iostream>
#include<string>
#include<cmath>
using namespace std;

template<class T>
class node{
private:
    T data;
    node<T>* next;
public:
    node() : next(nullptr){}
    node(T s) : next(nullptr), data(s){}
    T getData(){ return data; }
    void setData(T s){ data = s; }
    node<T>* getNext(){ return next; }
    void setNext(node<T>* n){ next = n; }
};
template<class T>
class stack{
private:
    node<T>* top;
public:
    stack() : top(nullptr){}

    void push(T e){
        node<T>* n = new node<T>;
        if(n == nullptr){
            cout<<"Stack overflow occurred!"<<endl;
            return;
        }
        n->setData(e);
        n->setNext(top);
        top = n;
    }

    T pop(){
        if(top == nullptr){
            cout<<"Stack underflow occurred!"<<endl;
            return T();
        }
        T last = top->getData();
        node<T>* temp = top;
        top = top->getNext();
        delete temp;
        return last;
    }

    T peek(){
        if(isEmpty())
            return T();
        return top->getData();
    }

    bool isEmpty(){ return top == nullptr; }
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

float applyOperation(char op,float val1,float val2){
    switch(op){
        case '+': return val1 + val2;
        case '-': return val1 - val2;
        case '*': return val1 * val2;
        case '/': return val1 / val2;
        case '^': return pow(val1, val2);
        default: return 0;
    }
}

bool checkDigit(char c){ return (c >= '0' && c <= '9'); }

float parseNumber(const string& s, int& i){
    string numStr = "";
    while(i < s.length() && (checkDigit(s[i]) || s[i] == '.')){
        numStr += s[i];
        i++;
    }
    i--;
    return stof(numStr);
}

void evaluateTop(stack<char>& operators, stack<float>& values){
    if(operators.isEmpty()) return;
    
    char op = operators.pop();
    float val2 = values.pop();
    float val1 = values.pop();
    
    values.push(applyOperation(op,val1,val2));
}

float calcExpression(const string& infix){
    stack<char> operators;
    stack<float> values;

    for(int i = 0; i < infix.length(); i++){
        char c = infix[i];

        if(checkDigit(c) || c == '.') 
            values.push(parseNumber(infix,i));
        else if(c == '('){
            if(i > 0 && (checkDigit(infix[i-1]) || infix[i-1] == ')'))
                operators.push('*');
            
            operators.push(c);
        } 
		else if(c == ')'){
            while (!operators.isEmpty() && operators.peek() != '(')
                evaluateTop(operators,values);
            
            operators.pop();
        } 
		else if(c == '*' || c == '/' || c == '+' || c == '-' || c == '^'){
            while (!operators.isEmpty() && precedence(c) <= precedence(operators.peek()))
                evaluateTop(operators,values);
            
            operators.push(c);
        }
    }
    while (!operators.isEmpty()) 
        evaluateTop(operators, values);

    return values.peek();
}

int main() {
    cout<<"\t\tWelcome to Muzammil's Calculator!"<<endl;
    cout<<endl<<"Enter your expression: "<<endl;
    string e;
    cin>>e;

    float result = calcExpression(e);
    cout<<"Result: "<<result<<endl;
    return 0;
}