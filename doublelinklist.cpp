#include <iostream>
using namespace std;
struct node
{
    int data;
    node *prev;
    node *next;
};
node *head = NULL;
node *tail = NULL;
void insert_at_first(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
void insert_at_last(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}
void insert_before_any_node(int key, int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = tail = newnode;
    }
    else if (head->data == key)
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    else if (tail->data == key)
    {
        tail->prev->next = newnode;
        tail->prev = newnode->prev;
        newnode->next = tail;
        tail->prev = newnode;
    }
    else
    {
        node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == key)
            {
                ptr->prev->next = newnode;
                ptr->prev = newnode->prev;
                newnode->next = ptr;
                ptr->prev = newnode;
                break;
            }

            else
            {
                ptr = ptr->next;
            }
        }
        if (ptr->next == nullptr)
        {
            cout << " key is not found" << endl;
        }
    }
}
void insert_after_any_node(int key, int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (head == NULL)
    {
        head = tail = newnode;
    }
    else if (head->data == key)
    {
        newnode->next = head->next;
        head->next = newnode;
        newnode->prev = head;
    }
    else if (tail->data == key)
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
    else
    {
        node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == key)
            {
                ptr->next->prev = newnode;
                newnode->next = ptr->next;
                ptr->next = newnode;
                newnode->prev = ptr;
                break;
            }

            else
            {
                ptr = ptr->next;
            }
        }
        if (ptr->next == nullptr)
        {
            cout << " key is not found" << endl;
        }
    }
}
void display_from_start()
{
    node *ptr = head;
    if (head == NULL)
    {
        cout << "linklist is empty" << endl;
    }
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
}
void display_from_last()
{
    node *ptr = tail;
    if (head == NULL)
    {
        cout << "linklist is empty" << endl;
    }
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->data << endl;
            ptr = ptr->prev;
        }
    }
}
void delete_Head()
{
    if (head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }
}

void delete_Last()
{
    if (tail == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        if (head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }
    }
}
void delete_any_node(int key)
{

    if (head == NULL)
    {
        cout << " list is empty";
    }
    else if (head->data == key)
    {
        head = head->next;
        head->prev = NULL;
    }
    else if (tail->data == key)
    {
        tail = tail->prev;
        tail->next = NULL;
    }
    else
    {
        node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == key)
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                delete ptr;
                break;
            }

            else
            {
                ptr = ptr->next;
            }
        }
        if (ptr->next == nullptr)
        {
            cout << " key is not found" << endl;
        }
    }
}
int main()
{
    insert_at_first(23);
    insert_at_first(22);
    insert_at_last(24);
    insert_at_last(25);
    insert_before_any_node(24, 10);
    insert_after_any_node(24, 11);
    delete_Head();
    delete_Last();
    delete_any_node(24);
    display_from_start();
    // display_from_last();
    return 0;
}