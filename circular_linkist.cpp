#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head = NULL;
void insert_at_first(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->next = nullptr;
    if (head == nullptr)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        node *ptr = head;
        while (ptr != nullptr)
        {

            if (ptr->next == head)
            {
                ptr->next = newnode;
                newnode->next = head;
                head = newnode;
                break;
            }
            else
            {
                ptr = ptr->next;
            }
        }
    }
}
void show()
{
    node *ptr = head;
    cout << "element in linklist is " << endl;
    do
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }

    while (ptr != head);
}
void insert_at_last(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->next = nullptr;
    if (head == nullptr)
    {
        cout << "linklist is empty" << endl;
    }
    else
    {
        node *ptr = head;
        while (ptr != nullptr)
        {
            if (ptr->next == head)
            {
                ptr->next = newnode;
                newnode->next = head;
                break;
            }
            else
            {
                ptr = ptr->next;
            }
        }
    }
}
void insert_after_specific_node(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->next = nullptr;
    if (head == nullptr)
    {
        cout << "linklist is empty" << endl;
    }
    else
    {
        node *ptr = head;
        while (ptr != nullptr)
        {
            if (ptr->data == data)
            {
                ptr->next = newnode->next;
                ptr->next = newnode;
                break;
            }
            else if (ptr->next == nullptr)
            {
                cout << "data is not match" << endl;
            }
            else
            {
                ptr = ptr->next;
            }
        }
    }
}
void insert_before_specific_node(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->next = nullptr;
    if (head == nullptr)
    {
        cout << "list is empty" << endl;
    }
    else
    {

        if (head->data == data)
        {
            head->next = newnode;
            newnode->next = head;
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
                else if (ptr->next == nullptr)
                {
                    cout << "data is not match";
                }
                else
                {
                    ptr = ptr->next;
                }
            }
        }
    }
}
void search(int data)
{
    if (head == nullptr)
    {
        cout << "list is empty" << endl;
    }
    else
    {
        node *ptr = head;
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
                cout << "data  number is not match" << endl;
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
    if (head == nullptr)
    {
        cout << "list is empty" << endl;
    }
    else
    {
        node *ptr = head;
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
                cout << "data  number is not match" << endl;
            }
            else
            {
                ptr = ptr->next;
            }
        }
    }
}
void delete_at_first()
{
    if (head == nullptr)
    {
        cout << "list is empty";
    }
    else if (head->next == head)
    {
        head = nullptr;
    }

    else
    {
        node *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = head->next;
        head = head->next;
    }
}
void delete_at_last()
{
    if (head == nullptr)
    {
        cout << "list is empty";
    }
    else if (head->next == head)
    {
        head = nullptr;
    }

    else
    {
        node *p = head;
        while (p->next->next != head)
        {
            p = p->next;
        }
        p->next = head;
    }
}
int main()
{
    // insert_at_first(45);
    // insert_at_last(89);
    // delete_at_first();
    // delete_at_last();
    // show();
    //  insert_after_specific_node(1);
    //  insert_before_specific_node(2);
    //  update(89);
    //  search(45);
    // delete_at_first();
    // delete_at_last();

    return 0;
}