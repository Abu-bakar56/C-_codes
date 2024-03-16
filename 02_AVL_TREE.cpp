#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    int height;
};

int get_height(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

int get_balance_factor(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return get_height(n->left) - get_height(n->right);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

node *create_node(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

node *right_rotate(node *y)
{
    node *x = y->left;
    node *t2 = x->right;

    x->right = y;
    y->left = t2;

    x->height = max(get_height(x->right), get_height(x->left)) + 1;
    y->height = max(get_height(y->right), get_height(y->left)) + 1;
    return x;
}

node *left_rotate(node *x)
{
    node *y = x->right;
    node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(get_height(x->right), get_height(x->left)) + 1;
    y->height = max(get_height(y->right), get_height(y->left)) + 1;

    return y;
}

node *insert(node *n, int data)
{
    if (n == NULL)
    {
        return create_node(data);
    }
    if (data < n->data)
    {
        n->left = insert(n->left, data);
    }
    else if (data > n->data)
    {
        n->right = insert(n->right, data);
    }

    n->height = 1 + max(get_height(n->left), get_height(n->right));
    int bf = get_balance_factor(n);

    // Left Left Case
    if (bf > 1 && data < n->left->data)
    {
        return right_rotate(n);
    }
    // Right Right Case
    if (bf < -1 && data > n->right->data)
    {
        return left_rotate(n);
    }
    // Left Right Case
    if (bf > 1 && data > n->left->data)
    {
        n->left = left_rotate(n->left);
        return right_rotate(n);
    }
    // Right Left Case
    if (bf < -1 && data < n->right->data)
    {
        n->right = right_rotate(n->right);
        return left_rotate(n);
    }
    return n;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    node *root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    inorder(root);

    return 0;
}
