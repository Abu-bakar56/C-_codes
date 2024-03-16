#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

struct Employee
{
    int id;
    string name;
    double salary;
    string contactno;
    Employee *next;
    Employee *prev;
};
void registration();
void login();
void addEmployee(int id, const string &name, double salary,string contactno);
void deleteEmployee(Employee *employeeToDelete);
void displayEmployees();
void displayemployeeid(int id);
void selectMenu();
void labelMenu();
Employee *head = NULL;
Employee *tail = NULL;

void registeration()
{
    system("CLS");
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl
         << "|                                              EMPLOYEE MANAGEMENT SYSTEM                                               |" << endl
         << "----------------------------------------------------------------------------------------------------------------------" << endl;
    string name, checkname, pass;
    bool samename;
    ifstream check_name("username.txt");
    do
    {
        cout << "Enter a username : ";
        getline(cin, name);
        samename = false;
        check_name.clear();
        check_name.seekg(0, ios::beg);
        while (getline(check_name, checkname))
        {
            if (checkname == name)
            {
                samename = true;
                cout << "This username is already taken." << endl;
                Sleep(1000);
                system("CLS");
                break;
            }
        }
    } while (samename);
    check_name.close();

    ofstream savename("username.txt", ios::app);
    savename << name << endl;
    savename.close();

    system("CLS");
    cout << "----------------------------------------------------------------------------------------------------------------------" << endl
         << "|                                              EMPLOYEE MANAGEMENT SYSTEM                                               |" << endl
         << "----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Create a password : ";
    getline(cin, pass);

    ofstream savepass("password.txt", ios::app);
    savepass << pass << endl;
    savepass.close();

    labelMenu();
}

void login()
{
    string name, checkname;
    bool samename;
    ifstream check_name("username.txt");
    do
    {
        system("CLS");
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl
             << "|                                              EMPLOYEE MANAGEMENT SYSTEM                                               |" << endl
             << "----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter a username : ";
        getline(cin, name);
        samename = false;
        check_name.clear();
        check_name.seekg(0, ios::beg);
        while (getline(check_name, checkname))
        {
            if (checkname == name)
            {
                samename = true;
                break;
            }
        }

        if (!samename)
        {
            system("CLS");
            cout << "----------------------------------------------------------------------------------------------------------------------" << endl
                 << "|                                              EMPLOYEE MANAGEMENT SYSTEM                                               |" << endl
                 << "----------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Wrong Username." << endl;
            Sleep(1000);
        }
    } while (!samename);
    check_name.close();

    string pass, checkpass;
    bool samepass;
    ifstream check_pass("password.txt");
    do
    {
        system("CLS");
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl
             << "|                                              EMPLOYEE MANAGEMENT SYSTEM                                               |" << endl
             << "----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Enter a password : ";
        getline(cin, pass);
        samepass = false;
        check_pass.clear();
        check_pass.seekg(0, ios::beg);
        while (getline(check_pass, checkpass))
        {
            if (checkpass == pass)
            {
                samepass = true;
                break;
            }
        }

        if (!samepass)
        {
            cout << "Wrong password." << endl;
            Sleep(1000);
            system("CLS");
        }
    } while (!samepass);
    check_pass.close();
    labelMenu();
}

void addemployee(int id,  string &name, double salary,string contactno)
{
    Employee *newnode = new Employee;
    newnode->id = id;
    newnode->name = name;
    newnode->salary = salary;
    newnode->contactno=contactno;
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

Employee *delemployee()
{
    int da;
    cout << "Enter the ID of the employee whose data you want to delete: ";
    cin >> da;

    Employee *temp = head;

    while (temp != NULL)
    {
        if (temp->id == da)
        {
            if (temp == head)
            {
                head = temp->next;
                if (head != NULL)
                    head->prev = NULL;
            }
            else if (temp == tail)
            {
                tail = temp->prev;
                if (tail != NULL)
                    tail->next = NULL;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            cout << "Data of employee you deleted:" << endl;
            cout << "ID: " << temp->id << "\tName: " << temp->name << "\tSalary: " << temp->salary << endl;
            delete temp;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }

    return temp;
}

void displayemployee()
{
    Employee *temp = head;

    cout << "LIST OF EMPLOYEES IN THE COMPANY" << endl;

    while (temp)
    {
        cout << "ID: " << temp->id << "\tName: " << temp->name << "\tSalary: " << temp->salary<< "\tContact number: " << temp->contactno << endl;
        temp = temp->next;
    }
}

void displayemployeeid()
{
    int da;
    cout << "Enter the ID of the employee whose data you want to search: ";
    cin >> da;

    Employee *temp = head;

    cout << "DATA OF THIS EMPLOYEE:" << endl;

    while (temp != NULL)
    {
        if (temp->id == da)
        {
           cout << "ID: " << temp->id << "\tName: " << temp->name << "\tSalary: " << temp->salary<< "\tContact number: " << temp->contactno << endl;
            break;
        }
        temp = temp->next;
        }
}

void selectMenu()
{
    while (true)
    {
        system("CLS");
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl
             << "|                                             EMPLOYEE MANAGEMENT SYSTEM                                              |" << endl
             << "----------------------------------------------------------------------------------------------------------------------" << endl;
        int ch;
        cout << "1. Registration." << endl
             << "2. Login." << endl
             << "3. Exit." << endl
             << "Enter your choice: ";

        switch (ch = getch())
        {
        case 49:
            registeration();
            break;
        case 50:
            login();
            break;
        case 51:
            exit(0);
        default:
            break;
        }
    }
}

void labelMenu()
{
    while (true)
    {
        system("CLS");
        cout << "----------------------------------------------------------------------------------------------------------------------" << endl
             << "|                                              EMPLOYEE MANAGEMENT SYSTEM                                               |" << endl
             << "----------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "**Welcome to Home page**" << endl;
        cout << "1. For Add New Employee " << endl;
        cout << "2. For Delete Employee " << endl;
        cout << "3. For Show All Employees Details " << endl;
        cout << "4. For Show Specific Employees Details " << endl;
        cout << "5. Log Out" << endl;

        int choice;
        cout << "Enter your choice: ";
        choice = getch();

        switch (choice)
        {
        case 49:
        {
            int id;
            string name;
            double salary;
            string contactno;
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Salary: ";
            cin >> salary;
            cout << "Enter Contact number: ";
            cin>>contactno;
            addemployee(id, name, salary,contactno);
        }
        break;
        case 50:
            delemployee();
            break;
        case 51:
            displayemployee();
            getch();
            break;
        case 52:
            displayemployeeid();
            getch();
            break;
        case 53:
            selectMenu();
            break;
        default:
            cout << "Wrong input" << endl;
            break;
        }
    }
}

int main()
{
    system("COLOR 0A");
    selectMenu();
    return 0;
}
