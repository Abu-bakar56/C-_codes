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
void insert_node(node *root, int data)
{
    if (root == NULL)
    {
        root = create_node(data);
    }
    else
    {
        node *temp = root;
        while (temp != NULL)
        {
            if (data > temp->data)
            {
                if (temp->right == NULL)
                {
                    temp->right = create_node(data);
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
            else if (data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = create_node(data);
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                cout << " this number is duplicate so it is not insert" << endl;
                break;
            }
        }
    }
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
void preorder(node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
node *Maxvalue(node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
node *Minvalue(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
node *delete_node(node *root, int data)
{
    if (root == NULL)
    {
        cout << "tree is empty" << endl;
    }
    else if (data > root->data)
    {
        root->right = delete_node(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = delete_node(root->left, data);
    }
    else
    {
        while (root != NULL)
        {
            if (root->data == data)
            {
                if (root->left == NULL && root->right == NULL)
                {
                    return NULL;
                }
                else
                {
                    if (root->right == NULL)
                    {
                        node *temp = Maxvalue(root->left);
                        root->data = temp->data;
                        root->left = delete_node(root->left, root->data);
                    }
                    else
                    {

                        node *temp = Minvalue(root->right);
                        root->data = temp->data;
                        root->right = delete_node(root->right, root->data);
                    }
                }
            }
        }
    }
}
int main()
{
    // creating the node in for tree
    node *p = create_node(100);
    node *p1 = create_node(20);
    node *p2 = create_node(200);
    node *p3 = create_node(10);
    node *p4 = create_node(30);
    node *p5 = create_node(150);

    // linking node in tree
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->left = p5;

    // creating the node and link through function in tree
    insert_node(p, 300);

    // tree look like this
    //        100
    //      /    \
    //    20     200
    //   / \     / \
    //  10  30  150 300

delete_node(p,150);
    cout << "INORDER TRAVERSAL OF BINARY TREE  =" << endl;
    inorder(p);
    cout << endl;
    cout << "PREORDER TRAVERSAL OF BINARY TREE  =" << endl;
    preorder(p);
    cout << endl;
    cout << "POSTORDER TRAVERSAL OF BINARY TREE  =" << endl;
    postorder(p);
    return 0;
}