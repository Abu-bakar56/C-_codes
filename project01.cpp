#include <iostream>
#include <conio.h>
#include<windows.h>
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
    node *ptr = head_SE;
    cout << "Student details:" << endl;
    while (ptr != nullptr)
    {
        cout << "Name: " << ptr->name << endl;
        cout << "Registration: " << ptr->reg << endl;
        cout << "CGPA: " << ptr->cgpa << endl;
        ptr = ptr->next;
    }
}
void show1()
{
    node *ptr = head_CS;
    cout << "Student details:" << endl;
    while (ptr != nullptr)
    {
        cout << "Name: " << ptr->name << endl;
        cout << "Registration: " << ptr->reg << endl;
        cout << "CGPA: " << ptr->cgpa << endl;
        ptr = ptr->next;
    }
}
void show2()
{
    node *ptr = head_AI;
    cout << "Student details:" << endl;
    while (ptr != nullptr)
    {
        cout << "Name: " << ptr->name << endl;
        cout << "Registration: " << ptr->reg << endl;
        cout << "CGPA: " << ptr->cgpa << endl;
        ptr = ptr->next;
    }
}
void show3()
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
void for_SE()
{
	char ch;
	int val;
	system("cls");
    cout << "information for SOFTWARE ENGINERRING STUDENT" << endl;
    cout<<"enter 1. to input information"<<endl;
    cout<<"enter 2. to display information"<<endl;
    cin>>val;
	cout<<endl;
   
	 if(val==1){
	do{
		system("cls");
    insert_node_SE();
	system("cls");	
    cout<<"enter again y. for input information"<<endl;
    cout<<"enter  n for not input information"<<endl;
    cin>>ch;
	}
	while(ch=='y'||ch=='Y');
	system("cls");
	cout<<"enter 2. to display information"<<endl;
    cin>>val;
    if(val==2){
    	system("cls");
		 cout << "information OF SOFTWARE ENGINERRING STUDENT" << endl;
		show();
	}
	
}
	
	
	if(val==2){
		system("cls");
		 cout << "information OF SOFTWARE ENGINERRING STUDENT" << endl;
		show();
	}
    
   
}
    
void for_CS()
{
   char ch;
	int val;
	system("cls");
    cout << "information for COMPUTER SCIENCE  STUDENT" << endl;
    cout<<"enter 1. to input information"<<endl;
    cout<<"enter 2. to display information"<<endl;
    cin>>val;
	cout<<endl;
   
	 if(val==1){
	do{
		system("cls");
    insert_node_CS();
	system("cls");	
    cout<<"enter again y. for input information"<<endl;
    cout<<"enter  n for not input information"<<endl;
    cin>>ch;
	}
	while(ch=='y'||ch=='Y');
	system("cls");
	cout<<"enter 2. to display information"<<endl;
    cin>>val;
    if(val==2){
    	system("cls");
		 cout << "information OF COMPUTER SCIENCE STUDENT" << endl;
		show1();
	}
	
}
	
	
	if(val==2){
		system("cls");
		 cout << "information OF COMPUTER SCIENCE STUDENT" << endl;
		show1();
	}
    
}
void for_AI()
{
   char ch;
	int val;
	system("cls");
    cout << "information for ARTIFICAL INTELLIEGANCE STUDENT" << endl;
    cout<<"enter 1. to input information"<<endl;
    cout<<"enter 2. to display information"<<endl;
    cin>>val;
	cout<<endl;
   
	 if(val==1){
	do{
		system("cls");
    insert_node_AI();
	system("cls");	
    cout<<"enter again y. for input information"<<endl;
    cout<<"enter  n for not input information"<<endl;
    cin>>ch;
	}
	while(ch=='y'||ch=='Y');
	system("cls");
	cout<<"enter 2. to display information"<<endl;
    cin>>val;
    if(val==2){
    	system("cls");
		 cout << "information OF  ARTIFICAL INTELLIEGANCE STUDENT" << endl;
		show2();
	}
	
}
	
	
	if(val==2){
		system("cls");
		 cout << "information OF  ARTIFICAL INTELLIEGANCE STUDENT" << endl;
		show2();
	}
    
}
void for_AF()
{
   char ch;
	int val;
	system("cls");
    cout << "information for AF STUDENT " << endl;
    cout<<"enter 1. to input information"<<endl;
    cout<<"enter 2. to display information"<<endl;
    cin>>val;
	cout<<endl;
   
	 if(val==1){
	do{
		system("cls");
    insert_node_AF();
	system("cls");	
    cout<<"enter again y. for input information"<<endl;
    cout<<"enter  n for not input information"<<endl;
    cin>>ch;
	}
	while(ch=='y'||ch=='Y');
	system("cls");
	cout<<"enter 2. to display information"<<endl;
    cin>>val;
    if(val==2){
    	system("cls");
		 cout << "information OF AF STUDENT" << endl;
		show3();
	}
	
}
	
	
	if(val==2){
		
		system("cls");
		 cout << "information OF AF STUDENT" << endl;
		show3();
	}
    
}

int main()
{
    cout << "**EXAMINATION OFFICE**" << endl;
    cout << "1. FOR SOFTWARE STUDENT " << endl;
    cout << "2. FOR COMPUTER SCIENCE STUDENT" << endl;
    cout << "3. FOR ARTIFICAL INTELLIGENCE STUDENT" << endl;
    cout << "4. FOR AF STUDENT " << endl;

    int choice;
    switch (choice = getch())
    {
    case 49:
        for_SE();
        break;
    case 50:
        for_CS();
        break;
    case 51:
        for_AI();
        break;
    case 52:
        for_AF();
        break;
    default:
        cout << "Wrong input" << endl;
        break;
    }

    return 0;
}