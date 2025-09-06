#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* child;

        Node(int d)
        {
            data = d;
            next = NULL;
            child = NULL;
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

Node* flatten(Node* head)
{
    if(head == NULL) return NULL;

    Node* curr = head;
    while(curr != NULL)
    {
        if(curr->child != NULL)
        {
            Node* childHead = flatten(curr->child);
            Node* nextNode = curr->next;
            curr->next = childHead;

            Node* temp = childHead;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nextNode;
            curr->child = NULL;
        }
        curr = curr->next;
    }
    return head;
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    head->next->child = new Node(4);
    head->next->child->next = new Node(5);

    cout << "Before Flatten: ";
    traverse(head);  

    head = flatten(head);

    cout << "After Flatten: ";
    traverse(head);   

    return 0;
}