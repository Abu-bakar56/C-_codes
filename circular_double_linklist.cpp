
#include<iostream>
using namespace std;

struct Node {
    int regNo;
    string name;
    float cgpa;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;

Node* createNode() {
    Node* node = new Node;
    cout << "Enter the registration number: ";
    cin >> node->regNo;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, node->name);
    cout << "Enter CGPA: ";
    cin >> node->cgpa;
    cout << endl << endl;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void insertAtLast() {
    Node* node = createNode();

    if (head == NULL) {
        head = tail = node;
        tail->next=head;
        head->prev=tail;
    } else {
        node->prev = tail;
        tail->next = node;
        tail = node;
        tail->next = head;  
        head->prev = tail;  
    }
}

void insertAtHead() {
    Node* node = createNode();

    if (head == NULL) {
        head = tail = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
        head->prev = tail;  
        tail->next = head;  
    }
}

void insertBeforeSpecific() {
    int reg;
	cout << "\nEnter the Specific Node's Registration: ";
    cin >> reg;
    Node* node = createNode();
    if (head == NULL) {
        cout << "List is Empty, node can't be inserted";
    } else {
        if (head->regNo == reg) {
            node->next = head;
            head->prev = node;
            head = node;
            head->prev = tail;  
            tail->next = head;   
        } else if (tail->regNo == reg) {
            node->next = tail;
            node->prev = tail->prev;
            tail->prev = node;
            node->prev->next = node;
        } else {
            Node* temp = head->next;
            while (temp != NULL) {
                if (temp->regNo == reg) {
                    temp = temp->prev;
                    node->next = temp->next;
                    node->prev = temp;
                    temp->next = node;
                    node->next->prev = node;
                    break;
                } else if (temp->next == head) {
                    cout << "Registration Didn't match in list, Node can't be inserted" << endl;
                    break;
                } else {
                    temp = temp->next;
                }
            }
        }
    }
}

void insertAfterSpecific() {
    int reg;
	cout << "\nEnter the Specific Node's Registration: ";
    cin >> reg;
    Node* node = createNode();
    if (head == NULL) {
        cout << "List is Empty, node can't be inserted";
    } else {
        if (tail->regNo == reg) {
            node->next = head;
            node->prev = tail;
            tail->next = node;
            tail = node;
            head->prev = tail;
        } else {
            Node* temp = head;
            while (temp != NULL) {
                if (temp->regNo == reg) {
                    node->next = temp->next;
                    node->prev = temp;
                    temp->next = node;
                    node->next->prev = node;
                    break;
                } else if (temp->next == head) {
                    cout << "Registration Didn't match in list, Node can't be inserted" << endl;
                    break;
                } else {
                    temp = temp->next;
                }
            }
        }
    }
}

void deleteHead() {
    if (head == NULL) {
        cout << "List is empty";
    } else {
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = tail;  
            tail->next = head;  
        }
    }
}

void deleteLast() {
    if (tail == NULL) {
        cout << "List is empty";
    } else {
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = head;  
            head->prev = tail;  
        }
    }
}

void deleteSpecificNode() {
    int reg;
    cout << "\nEnter the Specific Node's Registration: ";
    cin >> reg;
    if (head == NULL) {
        cout << "List is Empty, node can't be deleted";
    } else {
        if (head->regNo == reg) {
            head = head->next;
            head->prev = tail;  
            tail->next = head;  
        } else if (tail->regNo == reg) {
            tail = tail->prev;
            tail->next = head;  
            head->prev = tail;  
        } else {
            Node* temp = head->next;
            while (temp != NULL) {
                if (temp->regNo == reg) {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    break;
                } else if (temp->next == head) {
                    cout << "Registration Didn't match in list, Node can't be deleted" << endl;
                    break;
                } else {
                    temp = temp->next;
                }
            }
        }
    }
}

void displayFromStart() {
    if (head == NULL) {
        cout << "List is Empty";
    } else {
        Node* temp = head;
        int i = 1;
        do {
            cout << "Details for Student " << i << " are given below:" << endl;
            cout << "Registeration Number: " << temp->regNo << endl;
            cout << "Name: " << temp->name << endl;
            cout << "CGPA: " << temp->cgpa << endl << endl;
            i++;
            temp = temp->next;
        } while (temp != head);
    }
}

void displayFromLast() {
    if (head == NULL) {
        cout << "List is Empty";
    } else {
        Node* temp = tail;
        int i = 1;
        do {
            cout << "Details for Student " << i << " are given below:" << endl;
            cout << "Registeration Number: " << temp->regNo << endl;
            cout << "Name: " << temp->name << endl;
            cout << "CGPA: " << temp->cgpa << endl << endl;
            i++;
            temp = temp->prev;
        } while (temp != tail);
    }
}

int main() {
    insertAtLast();
    insertAtHead();
    insertBeforeSpecific();
    insertAfterSpecific();
    displayFromStart();
    deleteLast();
    deleteSpecificNode();
    displayFromLast();
   return 0;
}