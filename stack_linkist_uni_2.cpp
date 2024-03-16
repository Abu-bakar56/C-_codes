#include <iostream>
using namespace std;

struct Node
{
	int regNo;
	string name;
	float cgpa;
	Node *next;
};

Node *top = NULL;

void push()
{
	Node *node = new Node;
	cout << "Enter the registration number: ";
	cin >> node->regNo;
	cout << "Enter Name: ";
	cin.ignore();
	getline(cin, node->name);
	cout << "Enter CGPA: ";
	cin >> node->cgpa;
	cout << endl
		 << endl;
	node->next = NULL;

	if (top == NULL)
	{
		top = node;
	}
	else
	{
		node->next = top;
		top = node;
	}
}

void pop()
{
	if (top == NULL)
	{
		cout << "List is empty.";
	}
	else
	{
		top = top->next;
	}
}

void topDisplay()
{
	if (top == NULL)
	{
		cout << "Stack is empty.";
	}
	else
	{
		cout << "Details for Student are given below" << endl;
		cout << "Registeration Number: " << top->regNo << endl;
		cout << "Name: " << top->name << endl;
		cout << "CGPA: " << top->cgpa << endl;
	}
}

void update()
{
	if (top == NULL)
	{
		cout << "Stack is Empty.";
	}
	else
	{
		int reg;
		cout << "Enter the registeration number to be updated: ";
		cin >> reg;
		Node *temp = top;
		while (top != NULL)
		{
			if (temp->regNo == reg)
			{
				cout << "Enter the updated registeration number: ";
				cin >> temp->regNo;
				cout << "Enter updated Name: ";
				cin.ignore();
				getline(cin, temp->name);
				cout << "Enter updated CGPA: ";
				cin >> temp->cgpa;
				cout << endl
					 << endl;
				break;
			}
			else if (temp->next == top)
			{
				cout << "Given Registeration Didn't Match in Database.";
			}
			else
			{
				temp = temp->next;
			}
		}
	}
}

void search()
{
	if (top == NULL)
	{
		cout << "Stack is Empty.";
	}
	else
	{
		int reg;
		cout << "Enter the registeration number to search: ";
		cin >> reg;
		Node *temp = top;
		while (top != NULL)
		{
			if (temp->regNo == reg)
			{
				cout << "Registration Number: " << temp->regNo << endl;
				cout << "Name: " << temp->name << endl;
				cout << "CGPA: " << temp->cgpa << endl;
				cout << endl
					 << endl;
				break;
			}
			else if (temp->next == top)
			{
				cout << "Given Registeration Didn't Match in Database.";
			}
			else
			{
				temp = temp->next;
			}
		}
	}
}

void display()
{
	if (top == NULL)
	{
		cout << "List is empty.";
	}
	else
	{
		int i = 0;
		Node *temp = top;
		while (temp != NULL)
		{
			cout << "Details for Student " << i + 1 << " are given below" << endl;
			cout << "Registration Number: " << temp->regNo << endl;
			cout << "Name: " << temp->name << endl;
			cout << "CGPA: " << temp->cgpa << endl;
			cout << endl
				 << endl;
			temp = temp->next;
			i++;
		}
	}
}

int main()
{
	push();
	push();
	// push();
	display();
	// pop();
	// update();
	// search();
	return 0;
}
