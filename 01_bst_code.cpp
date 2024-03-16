#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
node *create_node(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void inoder(node *root)
{

    if (root != NULL)
    {
        inoder(root->left);
        cout << root->data << " ";
        inoder(root->right);
    }
}
void preorder(node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
node *search(node *root, int key)
{
    while (root != NULL)
    {

        if (root->data == key)
        {
            return root;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
    }
    return NULL;
}
node *search_rec(node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (root->data > key)
    {
        return search_rec(root->left, key);
    }
    else
    {
        return search_rec(root->right, key);
    }
}
node *insert(node *root, int data)
{

    node *prev = nullptr;
    if (root == NULL)
    {
        cout << "tree is empty" << endl;
    }
    while (root != nullptr)
    {
        prev = root;
        if (root->data == data)
        {
            cout << "this element is duplicate so insert is not possible " << endl;
        }
        else if (root->data > data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    node *new1 = create_node(data);
    if (prev->data > data)
    {
        prev->left = new1;
    }
    else
    {
        prev->right = new1;
    }
}
node *inorderPrec(node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

node *deletenode(node *root, int key)
{
    node *ipre;
    if (root == NULL)
    {
        cout << "tree is empty" << endl;
        return nullptr;
    }
    if (root->data == key && root->left == NULL && root->right == NULL)
    {
        free(root);
        return nullptr;
    }
    if (root->data > key)
    {
        root->left = deletenode(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = deletenode(root->right, key);
    }

    else
    {
        ipre = inorderPrec(root);
        root->data = ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
    return root;
}
int main()
{
    node *p = create_node(10);
    node *p1 = create_node(5);
    node *p2 = create_node(15);
    node *p3 = create_node(2);
    node *p4 = create_node(7);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    inoder(p);
    cout << endl;
    // preorder(p);
    // cout<<endl;
    // postorder(p);
    // cout<<endl;
    // node *n = search(p, 15);
    // cout << n->data;
    // cout << endl;
    // node *m = search_rec(p, 7);
    // cout << m->data;
    // insert(p, 3);
    deletenode(p, 15);
    inoder(p);
    return 0;
}