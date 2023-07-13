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
int getHight(Node *root)
{
    if (root == nullptr)
        return 0;
    int right = getHight(root->right);
    int left = getHight(root->left);

    if (right > left)
        return right + 1;
    else
        return left + 1;
}
void printNode(Node *root, int level)
{
    if (root == nullptr)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printNode(root->left, level - 1);
        printNode(root->right, level - 1);
    }
}
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
void printTreeLV(Node *root)
{
    for (int i = 0; i < getHight(root); i++)
    {
        cout << "Lv " << i << ": ";
        printNode(root, i);
        cout << "\n";
    }
}

int main()
{
    Tree t;
    int a[100]{7, 4, 12, 3, 6, 8, 1, 5, 10};

    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
        addNode(t.root, a[i]);

    printTreeLV(t.root);
    return 0;
}