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
// check an existence of a node without using recursing
bool interativeSearching(Node *root, int x)
{
    if (root == NULL)
        return false;
    Node *a = root;
    while (a)
    {
        if (a->data == x)
            return true;
        else if (x < a->data)
            a = a->left;
        else
            a = a->right;
    }
    return false;
}
int main()
{
    Tree t;

    addNode(t.root, 4);
    addNode(t.root, 2);
    addNode(t.root, 1);
    addNode(t.root, 3);
    addNode(t.root, 6);
    addNode(t.root, 5);
    addNode(t.root, 7);

    cout << interativeSearching(t.root, 5);
    return 0;
}