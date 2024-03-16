#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node *next;
};

node *f = NULL;
node *b = NULL;

node *create_node(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void insert_in_tree(node *&root, int data)
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
                cout << " data is duplicate so this not insert " << endl;
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

int isempty()
{
    if (b == nullptr)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull()
{
    node *n = new node;
    if (n == nullptr)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(int val)
{
    if (isfull())
    {
        cout << "queueue is  full and over flow";
    }
    else
    {
        node *p = new node;
        p->data = val;
        p->next = NULL;
        if (f == nullptr)
        {
            f = b = p;
        }
        else
        {
            b->next = p;
            b = p;
        }
    }
}
int dequeue()
{
    if (isempty())
    {
        cout << "queue is empty";
        return -1;
    }
    else
    {
        int data;
        node *g = f;
        data = g->data;
        f = f->next;
        delete g;
        return data;
    }
}

void search(node *root, int key)
{
    node *temp = root;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            if (temp->left != NULL)
            {
                enqueue(temp->left->data);
            }
            if (temp->right != NULL)
            {
                enqueue(temp->right->data);
            }
            break;
        }
        else if (key > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
}

void level_order_traversal(node *root)
{
    node *temp = root;
    if (temp == NULL)
    {
        cout << "there is no tree";
    }
    else
    {
        enqueue(temp->data);

        while (!isempty())
        {
            int currentData = dequeue();
            cout << currentData << " ";
            search(temp, currentData);
        }
    }
}

int main()
{

    node *p = create_node(50);
    node *p1 = create_node(30);
    node *p2 = create_node(60);
    node *p3 = create_node(15);
    node *p4 = create_node(45);
    node *p5 = create_node(55);
    node *p6 = create_node(70);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    cout << "inorder traversal of tree before is  =" << endl;
    inorder(p);
    cout << endl;
    insert_in_tree(p, 67);
    cout << "inorder traversal of tree after  is =" << endl;
    inorder(p);
    cout << endl;
    cout << "preorder traversal of tree is =" << endl;
    preorder(p);
    cout << endl;
    cout << "postorder traversal of tree is =" << endl;
    postorder(p);
    cout << endl;
    cout << "Level-order traversal: ";
    level_order_traversal(p);

    return 0;
}
