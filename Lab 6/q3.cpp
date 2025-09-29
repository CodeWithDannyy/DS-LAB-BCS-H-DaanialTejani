#include<iostream>
using namespace std;
#define MAX 100
class Queue
{
    int front,rear;
    int arr[MAX];

    public:
        Queue()
        {
            front = 0;
            rear = -1;
        }

        bool isEmpty()
        {
            return front > rear;
        }

        bool isFull()
        {
            return rear == MAX - 1;
        }

        void enqueue(int x)
        {
            if(isFull())
            {
                cout << "Queue is Full" << endl;
                return;
            }
            arr[++rear] = x;
            cout << x << " Enqueued." << endl;
        }

        int dequeue()
        {
            if(isEmpty())
            {
                cout << "Queue is empty" << endl;
                return 0;
            }
            cout << "Dequeued : " << arr[front] << endl;
            return arr[front++];
        }

        void displayContents()
        {
            if(isEmpty())
            {
                cout << "Queue is empty" << endl;
                return;
            }

            cout << "Queue Contents: " << endl;
            for(int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    queue.displayContents();

    int x = queue.dequeue();
    cout << "Dequeued Element : " << x << endl;

    queue.displayContents();
}