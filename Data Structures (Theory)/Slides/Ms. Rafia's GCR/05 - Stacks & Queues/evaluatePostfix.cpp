#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Stack {
private:
    int top;
    int max_size;
    int* arr;

public:
    Stack(int size) {
        top = -1;
        max_size = size;
        arr = new int[max_size];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top < max_size - 1) {
            arr[++top] = value;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    int pop() {
        if (top != -1) {
            return arr[top--];
        } else {
            cout << "Stack underflow!" << endl;
            return 0;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int evaluatePostfix(string postfix) {
    Stack operandStack(postfix.length());

    for (int i = 0; i < postfix.length(); i++) {
        char currentChar = postfix[i];

        if (isdigit(currentChar)) {
            operandStack.push(currentChar - '0');
        } else {
            int operand2 = operandStack.pop();
            int operand1 = operandStack.pop();

            switch (currentChar) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operandStack.push(operand1 / operand2);
                    break;
                case '^':
                    operandStack.push(pow(operand1, operand2));
                    break;
                default:
                    cout << "Invalid operator: " << currentChar << endl;
                    return 0;
            }
        }
    }

    return operandStack.pop();
}

int main() {
    string postfixExpression;

    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;

    int result = evaluatePostfix(postfixExpression);

    cout << "The result of the postfix expression is: " << result << endl;

    return 0;
}
