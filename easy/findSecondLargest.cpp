#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int input, Node *n = NULL)
    {
        this->data = input;
        this->left = this->right = n;
    }
};
struct Tree
{
    Node *root;
    Tree(Node *a = NULL)
    {
        this->root = a;
    }
};
void addNode(Node *&root, int input)
{

    if (root == NULL)
        root = new Node(input);
    else
    {
        if (input < root->data)
            addNode(root->left, input);
        else if (input > root->data)
            addNode(root->right, input);
    }
}
int secondLargest(Node *root)
{
    Node *i = root;
    Node *j = NULL;

    while (i->right != NULL)
    {
        j = i;
        i = i->right;
    }
    if (i->left != NULL)
    {
        j = i->left;
        while (j->right != NULL)
            j = j->right;
    }
    return j->data;
}
int main()
{
    Tree t;
    addNode(t.root, 10);
    addNode(t.root, 8);
    addNode(t.root, 12);
    addNode(t.root, 18);
    addNode(t.root, 17);
    cout << secondLargest(t.root);
    return 0;
}