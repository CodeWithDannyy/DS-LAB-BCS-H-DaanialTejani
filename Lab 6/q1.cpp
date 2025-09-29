#include<iostream>
using namespace std;

class Stack
{
    int top;

    public:
        int arr[100];

        Stack() { top = -1; }

        void push(int x)
        {
            if(top >= 99)
            {
                cout << "Stack Overflow!!" << endl;
                return;
            }
            arr[++top] = x;
        }

        int pop()
        {
            if(top < 0)
            {
                cout << "Stack Underflow!!" << endl;
                return 0;
            }
            int a = arr[top--];
            return a;
        }

        void peek()
        {
            if(top < 0)
            {
                cout << "Stack is empty!!" << endl;
                return;
            }
            cout << "Element at the top : " << arr[top] << endl;
        }

        void displayStackContents()
        {
            cout << "\nStack Contents : " << endl;
            for(int i = 0; i <= top; i++)
            {
                cout << arr[i] << endl;
            }
        }
};

int main()
{
    Stack stack;
    stack.push(67);
    stack.push(41);
    stack.push(42);
    stack.push(69);
    stack.push(420);

    stack.displayStackContents();

    int x = stack.pop();
    cout << "Popped Element : " << x << endl;

    stack.displayStackContents();

    stack.peek();
}
