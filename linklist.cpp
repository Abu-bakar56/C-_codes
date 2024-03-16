#include <iostream>
using namespace std;
struct node
{
    int reg;
    string name;
    float cgpa;
    node *next;
};
node *head_SE = nullptr;
node *head_CS = nullptr;
node *head_AI = nullptr;
node *head_AF = nullptr;
void insert_node_SE()
{
    node *new_node = new node;
    cout << "enter the registeration " << endl;
    cin >> new_node->reg;
    cout << "enter the name " << endl;
    cin.ignore();
    getline(cin, new_node->name);
    cout << "enter the CGPA " << endl;
    cin >> new_node->cgpa;
    new_node->next = nullptr;
    if (head_SE == nullptr)
    {
        head_SE = new_node;
    }
    else
    {
        node *ptr = head_SE;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}
void insert_node_CS()
{
    node *new_node = new node;
    cout << "enter the registeration " << endl;
    cin >> new_node->reg;
    cout << "enter the name " << endl;
    cin.ignore();
    getline(cin, new_node->name);
    cout << "enter the CGPA " << endl;
    cin >> new_node->cgpa;
    new_node->next = nullptr;
    if (head_CS == nullptr)
    {
        head_CS = new_node;
    }
    else
    {
        node *ptr = head_CS;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}
void insert_node_AI()
{
    node *new_node = new node;
    cout << "enter the registeration " << endl;
    cin >> new_node->reg;
    cout << "enter the name " << endl;
    cin.ignore();
    getline(cin, new_node->name);
    cout << "enter the CGPA " << endl;
    cin >> new_node->cgpa;
    new_node->next = nullptr;
    if (head_AI == nullptr)
    {
        head_AI = new_node;
    }
    else
    {
        node *ptr = head_AI;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}
void insert_node_AF()
{
    node *new_node = new node;
    cout << "enter the registeration " << endl;
    cin >> new_node->reg;
    cout << "enter the name " << endl;
    cin.ignore();
    getline(cin, new_node->name);
    cout << "enter the CGPA " << endl;
    cin >> new_node->cgpa;
    new_node->next = nullptr;
    if (head_AF == nullptr)
    {
        head_AF = new_node;
    }
    else
    {
        node *ptr = head_AF;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}

void show()
{
    node *ptr = head_AF;
    cout << "Student details:" << endl;
    while (ptr != nullptr)
    {
        cout << "Name: " << ptr->name << endl;
        cout << "Registration: " << ptr->reg << endl;
        cout << "CGPA: " << ptr->cgpa << endl;
        ptr = ptr->next;
    }
}
int main()
{
    cout << "information for SOFTWARE STUDENT" << endl;
    insert_node_SE();
   
    cout << "information OF SOFTWARE STUDENT" << endl;
    show();

    return 0;
}