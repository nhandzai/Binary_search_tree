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
void sumKthSmallest(Node *root, int &sum, int &k)
{
    if (root == NULL)
        return;
    sumKthSmallest(root->left, sum, k);
    if (k > 0)
    {
        sum += root->data;
        --k;
    }
    sumKthSmallest(root->right, sum, k);
}
int main()
{
    Node *root = NULL;
    addNode(root, 20);
    addNode(root, 8);
    addNode(root, 4);
    addNode(root, 12);
    addNode(root, 10);
    addNode(root, 14);
    addNode(root, 22);

    int k = 3;
    int sum = 0;
    sumKthSmallest(root, sum, k);
    cout << sum;
    return 0;
}