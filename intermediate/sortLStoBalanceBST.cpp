#include <iostream>
using namespace std;
struct NodeList
{
    int data;
    NodeList *next;
    NodeList(int input)
    {
        data = input;
        next = nullptr;
    }
};
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
void sortListToBBST(Node *&root, NodeList *start, NodeList *end)
{
    if (start == nullptr)
        return;
    NodeList *slow;
    NodeList *fast = slow = start;

    int i = 0;
    while (fast->next != end)
    {
        ++i;
        fast = fast->next;
    }
    int j = 0;
    while (j < i / 2)
    {
        slow = slow->next;
        ++j;
    }
    addNode(root, slow->data);
    if (start->next == end)
        return;

    sortListToBBST(root, start, slow);
    sortListToBBST(root, slow->next, end);
}
void lrt(Node *root)
{
    if (root == NULL)
        return;
    lrt(root->left);
    cout << root->data << " ";
    lrt(root->right);
}
int main()
{
    Node *root;
    root = nullptr;

    NodeList *a = new NodeList(1);
    NodeList *b = new NodeList(2);
    a->next = b;
    NodeList *c = new NodeList(3);
    b->next = c;
    NodeList *d = new NodeList(4);
    c->next = d;
    NodeList *e = new NodeList(5);
    d->next = e;
    NodeList *f = new NodeList(6);
    e->next = f;
    NodeList *g = new NodeList(7);
    f->next = g;

    sortListToBBST(root, a, nullptr);
    lrt(root);
    return 0;
}