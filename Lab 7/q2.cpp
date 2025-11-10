#include<iostream>
using namespace std;

class BST
{
    public:
        string songName;
        int playCounts;
        BST* left;
        BST* right;
        BST(string sN, int pC) : songName(sN), playCounts(pC), left(NULL), right(NULL) {}
};

BST* insert(BST* root, string name, int count)
{
    if(root == NULL)
        return new BST(name, count);
    if(root->playCounts > count)
        root->left = insert(root->left, name, count);
    if(root->playCounts < count)
        root->right = insert(root->right, name, count);
    return root;
}

BST* search(BST* root, int playCount)
{
    if(root == NULL)
        return NULL;
    else if(playCount < root->playCounts)
        return search(root->left, playCount);
    else if(playCount > root->playCounts)
        return search(root->right, playCount);
    else
        return root;
}

void inorder(BST* root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout << "("<< root->songName  << ", " << root->playCounts << ") ";
    inorder(root->right);
}

void postOrder(BST* root)
{
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << "("<< root->songName  << ", " << root->playCounts << ") ";
}

BST* deleteNode(BST* root, int pC)
{
    if(root == NULL)
        return root;
    if(pC < root->playCounts)
        root->left = deleteNode(root->left, pC);
    else if(pC > root->playCounts)
        root->right = deleteNode(root->right, pC);
    else
    {
        if(root->right == NULL && root->left == NULL)
        {
            delete root;
            return NULL;
        }
        else if(root->left == NULL)
        {
            BST* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL)
        {
            BST* temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            BST* temp = root->right;
            while(temp->left != NULL)
                temp = temp->left;
            root->songName = temp->songName;
            root->playCounts = temp->playCounts;
            root->right = deleteNode(root->right, temp->playCounts);
        }
    }
    return root;
}

int main()
{
    BST* root = NULL;
    root = insert(root, "When the Sun Hits", 240);
    root = insert(root, "Alison", 310);
    root = insert(root, "Cherry-coloured Funk", 190);
    root = insert(root, "Sometimes", 280);
    root = insert(root, "Blown a Wish", 150);
    root = insert(root, "Heart Shaped Box (shoegaze cover)", 270);
    root = insert(root, "Only Shallow", 325);
    root = insert(root, "Blue Light", 165);
    root = insert(root, "Machine Gun", 295);
    root = insert(root, "Sleep Apnea", 175);

    cout << "Inorder Traversel : " << endl;
    inorder(root); 
    cout << endl;
    cout << endl;
    cout << "Post Order Traversel : " << endl;
    postOrder(root); 

    cout << endl;
    cout << endl;
    BST* searchR = search(root, 295);
    if(searchR)
    {
        cout << "Searched Song : ";
        cout << searchR->songName << ", " << searchR->playCounts << endl;
    }
    else
        cout << "not found" << endl;

    root = deleteNode(root, 310);

    cout << "Inorder Traversel(After deletion) : " << endl;
    inorder(root);
}
