#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
int isfull(node *top)
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
int isempty(node *top)
{
    if (top == nullptr)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

node *push(node *top, int data)
{
    node *p = new node;
    if (isfull(p))
    {
        cout << "stack is full ";
    }
    else
    {
        p->data = data;
        p->next = top;
        top = p;
    }
    return top;
}
int pop(node **top)
{
    if (isempty(*top))
    {
        cout << "stack is empty";
    }
    else
    {
        int val;
        val = (*top)->data;
        node *n = *top;
        *top = (*top)->next;
        free(n);
        return val;
    }
}
void show(node *top)
{
    node *ptr=top;
    cout << "element is :" << endl;
    while (ptr != nullptr)
    {
        cout << ptr->data<<endl;
        ptr = ptr->next;
    }
}
int peek(node *ptr, int pos)
{
    for (int i = 0; (i < pos  && ptr != nullptr); i++)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}
int main()
{
    node *top = nullptr;
    top = push(top, 45);
    top = push(top, 1);
    top = push(top, 3);
    top = push(top, 2);

    cout << peek(top, 2);
    return 0;
}