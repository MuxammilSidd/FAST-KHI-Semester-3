#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    int top;
    int max_size;
    char* arr;

public:
    Stack(int size) {
        top = -1;
        max_size = size;
        arr = new char[max_size];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(char c) {
        if (top < max_size - 1) {
            arr[++top] = c;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    char pop() {
        if (top != -1) {
            return arr[top--];
        } else {
            cout << "Stack underflow!" << endl;
            return '\0';
        }
    }

    char peek() {
        return (top != -1) ? arr[top] : '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperand(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

string convertToPostfix(string infix) {
    Stack operatorStack(infix.length());
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char currentChar = infix[i];

        if (isOperand(currentChar)) {
            postfix += currentChar;
        } else if (currentChar == '(') {
            operatorStack.push(currentChar);
        } else if (currentChar == ')') {
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {
                postfix += operatorStack.pop();
            }
            operatorStack.pop();
        } else {
            while (!operatorStack.isEmpty() && getPrecedence(currentChar) <= getPrecedence(operatorStack.peek())) {
                postfix += operatorStack.pop();
            }
            operatorStack.push(currentChar);
        }
    }

    while (!operatorStack.isEmpty()) {
        postfix += operatorStack.pop();
    }

    return postfix;
}

string convertToPrefix(string infix) {
    string reversedInfix(infix.rbegin(), infix.rend());

    for (int i = 0; i < reversedInfix.length(); i++) {
        if (reversedInfix[i] == '(')
            reversedInfix[i] = ')';
        else if (reversedInfix[i] == ')')
            reversedInfix[i] = '(';
    }

    string postfix = convertToPostfix(reversedInfix);
    string prefix = string(postfix.rbegin(), postfix.rend());

    return prefix;
}

int main() {
    string infixExpression;

    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    string prefixExpression = convertToPrefix(infixExpression);

    cout << "The corresponding prefix expression is: " << prefixExpression << endl;

    return 0;
}
