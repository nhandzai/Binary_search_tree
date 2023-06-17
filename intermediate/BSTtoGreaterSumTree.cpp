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
void addNode(Node *&root, int data)
{
    if (root == nullptr)
        root = new Node(data);
    else
    {
        if (data < root->data)
            addNode(root->left, data);
        else
            addNode(root->right, data);
    }
}

void BSTtoGreatSumTree(Node *root, int *sum)
{
    if (root == nullptr)
        return;

    BSTtoGreatSumTree(root->right, sum);
    int temp = *sum;
    *sum += root->data;
    root->data = temp;
    BSTtoGreatSumTree(root->left, sum);
}
void LTR(Node *root)
{
    if (root == nullptr)
        return;
    LTR(root->left);
    cout << root->data << " ";
    LTR(root->right);
}
int main()
{
    Node *root;
    root = nullptr;
    int a[8]{11, 2, 1, 7, 29, 15, 40, 35};

    for (int i = 0; i < 8; i++)
    {
        addNode(root, a[i]);
    }

    int sum = 0;
    BSTtoGreatSumTree(root, &sum);
    LTR(root);
    return 0;
}