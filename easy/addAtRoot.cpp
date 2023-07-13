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
void rightRotation(Node *&root)
{
    if (root->left == nullptr)
        return;
    Node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root = temp;
}
void leftRotation(Node *&root)
{
    if (root->right == nullptr)
        return;
    Node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root = temp;
}
void addNodeAtRoot(Node *&root, int input)
{
    if (root == NULL)
        root = new Node(input);
    else
    {
        if (input < root->data)
        {
            addNodeAtRoot(root->left, input);
            rightRotation(root);
        }
        else if (input > root->data)
        {
            addNodeAtRoot(root->right, input);
            leftRotation(root);
        }
    }
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
    addNodeAtRoot(t.root, 8);
    addNodeAtRoot(t.root, 6);
    addNodeAtRoot(t.root, 10);
    return 0;
}