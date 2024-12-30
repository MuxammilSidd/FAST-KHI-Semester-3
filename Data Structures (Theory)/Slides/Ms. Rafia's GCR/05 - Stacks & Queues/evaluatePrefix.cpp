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

int evaluatePrefix(string prefix) {
    Stack operandStack(prefix.length());
    
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char currentChar = prefix[i];

        if (isdigit(currentChar)) {
            operandStack.push(currentChar - '0');
        } else {
            int operand1 = operandStack.pop();
            int operand2 = operandStack.pop();

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
    string prefixExpression;

    cout << "Enter a prefix expression: ";
    cin >> prefixExpression;

    int result = evaluatePrefix(prefixExpression);

    cout << "The result of the prefix expression is: " << result << endl;

    return 0;
}
