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
int main()
{

    return 0;
}