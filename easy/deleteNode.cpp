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
Node *findMin(Node *root)
{
    if (root == NULL)
        return root;

    Node *i = root;
    while (i != NULL && i->left != NULL)
    {
        i = i->left;
    }
    return i;
}
Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
        return root;

    if (x > root->data)
        root->right = deleteNode(root->right, x);
    else if (x < root->data)
        root->left = deleteNode(root->left, x);
    else
    {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, root->data);
        }
    }
    return root;
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
    addNode(t.root, 8);
    addNode(t.root, 7);
    addNode(t.root, 2);
    addNode(t.root, 10);
    addNode(t.root, 9);
    addNode(t.root, 13);

    deleteNode(t.root, 8);
    LTR(t.root);
    return 0;
}