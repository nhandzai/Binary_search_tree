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
void Merge(int *a, int lenA, int *b, int lenB, int *x)
{
    int i, j, count;
    i = j = count = 0;

    while (i < lenA && j < lenB)
    {
        if (a[i] < b[j])
            x[count++] = a[i++];
        else
            x[count++] = b[j++];
    }
    while (i < lenA)
        x[count++] = a[i++];
    while (j < lenB)
        x[count++] = b[j++];
}
void MergeSort(int *a, int n)
{
    if (n <= 1)
        return;

    int mid = n / 2;
    int leftA[mid];
    int rightA[n - mid];

    for (int i = 0; i < mid; i++)
        leftA[i] = a[i];

    int count = 0;
    for (int i = mid; i < n; i++)
        rightA[count++] = a[i];

    MergeSort(leftA, mid);
    MergeSort(rightA, n - mid);
    Merge(leftA, mid, rightA, n - mid, a);
}
void storeTree(Node *root, vector<int> &a)
{
    if (root == NULL)
        return;
    storeTree(root->left, a);
    a.push_back(root->data);
    storeTree(root->right, a);
}
void arrToBst(int *a, Node *root, int *i)
{
    if (root == NULL)
        return;
    arrToBst(a, root->left, i);
    root->data = a[(*i)++];
    arrToBst(a, root->right, i);
}
void bsToBst(Node *root)
{
    vector<int> a;
    storeTree(root, a);
    MergeSort(a.data(), a.size());
    int i = 0;
    arrToBst(a.data(), root, &i);
    a.clear();
}
int main()
{
    Tree t;
    t.root = new Node(10);
    t.root->left = new Node(2);
    t.root->left->left = new Node(8);
    t.root->left->right = new Node(4);
    t.root->right = new Node(7);

    LTR(t.root);
    cout << endl;
    bsToBst(t.root);
    LTR(t.root);
    return 0;
}