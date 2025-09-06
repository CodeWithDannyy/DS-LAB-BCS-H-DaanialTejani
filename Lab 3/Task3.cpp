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

void traverse(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseInGroups(Node* head, int k)
{
    if(head == NULL) return NULL;

    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    int count = 0;

    while(curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL)
    {
        head->next = reverseInGroups(next, k);
    }

    return prev;
}

void insert(Node*& head, int data)
{
    Node* newNode = new Node(data);
    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main()
{
    int n;
    cout << "Enter the number of elements you want in the list: ";
    cin >> n;
    int k;
    cout << "Enter the number of node to be reversed: ";
    cin >> k;

    Node* head = NULL;
    for(int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter Element " << i+1 << ": ";
        cin >> x;
        insert(head, x);
    }

    head = reverseInGroups(head, k);

    cout << "Reversed in Groups of " << k << ": ";
    traverse(head);
}