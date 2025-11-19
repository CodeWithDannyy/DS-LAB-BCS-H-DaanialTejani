#include<iostream>
using namespace std;

class Node
{
    public:
        int rollNo;
        int height;
        Node* right;
        Node* left;

        Node(int key) : rollNo(key), height(1), right(NULL), left(NULL) {}
};

int height(Node* root)
{
    return root ? root->height : 0;
}

int getBalanceFactor(Node* root)
{
    if(root == NULL)
        return 0;

    return (height(root->left) - height(root->right));
}

Node* RightRotate(Node* root)
{
    Node* x = root->left;
    Node* y = x->right;

    x->right = root;
    root->left = y;

    root->height = 1 + max(height(root->left), height(root->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node* LeftRotate(Node* root)
{
    Node* x = root->right;
    Node* y = x->left;

    x->left = root;
    root->right = y;

    root->height = 1 + max(height(root->left), height(root->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

Node* insert(Node* root, int key, string &rot)
{
    if(root == NULL) return new Node(key);

    if(key > root->rollNo)
        root->right = insert(root->right, key, rot);
    else if(key < root->rollNo)
        root->left = insert(root->left, key, rot);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int bf = getBalanceFactor(root);

    if(bf > 1 && key < root->left->rollNo)
    {
        rot = "LL Rotation";
        return RightRotate(root);
    }
        

    if(bf < -1 && key > root->right->rollNo)
    {
        rot = "RR Rotation";
        return LeftRotate(root);
    }

    if(bf > 1 && key > root->left->rollNo)
    {
        rot = "LR Rotation";
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }
    if(bf < -1 && key < root->right->rollNo)
    {
        rot = "RL Rotation";
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }

    rot = "No rotation";
    return root;
}

Node* minValueNode(Node* node)
{
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key, string &rot)
{
    if(root == NULL)
        return root;

    if(key < root->rollNo)
        root->left = deleteNode(root->left, key, rot);
    else if(key > root->rollNo)
        root->right = deleteNode(root->right, key, rot);
    else
    {
        if(root->left == NULL || root->right == NULL)
        {
            Node* temp = root->left ? root->left : root->right;

            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }

            delete temp;
        }
        else
        {
            Node* temp = minValueNode(root->right);
            root->rollNo = temp->rollNo;
            root->right = deleteNode(root->right, temp->rollNo, rot);
        }
    }

    if(root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int bf = getBalanceFactor(root);

    if(bf > 1 && getBalanceFactor(root->left) >= 0)
    {   
        rot = "LL Rotation";
        return RightRotate(root);
    }
       

    if(bf > 1 && getBalanceFactor(root->left) < 0)
    {
        rot = "LR Rotation";
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }

    
    if(bf < -1 && getBalanceFactor(root->right) <= 0)
    {
        rot = "RR Rotation";
        return LeftRotate(root);
    }
        

    if(bf < -1 && getBalanceFactor(root->right) > 0)
    {
        rot = "RL Rotation";
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }

    rot = "No rotation";
    return root;
}

void inOrder(Node* root)
{
    if(root == NULL) return;

    inOrder(root->left);
    cout << root->rollNo << "/" << root->height << " ";
    inOrder(root->right);
}

void printTreeInfo(Node* root, const string &msg, const string &rotMsg)
{
    cout << "\n--- " << msg << " ---\n";
    cout << "Inorder (rollNo/height): ";
    inOrder(root);
    cout << "\nTree height (root->height): " << height(root) << endl;
    cout << "Root BF: " << getBalanceFactor(root) << endl;
    
    if(rotMsg == "" || rotMsg == "No rotation")
        cout << "Rotation: None\n";
    else
        cout << "Rotation: " << rotMsg << "\n";
}

int main()
{
    Node* root = NULL;
    string msg;
 
    msg = "No rotation";
    root = insert(root, 10, msg);
    printTreeInfo(root, "After inserting 10", msg);

    msg = "No rotation";
    root = insert(root, 5, msg);
    printTreeInfo(root, "After inserting 5", msg);

    msg = "No rotation";
    root = insert(root, 30, msg);
    printTreeInfo(root, "After inserting 30", msg);

    msg = "No rotation";
    root = insert(root, 40, msg);
    printTreeInfo(root, "After inserting 40", msg);

    msg = "No rotation";
    root = insert(root, 15, msg);
    printTreeInfo(root, "After inserting 15", msg);

    msg = "No rotation";
    root = insert(root, 25, msg);
    printTreeInfo(root, "After inserting 25", msg);

    msg = "No rotation";
    root = deleteNode(root, 5, msg);
    printTreeInfo(root, "After deleting 5", msg);

    msg = "No rotation";
    root = deleteNode(root, 30, msg);
    printTreeInfo(root, "After deleting 30", msg);

    msg = "No rotation";
    root = deleteNode(root, 10, msg);
    printTreeInfo(root, "After deleting 10", msg);

    return 0;
}
