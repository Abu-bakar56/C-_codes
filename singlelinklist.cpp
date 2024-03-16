#include <iostream>
using namespace std;
struct node
{
	int reg;
	string name;
	float gpa;
	node *next;
};
node *head = NULL;
void insertatlast()
{
	node *newnode = new node;
	cout << "enter data of new node" << endl;
	cout << "enter the registration" << endl;
	cin >> newnode->reg;
	cout << "enter the name " << endl;
	cin.ignore();
	getline(cin, newnode->name);
	cout << "enter the gpa " << endl;
	cin >> newnode->gpa;
	newnode->next = NULL;
	if (head == NULL)
	{
		head = newnode;
	}
	else if (head->next == NULL)
	{
		head->next = newnode;
	}
	else
	{
		node *temp = head;
		while (temp != NULL)
		{
			if (temp->next == NULL)
			{
				temp->next = newnode;
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
}
void showlinklist(node *ptr)
{
	int i = 1;

	while (ptr != NULL)
	{
		cout << "details of student is : "
			 << "  " << i << endl;
		cout << "registration number of student is " << endl;
		cout << ptr->reg << endl;
		cout << "name of student is " << endl;
		cout << ptr->name << endl;
		cout << "GPA of student is " << endl;
		cout << ptr->gpa << endl;
		ptr = ptr->next;
		i++;
	}
}
void search(int reg)
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
			if (ptr->reg == reg)
			{
				cout << "registration is match"
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
void update(int reg)
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
			if (ptr->reg == reg)
			{
				cout << "registration is match"
					 << "  " << endl;
				cout << "change and enter the registration" << endl;
				cin >> ptr->reg;
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
void delete_atstart()
{
	if (head == nullptr)
	{
		cout << "list is empty" << endl;
	}
	else
	{
		head = head->next;
	}
}

void delete_atlast()
{
	if (head == nullptr)
	{
		cout << "list is empty" << endl;
	}
	else
	{
		node *temp = head;
		while (temp != nullptr)
		{
			if (temp->next->next == nullptr)
			{
				temp->next = temp->next->next;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
}
void delete_atanynode(int reg)
{
	if (head == nullptr)
	{
		cout << "list is empty";
	}
	else
	{
		node *temp = head;
		while (temp != nullptr)
		{
			if (temp->reg == reg)
			{
				temp->next = temp->next->next;
			}
			else if (temp->next == nullptr)
			{
				cout << "registration is not find" << endl;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
}
int main()
{

	insertatlast();
	insertatlast();
	insertatlast();
	// delete_atstart();
	// cout<<"before update"<<endl;
	// showlinklist(head);
	// search(14);
	// update(14);
	delete_atanynode(14);
	// cout<<"after  update"<<endl;
	showlinklist(head);
	// delete_atlast();

 return 0;
}