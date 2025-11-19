#include<iostream>
using namespace std;

class Node
{
    public:
        int price;
        int height;
        Node* right;
        Node* left;

        Node(int key) : price(key), height(1), right(NULL), left(NULL) {}

};

int h(Node* n){ return n ? n->height : 0; }
int bf(Node* n){ return n ? h(n->left) - h(n->right) : 0; }

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    y->left = x->right;
    x->right = y;
    y->height = 1 + max(h(y->left), h(y->right));
    x->height = 1 + max(h(x->left), h(x->right));
    return x;
}

Node* leftRotate(Node* x)
{
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = 1 + max(h(x->left), h(x->right));
    y->height = 1 + max(h(y->left), h(y->right));
    return y;
}

Node* insert(Node* root, int price)
{
    if(!root) return new Node(price);

    if(price < root->price) 
        root->left = insert(root->left, price);
    else if(price > root->price) 
        root->right = insert(root->right, price);
    else 
        return root;

    root->height = 1 + max(h(root->left), h(root->right));

    int balance = bf(root);

    if(balance > 1 && price < root->left->price) 
        return rightRotate(root);    

    if(balance < -1 && price > root->right->price) 
        return leftRotate(root);     

    if(balance > 1 && price > root->left->price)
    {                              
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && price < root->right->price){                             
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(Node* root)
{
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->price << " ";
    inOrder(root->right);
}

void rangeQuery(Node* root, int X, int Y)
{
    if(!root) return;

    if(root->price > X)
        rangeQuery(root->left, X, Y);
    if(root->price >= X && root->price <= Y)
        cout << root->price << " ";
    if(root->price < Y) 
        rangeQuery(root->right, X, Y);
}

int main(){
    Node* root = NULL;

    int prices[] = {50, 20, 70, 10, 30, 60, 90, 25, 35};
    int size = sizeof(prices) / sizeof(prices[0]);
    for(int i=0; i< size; i++)
        root = insert(root, prices[i]);

    inOrder(root);
    cout << endl;
    int X = 25, Y = 70;
    cout << "Prices between " << X << " and " << Y << ": ";
    rangeQuery(root, X, Y);
}