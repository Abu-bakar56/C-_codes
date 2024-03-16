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
void insert_node(node *root, int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL)
    {
        root = newnode;
    }
    else
    {
        node *temp = root;
        while (root != NULL)
        {
            if (data > temp->data)
            {
                if (temp->right == NULL)
                {
                    temp->right = newnode;
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
                    temp->left = newnode;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                cout << " duplicate is found so not insert " << endl;
            }
        }
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
    node *p = create_node(10);
    node *p1 = create_node(5);
    node *p2 = create_node(15);
    node *p3 = create_node(2);
    node *p4 = create_node(7);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    cout << "inoder terverasal before is =" << endl;
    inoder(p);
    insert_node(p, 3);
    delete_node(p,15);
    cout << endl;
    cout << "inoder terverasal after  is =" << endl;
    inoder(p);
    return 0;
}