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

void search(node *root, int key);

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

void search(node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            if (root->left != NULL)
            {
                enqueue(root->left->data);
            }
            if (root->right != NULL)
            {
                enqueue(root->right->data);
            }
            break;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
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

    cout << "Level-order traversal: ";
    level_order_traversal(p);

    return 0;
}
