#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *f = NULL;
node *b = NULL;

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
        p->next = nullptr;
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
void show(node *ptr)
{
    cout << "element is :" << endl;
    while (ptr != nullptr)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}
int main()
{
    enqueue(34);
    enqueue(4);
    enqueue(7);
    enqueue(17);
    show(f);
    dequeue();
    show(f);
    return 0;
}