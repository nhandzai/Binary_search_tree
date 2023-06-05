#include <iostream>
#include <vector>
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
void storeTree(Node *root, vector<int> &a)
{
    if (root == NULL)
        return;
    storeTree(root->left, a);
    a.push_back(root->data);
    storeTree(root->right, a);
}
bool is2BstHaveSameElements(Node *rootA, Node *rootB)
{
    if (rootA == NULL && rootB == NULL)
        return true;
    vector<int> a;
    vector<int> b;

    storeTree(rootA, a);
    storeTree(rootB, b);

    return a == b;
}
int main()
{
    Node *root1 = new Node(15);
    root1->left = new Node(10);
    root1->right = new Node(20);
    root1->left->left = new Node(5);
    root1->left->right = new Node(12);
    root1->right->right = new Node(25);

    // Second BST
    Node *root2 = new Node(15);
    root2->left = new Node(12);
    root2->right = new Node(20);
    root2->left->left = new Node(5);
    root2->left->left->right = new Node(10);
    root2->right->right = new Node(25);

    cout << is2BstHaveSameElements(root1, root2);
    return 0;
}