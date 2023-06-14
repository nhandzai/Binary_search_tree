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
void addGreaterValue(Node *root, int *a)
{
    if (root == NULL)
        return;
    addGreaterValue(root->right, a);
    root->data += *a;
    *a = root->data;
    addGreaterValue(root->left, a);
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
    addNode(t.root, 10);
    addNode(t.root, 8);
    addNode(t.root, 12);
    addNode(t.root, 18);
    addNode(t.root, 17);
    LTR(t.root);
    cout << endl;

    int a = 0;
    addGreaterValue(t.root, &a);
    LTR(t.root);

    return 0;
}