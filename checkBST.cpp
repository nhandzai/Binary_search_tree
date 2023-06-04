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
int MaxValue(Node *root)
{
    if (root == NULL)
        return INT16_MIN;

    int right = MaxValue(root->right);
    int left = MaxValue(root->left);

    return max(root->data, max(right, left));
}
int MinValue(Node *root)
{
    if (root == NULL)
        return INT16_MAX;

    int right = MinValue(root->right);
    int left = MinValue(root->left);

    return min(root->data, min(right, left));
}
bool checkBST(Node *root)
{
    if (root == NULL)
        return true;

    if (root->data < MaxValue(root->left))
        return false;
    else if (root->data > MinValue(root->right))
        return false;
    else if (!checkBST(root->left) || !checkBST(root->right))
        return false;
    return true;
}
int main()
{
    Tree t;
    t.root = new Node(6);
    t.root->left = new Node(3);
    t.root->left->left = new Node(1);
    t.root->right = new Node(8);
    t.root->right->left = new Node(7);

    if (checkBST(t.root))
        cout << "true";
    else
        cout << "false";
    return 0;
}
