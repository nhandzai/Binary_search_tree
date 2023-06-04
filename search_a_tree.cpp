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
Node *findX(Node *root, int x)
{
    if (root == NULL || root->data == x)
        return root;
    else if (root->data > x)
        return findX(root->left, x);
    else
        return findX(root->right, x);
}
void LTR(Node *root)
{
    if (root == NULL)
        return;
    LTR(root->left);
    cout << root->data << " ";
    LTR(root->right);
}
int main()
{
    Tree t;
    addNode(t.root, 5);
    addNode(t.root, 2);
    addNode(t.root, 7);
    addNode(t.root, 3);
    addNode(t.root, 9);

    cout << findX(t.root, 9)->data;
    return 0;
}