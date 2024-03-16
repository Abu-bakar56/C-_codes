#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *head = nullptr;
void insert_at_start(int data)
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
        newnode->next = head;
        head->next = newnode;
        head = newnode;
    }
}
void display()
{
    cout << "element is this " << endl;
    node *ptr = head;
    do
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
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
            if (ptr->next == head)
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
void insert_before_node(int data, int dataa)
{
    node *newnode = new node;
    newnode->data = dataa;
    newnode->next = nullptr;
    if (head == nullptr)
    {
        cout << "list is empty";
    }
    else if (head->data == data)
    {
        newnode->next = head;
        head->next = newnode;
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
            else if (ptr->next == head)
            {
                cout << "data is not found" << endl;
                break;
            }
            else
            {
                ptr = ptr->next;
            }
        }
    }
}
void insert_after_node(int data, int dataa)
{
    node *newnode = new node;
    newnode->data = dataa;
    newnode->next = nullptr;
    if (head == nullptr)
    {
        cout << "list is empty";
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
            else if (ptr->next == head)
            {
                cout << "is not found";
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
void delete_at_start()
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
        node *ptr = head;
        while (ptr->next != head)
        {
           

                ptr=ptr->next;
        }
            
                ptr->next = head->next;
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
            if (ptr->next->data==data)
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
    // insert_at_start(11);
    // insert_at_start(10);
    // insert_at_last(12);
    // insert_at_last(13);
    // insert_before_node(13, 25);
    // insert_after_node(25, 26);
    // display();
    // delete_at_start();
    // delete_at_last();
    // delete_any_node(12);
    // display();
    // search(13);
    // update(24);
    return 0;
}