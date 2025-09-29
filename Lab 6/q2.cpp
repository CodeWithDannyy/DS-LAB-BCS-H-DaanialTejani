#include<iostream>
using namespace std;

class Node
{
    public:
        string url;
        Node* next;

        Node(string str)
        {
            url = str;
            next - NULL;
        }
};

class Stack
{
    Node* top;
    public:
        Stack() { top = NULL;}

        void push(string url)
        {
            Node* temp = new Node(url);
            temp->next = top;
            top = temp;
            cout << "Visited Site : " << url << endl;
        }

        string pop()
        {
            if(top == NULL)
            {
                cout << "Empty History" << endl;
                return "";
            }

            Node* temp = top;
            string site = temp->url;
            cout << "Removing Site : " << temp->url << endl;
            top = temp->next;
            delete temp;
            return site;
        }

        void peek()
        {
            if(top == NULL)
            {
                cout << "No page open" << endl;
                return;
            }
            cout << "Site at the top : " << top->url << endl;
        }

        void displayContents()
        {
            Node* temp = top;
            while(temp != NULL)
            {
                cout << temp->url << endl;
                temp = temp->next;
            }
        }
};


int main()
{
    Stack stack;
    stack.push("google.com");
    stack.push("rule34.com");
    stack.push("fssquad.com");
    

    stack.displayContents();

    string site = stack.pop();
    cout << "Site Removed : " << site << endl;

    stack.displayContents();

    stack.peek();
}