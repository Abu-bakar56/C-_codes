#include <iostream>
using namespace std;
struct List
{
    int reg;
    float CGPA;
    string Name;

    List *ptr;
};

List *Head = NULL;

void insert_at_last()
{
    List *node = new List;
    cout << "NAME:";
    cin.ignore();
    getline(cin, node->Name);
    cout << "REGESTRATION:";
    cin >> node->reg;
    cout << "CGPA:";
    cin >> node->CGPA;

    node->ptr = NULL;

    if (Head == NULL)
    {
        Head = node;
        node->ptr = Head;
    }
    else
    {
        List *temp = Head;
        while (temp)
        {
            if (temp->ptr == Head)
            {
                temp->ptr = node;
                node->ptr = Head;
                break;
            }
            else
            {
                temp = temp->ptr;
            }
        }
    }
    cout << endl
         << endl;
}
void insert_at_start()
{
    List *node = new List;
    cout << "NAME:";
    cin.ignore();
    getline(cin, node->Name);
    cout << "REGESTRATION:";
    cin >> node->reg;
    cout << "CGPA:";
    cin >> node->CGPA;

    node->ptr = NULL;

    if (Head == NULL)
    {
        Head = node;
        node->ptr = Head;
    }
    else
    {
        List *temp = Head;
        while (temp)
        {
            if (temp->ptr == Head)
            {
                node->ptr = Head;
                Head = node;
                temp->ptr = Head;
                break;
            }
            else
            {
                temp = temp->ptr;
            }
        }
    }
    cout << endl
         << endl;
}

void insert_after_specific_node(int REG)
{

    if (Head == NULL)
    {
        cout << "No node inserted because List is empty" << endl;
    }
    else
    {

        List *temp = Head;
        while (temp)
        {
            if (temp->reg == REG)
            {
                List *node = new List;
                cout << "Enter Name:";
                cin.ignore();
                getline(cin, node->Name);
                cout << "Enter Regestration:";
                cin >> node->reg;
                cout << "Enter CGPA:";
                cin >> node->CGPA;
                node->ptr = NULL;

                node->ptr = temp->ptr;
                temp->ptr = node;
                break;
            }
            else if (temp->ptr == Head)
            {
                cout << "No node inserted because Data does not matched" << endl;
                break;
            }
            else
            {
                temp = temp->ptr;
            }
        }
    }
}

void insert_before_specific_node(int REG)
{

    if (Head == NULL)
    {
        cout << "Node is not Inserted because List is Empty" << endl;
    }
    else
    {
        if (Head->reg == REG)
        {
            List *node = new List;
            cout << "Enter Name:";
            cin.ignore();
            getline(cin, node->Name);
            cout << "Enter CGPA:";
            cin >> node->CGPA;
            cout << "Enter Regestration Number:";
            cin >> node->reg;

            node->ptr = NULL;

            node->ptr = Head;
            Head = node;
        }
        else
        {
            List *temp = Head;
            while (temp)
            {
                if (temp->ptr->reg == REG)
                {

                    List *node = new List;
                    cout << "Enter Name:";
                    cin.ignore();
                    getline(cin, node->Name);
                    cout << "Enter CGPA:";
                    cin >> node->CGPA;
                    cout << "Enter Regestration Number:";
                    cin >> node->reg;

                    node->ptr = NULL;

                    node->ptr = temp->ptr;
                    temp->ptr = node;
                    cout << "Node is inserted before specified Node" << endl;
                    break;
                }
                else if (temp->ptr->ptr == Head)
                {
                    cout << "Node is not Inserted because Data does not exists in List" << endl;
                }
                else
                {
                    temp = temp->ptr;
                }
            }
        }
    }

    cout << endl
         << endl;
}

void search(int REG)
{
    if (Head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        List *temp = Head;
        while (temp)
        {
            if (temp->reg == REG)
            {
                cout << "NAME:" << temp->Name << endl;
                cout << "CGPA:" << temp->CGPA << endl;
                cout << "REG:" << temp->reg << endl;
                break;
            }
            else if (temp->ptr == Head)
            {
                cout << "Data does not exist in LIST" << endl;
                break;
            }
            else
            {
                temp = temp->ptr;
            }
        }
    }
    cout << endl
         << endl;
}

void update(int REG)
{
    if (Head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        List *temp = Head;
        while (temp)
        {
            if (temp->reg == REG)
            {
                cout << "Enter NAME:";
                cin.ignore();
                getline(cin, temp->Name);
                cout << "Enter CGPA:";
                cin >> temp->CGPA;
                cout << "Enter REG:";
                cin >> temp->reg;

                cout << "\t Data Updated" << endl;
                break;
            }
            else if (temp->ptr == Head)
            {
                cout << "Data does not exist in LIST" << endl;
                break;
            }
            else
            {
                temp = temp->ptr;
            }
        }
    }
    cout << endl
         << endl;
}

void search_Duplicate(float cgpa)
{
    int count = 0;
    if (Head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {

        List *temp = Head;
        while (temp)
        {
            if (temp->CGPA == cgpa)
            {
                count++;
                temp = temp->ptr;
                if (temp == Head)
                {
                    break;
                }
            }
            else if (temp->ptr == Head && count == 0)
            {
                cout << "Data does not exist in LIST" << endl;
                break;
            }
            else
            {
                temp = temp->ptr;
                if (temp == Head)
                {
                    break;
                }
            }
        }
    }
    cout << endl;
    if (count >= 2)
    {
        cout << "Number of students with Same CGPA's are:" << count << endl;
    }
    else
    {
        cout << "No Students with Duplicate CGPA's" << endl;
    }
    cout << endl
         << endl;
}

void Delete_any(int REG)
{
    if (Head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        if (Head->reg == REG)
        {
            List *temp = Head;
            while (temp)
            {
                if (temp->ptr == Head)
                {
                    Head = Head->ptr;
                    temp->ptr = Head;
                    cout << endl
                         << "\t node deleted" << endl;
                    break;
                }
                else
                {
                    temp = temp->ptr;
                }
            }
        }
        else
        {

            List *temp = Head;
            while (temp)
            {
                if (temp->ptr->reg == REG)
                {
                    temp->ptr = temp->ptr->ptr;
                    cout << "\t Node deleted" << endl;
                    break;
                }
                else if (temp->ptr->ptr == Head)
                {
                    cout << "Data not found in List" << endl;
                    break;
                }
                else
                {
                    temp = temp->ptr;
                }
            }
        }
    }
}

void Delete_First()
{
    if (Head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        List *temp = Head;
        while (temp)
        {
            if (temp->ptr == Head)
            {
                Head = Head->ptr;
                temp->ptr = Head;
                cout << endl
                     << "Fisrt node deleted" << endl;
                break;
            }
            else
            {
                temp = temp->ptr;
            }
        }
    }
}

void Delete_Last()
{
    if (Head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        if (Head->ptr == Head)
        {
            Head = Head->ptr;
        }
        else
        {
            List *temp = Head;
            while (temp)
            {
                if (temp->ptr->ptr == Head)
                {
                    temp->ptr = temp->ptr->ptr;
                    cout << endl
                         << "Last node Deleted" << endl;
                    break;
                }
                else
                {
                    temp = temp->ptr;
                }
            }
        }
    }
}

void Display()
{

    if (Head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        cout << "\t \t DISPLAYING DATA" << endl;
        List *temp = Head;
        while (temp)
        {
            cout << "NAME:" << temp->Name << endl;
            cout << "REGESTARTION:" << temp->reg << endl;
            cout << "CGPA:" << temp->CGPA << endl;
            cout << endl
                 << endl;
            temp = temp->ptr;
            if (temp == Head)
            {
                break;
            }
        }
    }
}
void MAIN()
{
    int Reg;
    int choice;
    do
    {

        cout << "1. Insert Node:" << endl;
        cout << "2. Search Node  Data:" << endl;
        cout << "3. Update Node  Data:" << endl;
        cout << "4. Display List Data:" << endl;
        cout << "5. Delete Node:" << endl;
        cout << "6. Search Duplicate:" << endl;
        cout << "7. Quit" << endl;
        cout << "Choice any options by its number:";

        cin >> choice;
        cout << endl
             << endl;
        switch (choice)
        {
        case 1:
        {
            system("cls");
            char ch;
            cout << "a. Insert Node at  Last:" << endl;
            cout << "b. Insert Node at Start:" << endl;
            cout << "c. Insert before specific Node:" << endl;
            cout << "d. Insert after  specific Node:" << endl;
            cout << "Chose one option:";
            cin >> ch;
            switch (ch)
            {
            case 'a':
            {

                insert_at_last();
                break;
            }
            case 'b':
            {
                insert_at_start();
                break;
            }
            case 'c':
            {
                cout << endl
                     << "Enter Any Regestration Number to insert node before that node:";
                cin >> Reg;
                cout << endl;
                insert_before_specific_node(Reg);
                break;
            }
            case 'd':
            {

                cout << endl
                     << "Enter Any Regestration Number to insert after that node:";
                cin >> Reg;
                cout << endl;
                insert_after_specific_node(Reg);
                break;
            }
            default:
            {
                cout << "Invalid Entry" << endl;
                break;
            }
            }

            break;
        }
        case 2:
        {
            system("cls");
            cout << endl
                 << "Enter Any Regestration Number to search Student data:";
            cin >> Reg;
            cout << endl;
            search(Reg);
            break;
        }
        case 3:
        {
            system("cls");
            cout << endl
                 << "Enter Any Regestration Number to update Student data:";
            cin >> Reg;
            cout << endl;
            update(Reg);
            break;
        }
        case 4:
        {
            system("cls");
            cout << "\t \t DISPLAYING DATA" << endl;
            Display();
            break;
        }
        case 5:
        {
            system("cls");
            cout << endl
                 << "a.Delete First Node:" << endl;
            cout << "b.Delete  any  Node:" << endl;
            cout << "c.Delete  last Node:" << endl;
            char ch;
            cout << "Chose any option:";
            cin >> ch;

            switch (ch)
            {
            case 'a':
            {
                Delete_First();
                break;
            }
            case 'b':
            {
                cout << endl
                     << "Enter Any Regestration Number to delete Student data:";
                cin >> Reg;
                cout << endl;
                Delete_any(Reg);
                break;
            }
            case 'c':
            {
                Delete_Last();
                break;
            }
            }

            break;
        }
        case 6:
        {
            float Cgpa;
            cout << "Enter CGPA to search duplicates:";
            cin >> Cgpa;
            search_Duplicate(Cgpa);
            break;
        }
        case 7:
        {
            break;
        }
        default:
        {
            system("cls");
            cout << "\t\t\t INVALID ENTRY" << endl;
            break;
        }
        }
        cout << endl
             << endl;

    } while (choice < 7);
}

int main()
{
    MAIN();
    return 0;
}
