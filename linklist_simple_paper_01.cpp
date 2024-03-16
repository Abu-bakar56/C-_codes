#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head = nullptr;
void display()
{
    if (head == nullptr)
    {
        cout << "list is empty" << endl;
    }
    else
    {
        cout << "element is this " << endl;
        node *ptr = head;
        while (ptr != nullptr)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
}
void insert_at_start(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->next = nullptr;
    if (head == nullptr)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void insert_at_last(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->next = nullptr;
    if (head == nullptr)
    {
        head = newnode;
    }
    else
    {
        node *ptr = head;
        while (ptr != nullptr)
        {
            if (ptr->next == nullptr)
            {
                ptr->next = newnode;
                break;
            }
            else
            {
                ptr = ptr->next;
            }
        }
    }
}
void insert_before_any_node(int data, int dataa)
{
    node *newnode = new node;
    newnode->data = dataa;
    newnode->next = nullptr;
    if (head == nullptr)
    {
        head = newnode;
    }
    else
    {
        node *ptr = head;
        while (ptr != nullptr)
        {
            if (ptr->next->data == data)
            {
                newnode->next = ptr->next;
                ptr->next = newnode;
                break;
            }
            else
            {
                ptr = ptr->next;
            }
        }
    }
}
void insert_after_any_node(int data, int dataa)
{
    node *newnode = new node;
    newnode->data = dataa;
    newnode->next = nullptr;
    if (head == nullptr)
    {
        head = newnode;
    }
    else
    {
        node *ptr = head;
        while (ptr != nullptr)
        {
            if (ptr->data == data)
            {
                newnode->next = ptr->next;
                ptr->next = newnode;
                break;
            }
            else
            {
                ptr = ptr->next;
            }
        }
    }
}
void search(int data)
{
    node *ptr = head;
    while (ptr != nullptr)
    {
        if (ptr->data == data)
        {
            cout << "data is found" << endl;
            break;
        }
        else if (ptr->next == nullptr)
        {
            cout << "data is not founded" << endl;
            break;
        }
        else
        {
            ptr = ptr->next;
        }
    }
}
void search_duplicate(int data)
{

    node *ptr = head;
    while (ptr != nullptr)
    {
        int count = 0;
        if (ptr->data == data && count < 5)
        {
            count++;
            cout << "data is found in  " << count + 1 << "time " << endl;
            break;
        }
        else if (ptr->next == nullptr)
        {
            cout << "data is not founded" << endl;
            break;
        }
        else
        {
            ptr = ptr->next;
        }
    }
}
void update(int data)
{
    node *ptr = head;
    while (ptr != nullptr)
    {
        if (ptr->data == data)
        {
            cout << "data is found " << endl;
            cout << "now update the data " << endl;
            cin >> ptr->data;
            break;
        }
        else if (ptr->next == nullptr)
        {
            cout << "data is not found";
            break;
        }
        else
        {
            ptr = ptr->next;
        }
    }
}
void delete_at_first()
{
    if (head == nullptr)
    {
        cout << "list is empty";
    }
    else
    {
        head = head->next;
    }
}
void delete_at_last()
{
    if (head == nullptr)
    {
        cout << "list is empty";
    }
    else
    {
        node *ptr = head;
        while (ptr != nullptr)
        {
            if (ptr->next->next == nullptr)
            {
                ptr->next = nullptr;
                break;
            }
            else
            {
                ptr = ptr->next;
            }
        }
    }
}
void delete_any_node(int data)
{
    if (head == nullptr)
    {
        cout << "list is empty";
    }
    else
    {
        node *ptr = head;
        while (ptr != nullptr)
        {
            if (ptr->next->data == data)
            {
                ptr->next = ptr->next->next;
                break;
            }
            else if (ptr->next->next == nullptr)
            {
                cout << "list is not found";
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
    insert_at_start(12);
    // insert_at_start(11);
    // insert_at_last(13);
    // insert_at_last(14);
    // insert_before_any_node(13, 45);
    // insert_after_any_node(45, 11);
    display();
    // delete_at_first();
    // delete_any_node(45);
    delete_at_last();
    display();
    // update(12);
    // search(11);
    // search_duplicate(11);
    return 0;
}