#include <iostream>
#include <algorithm>
using namespace std;

class Stack {
private:
    int arr[10];
    int top;

public:
    Stack() : top(-1) {}

    void push(int value) {
        if (top == 9) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[++top] = value;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return -1;
        } else {
            return arr[top--];
        }
    }

    int mid() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top / 2];
    }

    void revBottom() {
        if (top == -1) {
            return;
        }
        int midIndex = top / 2;
        for (int i = 0; i < midIndex / 2; ++i) {
            swap(arr[i], arr[midIndex - 1 - i]);
        }
    }

    void print() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
        } else {
            for (int i = top; i >= 0; --i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    bool empty() {
        return top == -1;
    }

    bool full() {
        return top == 9;
    }

    int size() {
        return top + 1;
    }
};

int main() {
    Stack stack;

    stack.push(27);
    stack.push(93);
    stack.push(15);
    stack.push(62);
    stack.push(51);
    stack.push(34);
    stack.push(86);
    stack.push(78);
    stack.push(39);
    stack.push(64);

    cout << "\nMiddle element: " << stack.mid() << endl;

    stack.revBottom();
    stack.print();

    cout << "\nPopped element: " << stack.pop() << endl;
    stack.print();

    cout << "\nIs the stack empty? " << (stack.empty() ? "Yes" : "No") << endl;
    cout << "\nIs the stack full? " << (stack.full() ? "Yes" : "No") << endl;
    cout << "\nCurrent stack size: " << stack.size() << endl;

    return 0;
}
