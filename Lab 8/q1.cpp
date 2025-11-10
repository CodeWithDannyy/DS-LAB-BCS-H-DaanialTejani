#include<iostream>
using namespace std;

class Tree
{
    public:
        string name;
        Tree* mother; 
        Tree* father;
        Tree(string s) : name(s), mother(NULL), father(NULL) {}
};

void youngestPerson(Tree* root)
{
    if(root == NULL)
    {
        cout << "No tree.";
        return;
    }
    cout << root->name << endl;
}

void leafs(Tree* root)
{
    if(root == NULL) return;
    
    if(root->father == NULL && root->mother == NULL)
    {
        cout << root->name << endl; 
        return;
    }
    leafs(root->father);
    leafs(root->mother);
}

int height(Tree* root)
{
    if(root == NULL) return 0;
    int LH = height(root->mother);
    int RH = height(root->father);
    return (LH > RH ? LH : RH) + 1;
}

void levels(Tree* root, int Level)
{
    if(root == NULL) return ;

    if(Level == 0)
    {
        cout << root->name << " ";
    }
    levels(root->mother, Level-1);
    levels(root->father, Level-1);
}
int main()
{
    Tree* Root = new Tree("John");
    Root->mother = new Tree("Abigail");
    Root->father = new Tree("Arthur");
    Root->mother->mother = new Tree("Sarah");
    Root->mother->father = new Tree("Shawn");
    Root->father->mother = new Tree("Miriam");
    Root->father->father = new Tree("Mark");

    cout << "Root (youngest person) : ";
    youngestPerson(Root);

    cout << "Leaf nodes (ancestors with no known parents)" << endl;
    leafs(Root);

    int h = height(Root);
    cout << "Height of the tree: " << h << endl;

    cout << "Level of each member: " << endl;
    for(int i = 0; i < h; i++)
    {
        cout << "Level " << i << " : ";
        levels(Root, i);
        cout << endl;
    }

    return 0;
}
