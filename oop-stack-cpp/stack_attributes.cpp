#include <iostream>
using namespace std;

// Base- class (Encapsulation + Inheritance)
class BaseStack {
protected:
    int size;   // Maximum size
    int top;    // Current top index
    int* arr;   // Dynamic array

public:
    BaseStack(int s) {      // Constructor
        size = s;
        arr = new int[size];
        top = -1;
    }

    ~BaseStack() {          // Destructor
        delete[] arr;
    }
};

// Derived class (Stack)
class Stack : public BaseStack {
public:
    Stack(int s) : BaseStack(s) {}   // Constructor

    // Push
    void push(int value) {
        if (isFull())
            cout << "Stack is full. Cannot push " << value << endl;
        else {
            arr[++top] = value;
            cout << value << " pushed." << endl;
        }
    }

    // Pop
    void pop() {
        if (isEmpty())
            cout << "Stack is empty. Cannot pop." << endl;
        else
            cout << arr[top--] << " popped." << endl;
    }

    // Show top
    void topElement() {
        if (isEmpty())
            cout << "Stack is empty. No top element." << endl;
        else
            cout << "Top element: " << arr[top] << endl;
    }

    // Check empty
    bool isEmpty() {
        return (top == -1);
    }

    // Check full
    bool isFull() {
        return (top == size - 1);
    }
};

// Main function
int main() {
    int n, choice, value;
    cout << "Enter stack size: ";
    cin >> n;

    Stack s(n);   // Object of Stack

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Display Top\n4. Check if Empty\n5. Check if Full\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.topElement();
                break;
            case 4:
                cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;
            case 5:
                cout << (s.isFull() ? "Stack is full" : "Stack is not full") << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}

