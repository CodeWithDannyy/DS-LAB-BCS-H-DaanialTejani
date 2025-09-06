#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* previous;

        Node(int data)
        {
            this->data = data;
            next = NULL;
            previous = NULL;
        }
};

Node* Doubly(Node* head)
{
    if(head == NULL) return NULL;

    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL)
    {
        temp->previous = prev;
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *circular(Node* head)
{
    if(head == NULL) return NULL;

    Node * temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next= head;
    return head;
}

void traverseFromTheStart(Node* temp)
{
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void traverseFromTheEnd(Node* temp)
{
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->previous;
    }
    cout << endl;
}

void printCLL(Node* head)
{
    if(head == NULL) return;

    Node* temp = head;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }while(temp != head);
    cout << "back to head\n";
}

int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    Node* tail = head;
    while(tail->next != NULL)
        tail = tail->next;

    head = Doubly(head);
    cout << "Doubly forward: ";
    traverseFromTheStart(head);
    cout << "Doubly backward: ";
    traverseFromTheEnd(tail);

    head = circular(head);
    cout << "Circular: ";
    printCLL(head);
}

