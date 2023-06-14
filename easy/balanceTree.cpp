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
void LTR(Node *root)
{
    if (root == NULL)
        return;
    LTR(root->left);
    cout << root->data << " ";
    LTR(root->right);
}
void TLR(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    TLR(root->left);
    TLR(root->right);
}
void storeTree(Node *root, vector<int> &a)
{
    if (root == NULL)
        return;
    storeTree(root->left, a);
    a.push_back(root->data);
    storeTree(root->right, a);
};
void makeBalance(vector<int> a, vector<int> &b, int *c, int i, int j)
{
    if (i >= j)
    {
        if (i == j && c[i] == 0)
        {
            b.push_back(a[i]);
            c[i]++;
        }
        return;
    }
    int mid = i + (j - i) / 2;
    if (c[mid] == 0)
    {
        b.push_back(a[mid]);
        c[mid]++;
    }
    makeBalance(a, b, c, i, mid - 1);
    makeBalance(a, b, c, mid + 1, j);
}
Node *balanceTree(Node *root)
{
    vector<int> a, b;
    Tree temp;
    storeTree(root, a);
    int x[a.size()]{};
    makeBalance(a, b, x, 0, a.size() - 1);
    for (int i = 0; i < b.size(); i++)
    {
        addNode(temp.root, b[i]);
    }
    return temp.root;
}
int main()
{
    Tree t;
    vector<int> a;
    addNode(t.root, 4);
    addNode(t.root, 3);
    addNode(t.root, 5);
    addNode(t.root, 2);
    addNode(t.root, 1);
    addNode(t.root, 6);
    addNode(t.root, 7);
    LTR(t.root);
    cout << endl;
    t.root = balanceTree(t.root);
    TLR(t.root);
    return 0;
}