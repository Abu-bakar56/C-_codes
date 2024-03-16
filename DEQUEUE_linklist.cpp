#include <iostream>
using namespace std;
struct node
{

    int data;
    node *next;
};
node *f = nullptr;
node *b = nullptr;
int isempty()
{
    if (f == nullptr)
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
void enqueuelast(int data)
{
    if (isfull())
    {
        cout << "queue is full";
    }
    else
    {
        node *p = new node;
        p->data = data;
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

void enqueuefirst(int data)
{
    if (isfull())
    {
        cout << "queue is full";
    }
    else
    {
        node *p = new node;
        p->data = data;
        p->next = f;
        if (f == nullptr)
        {
            f = b = p;
        }
        else
        {
            f = p;
        }
    }
}

int dequeuefirst()
{
    if (isempty())
    {
        cout << "queue is empty";
    }
    else
    {
        int val;
        val = f->data;
        node *ptr = f;
        f = f->next;
        delete ptr;
        return val;
    }
}

int dequeuelast()
{
    if (isempty())
    {
        cout << "queue is empty";
    }
    else
    {
        int val;

        node *ptr = b;
        node *tr = b->next;
        val = tr->data;
        b->next = nullptr;
        delete tr;
        return val;
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
    enqueuefirst(78);
     enqueuefirst(8);
      enqueuefirst(11);
      show(f);
      
    return 0;
}