#include <iostream>
using namespace std;
struct node
{
    int data;
    int priority;
    node *next;
};
node *f = NULL;
node *b = NULL;
int isempty()
{
    if (b == NULL)
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
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue()
{
    node *newnode = new node;
    cout << "Enter the data of node: ";
    cin >> newnode->data;
    cout << "Enter the priority of node: ";
    cin >> newnode->priority;
    newnode->next = NULL;

    if (isempty())
    {
        b = f = newnode;
    }
    else if (newnode->priority > b->priority)
    {
        b->next = newnode;
        b = newnode;
    }

    else
    {
        node *temp = f;
        while (temp->next != NULL && temp->next->priority <= newnode->priority)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void dequeue()
{
    if (isempty())
    {
        cout << "queue is empty" << endl;
    }
    else
    {

        f = f->next;
    }
}

void display()
{
    if (isempty())
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        node *temp = f;
        while (temp != NULL)
        {
            cout << "Details are: " << endl;
            cout << "Data: " << temp->data << endl;
            cout << "Priority: " << temp->priority << endl;
            temp = temp->next;
        }
    }
}
int main()
{
    enqueue();
    enqueue();
    enqueue();

    // dequeue();
    display();
    return 0;
}
