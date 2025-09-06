#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

Node* mergeList(Node* head1, Node* head2)
{
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    Node* head = NULL;
    Node* tail = NULL;

    if(head1->data <= head2->data)
    {
        head = head1;
        head1 = head1->next;
    }
    else
    {
        head = head2;
        head2 = head2->next;
    }
    tail = head;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            tail->next = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if(head1 != NULL) tail->next = head1;
    if(head2 != NULL) tail->next = head2;

    return head;
}

void printList(Node* head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node* A = new Node(1);
    A->next = new Node(3);
    A->next->next = new Node(5);

    Node* B = new Node(2);
    B->next = new Node(4);
    B->next->next = new Node(6);

    cout << "List A: ";
    printList(A);

    cout << "List B: ";
    printList(B);

    Node* merged = mergeList(A, B);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}