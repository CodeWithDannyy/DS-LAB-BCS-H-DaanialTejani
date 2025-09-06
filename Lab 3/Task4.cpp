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
    if(head == NULL)
    { 
        cout << endl; 
        return; 
    }
    Node* temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != head);
    cout << endl;
}

void insert(Node*& head, int data)
{
    Node* newNode = new Node(data);
    if(head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

int josephus(Node* &head, int k)
{
    if(head == NULL) return -1;
    if(k <= 0) return -1;

    Node* curr = head;
    Node* prev = head;

    while(prev->next != head) 
        prev = prev->next;

    while(curr->next != curr)
    {
        for(int i = 1; i < k; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if(curr == head) 
            head = curr->next;
        Node* del = curr;
        curr = curr->next;
        delete del;
    }

    int ans = curr->data;
    delete curr;
    head = NULL;
    return ans;
}

int main()
{
    Node* head = NULL;

    int N = 8, K = 3;
    for(int i = 1; i <= N; i++) 
        insert(head, i);

    cout << "Circle: ";
    traverse(head);

    int survivor = josephus(head, K);
    cout << "Survivor Position : " << survivor << endl;

    return 0;
}
