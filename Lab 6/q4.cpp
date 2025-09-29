#include<iostream>
using namespace std;

#define MAX 5
class CircularQueue
{
    int front, rear;
    int arr[MAX];

    public:
        CircularQueue()
        {
            front = -1;
            rear = -1;
        }

        bool isEmpty()
        {
            return front == -1;
        }

        bool isFull()
        {
            return (!isEmpty()) && ((rear + 1) % MAX == front);
        }

        void enqueue(int x)
        {
            if(isFull())
            {
                cout << "Queue is Full!" << endl;
                return;
            }

            if(isEmpty())
            {
                front = 0, rear = 0;
                arr[rear] = x;
                cout << x << " Enqueued." << endl;
                return;
            }

            rear = (rear + 1) % MAX;
            arr[rear] = x;
            cout << x << " Enqueued." << endl;
        }

        int dequeue()
        {
            if(isEmpty())
            {
                cout << "Queue is Empty" << endl;
                return 0;
            }

            int val = arr[front];
            cout << val << " dequeued" << endl;

            if(front == rear)
            {
                front = -1, rear = -1;
            }
            else
            {
                front = (front + 1) % MAX;
            }
            return val;
        }

        void displayContents()
        {
            if(isEmpty())
            {
                cout << "Queue is empty" << endl;
                return;
            }

            cout << "Queue Contents: " << endl;
            int i = front;
            while (true)
            {
                cout << arr[i] << " ";
                if(i == rear)
                    break;
                i = (i+1) % MAX;
            }
            cout << endl;
        }
};

int main()
{
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    q.displayContents();

    q.dequeue();
    q.dequeue();

    q.displayContents();

    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);

    q.displayContents();
}