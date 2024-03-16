#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *f = NULL;
node *b = NULL;
int isfull()
{
    node *n = new node;
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isempty()
{
    if (b==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(int data)
{
    if (isfull())
    {
        cout << "stack is full" << endl;
    }
    else
    {
        node *newnode = new node;
        newnode->data = data;
        newnode->next = NULL;
        newnode->next = top;
        top = newnode;
    }
}
int pop()
{
    if (isempty())
    {
        cout << "stack is empty" << endl;
        return -1;
    }
    else
    {
        int val;
        node *g = top;
        top = top->next;
        val = g->data;
        return val;
    }
}
void show()
{
    if (top == NULL)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}
node *stack_top()
{
    return top;
}

int main()
{
    push(34);
    push(4);
    push(3);
    push(77);
    show();
    cout << "pop value is " << pop() << endl;

    // stack_top();

    show();
    return 0;
}