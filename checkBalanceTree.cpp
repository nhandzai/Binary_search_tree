#include <iostream>
#include <cmath>
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
void LTR(Node *root)
{
    if (root == NULL)
        return;
    LTR(root->left);
    cout << root->data << " ";
    LTR(root->right);
}
int checkBalanceTree(Node *root)
{
    if (root == NULL)
        return 0;
    int left = checkBalanceTree(root->left);
    if (left == -1)
        return -1;
    int right = checkBalanceTree(root->right);
    if (right == -1)
        return -1;
    if (abs(right - left) > 1)
        return -1;
    else
        return max(left, right) + 1;
}
int main()
{
    Tree t;
    t.root = new Node(10);
    t.root->left = new Node(2);
    t.root->left->left = new Node(8);
    t.root->left->right = new Node(4);
    t.root->right = new Node(7);

    if (checkBalanceTree(t.root) > 0)
        cout << "true";
    else
        cout << "false";
    return 0;
}