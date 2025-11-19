#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Node {
public:
    int sev, height;
    Node *left, *right;
    Node(int s) : sev(s), height(1), left(NULL), right(NULL) {}
};

int h(Node* n){ return n ? n->height : 0; }
int bf(Node* n){ return n ? h(n->left) - h(n->right) : 0; }

Node* rightRotate(Node* y){
    Node* x = y->left;
    y->left = x->right;
    x->right = y;

    y->height = 1 + max(h(y->left), h(y->right));
    x->height = 1 + max(h(x->left), h(x->right));
    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    x->right = y->left;
    y->left = x;

    x->height = 1 + max(h(x->left), h(x->right));
    y->height = 1 + max(h(y->left), h(y->right));
    return y;
}

Node* insert(Node* root, int sev, string &rot){
    if(!root) return new Node(sev);

    if(sev < root->sev) root->left = insert(root->left, sev, rot);
    else if(sev > root->sev) root->right = insert(root->right, sev, rot);
    else return root;

    root->height = 1 + max(h(root->left), h(root->right));
    int bal = bf(root);

    if(bal > 1 && sev < root->left->sev){
        rot = "LL Rotation";
        return rightRotate(root);
    }
    if(bal < -1 && sev > root->right->sev){
        rot = "RR Rotation";
        return leftRotate(root);
    }
    if(bal > 1 && sev > root->left->sev){
        rot = "LR Rotation";
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(bal < -1 && sev < root->right->sev){
        rot = "RL Rotation";
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* minNode(Node* root){
    while(root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int sev, string &rot){
    if(!root) return root;

    if(sev < root->sev) root->left = deleteNode(root->left, sev, rot);
    else if(sev > root->sev) root->right = deleteNode(root->right, sev, rot);
    else {
        if(!root->left || !root->right){
            Node* temp = root->left ? root->left : root->right;
            if(!temp){
                temp = root;
                root = NULL;
            } else *root = *temp;
            delete temp;
        } else {
            Node* temp = minNode(root->right);
            root->sev = temp->sev;
            root->right = deleteNode(root->right, temp->sev, rot);
        }
    }

    if(!root) return root;

    root->height = 1 + max(h(root->left), h(root->right));
    int bal = bf(root);

    if(bal > 1 && bf(root->left) >= 0){
        rot = "LL Rotation";
        return rightRotate(root);
    }
    if(bal > 1 && bf(root->left) < 0){
        rot = "LR Rotation";
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(bal < -1 && bf(root->right) <= 0){
        rot = "RR Rotation";
        return leftRotate(root);
    }
    if(bal < -1 && bf(root->right) > 0){
        rot = "RL Rotation";
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int highest(Node* root){
    while(root->right) root = root->right;
    return root->sev;
}

void info(Node* root, string op, string rot){
    cout << "\n--- " << op << " ---\n";
    cout << "Tree height: " << (root ? root->height : 0) << "\n";
    cout << "Rotation: " << rot << "\n";
    cout << "Highest severity: " << highest(root) << "\n";
}

int main(){
    Node* root = NULL;
    string r;

   
    r = "None";
    root = insert(root, 50, r);
    info(root, "Inserted 50", r);

    r = "None";
    root = insert(root, 20, r);
    info(root, "Inserted 20", r);

    r = "None";
    root = insert(root, 80, r);
    info(root, "Inserted 80", r);

    r = "None";
    root = insert(root, 10, r);
    info(root, "Inserted 10", r);

    r = "None";
    root = insert(root, 60, r);
    info(root, "Inserted 60", r);

    r = "None";
    root = insert(root, 90, r);
    info(root, "Inserted 90", r);

    // Line-by-line deletes
    r = "None";
    root = deleteNode(root, 20, r);
    info(root, "Deleted 20", r);

    r = "None";
    root = deleteNode(root, 80, r);
    info(root, "Deleted 80", r);

    r = "None";
    root = deleteNode(root, 50, r);
    info(root, "Deleted 50", r);

    return 0;
}
