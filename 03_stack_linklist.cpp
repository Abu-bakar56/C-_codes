#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *Top = NULL;
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
    if (Top == NULL)
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
        node *p = new node;
        p->data = data;
        p->next = Top;
        Top = p;
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
        val = Top->data;
        node *n = Top;
        Top = Top->next;
        delete (n);
        return val;
    }
}
void show()
{
    node *ptr = Top;
    cout << "elements in stack is this " << endl;
    while (ptr != nullptr)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}
node *stack_top()
{
    return Top;
}
void search(int data)
{
    if (isempty())
    {
        cout << "list is empty" << endl;
    }
    else
    {
        node *ptr = Top;
        while (ptr != nullptr)
        {
            if (ptr->data == data)
            {
                cout << "data is match"
                     << "  " << endl;
                break;
            }
            else if (ptr->next == nullptr)
            {
                cout << "registration  number is not match" << endl;
            }
            else
            {
                ptr = ptr->next;
            }
        }
    }
}
void update(int data)
{
    if (isempty())
    {
        cout << "list is empty" << endl;
    }
    else
    {
        node *ptr = Top;
        while (ptr != nullptr)
        {
            if (ptr->data == data)
            {
                cout << "data is match"
                     << "  " << endl;
                cout << "change and enter the data" << endl;
                cin >> ptr->data;
                break;
            }
            else if (ptr->next == nullptr)
            {
                cout << "registration  number is not match" << endl;
            }
            else
            {
                ptr = ptr->next;
            }
        }
    }
}
int main()
{
    push(34);
    push(4);
    push(3);
    push(77);
    show();
    cout << "pop value is " << pop() << endl;

    stack_top();
    search(3);
    update(4);
    show();

    return 0;
}