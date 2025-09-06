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

Node* reverseList(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL)
    {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

bool isPalindrome(Node* head)
{
    if(head == NULL || head->next == NULL) return true;

    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* second = reverseList(slow->next);

    Node* p1 = head;
    Node* p2 = second;
    bool check = true;

    while(p2 != NULL)
    {
        if(p1->data != p2->data)
        {
            check = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    slow->next = reverseList(second);

    return check;
}

int main()
{
    int n;
    cout << "Enter the number of elements you want in the list: ";
    cin >> n;

    
    Node* head = NULL;
    for(int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter Element " << i+1 << ": ";
        cin >> x;
        insert(head, x);
    }

    if(isPalindrome(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}
