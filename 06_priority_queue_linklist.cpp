#include <iostream>
using namespace std;

struct Node {
    int data;
    int priority;
    Node* next;
};

int count=0;
int size=5;
Node* f = NULL;


int isFull(){
	if(count==size){
		return 1;
	}
	else{
		return 0;
	}
}

int isEmpty(){
	if(count==0){
		return 1;
	}
	else{
		return 0;
	}
}

void enqueue() {
    if (isFull()) {
        cout << "Queue is Full, Node can't be Queued";
    } else {
        Node* node = new Node;
        cout << "Enter the data ";
        cin >> node->data;
         cout << "Enter the priority ";
        cin >> node->priority;
        node->next = NULL;

        if (f == NULL || node->priority > f->priority) {
            node->next = f;
            f = node;
        } else {
            Node* temp = f;
            while (temp->next != NULL && temp->next->priority > node->priority) {
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
        }
        count++;
    }
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty.";
    } else {
        f=f->next;
        count--;
    }
}




void display() {
    if (isEmpty()) {
        cout << "queue is empty.";
    } else {
        int i = 0;
        Node* temp = f;
        while (temp != NULL) {
            cout << "Details are this  " << endl;
            cout << "data is this  " << temp->data << endl;
            cout << "priority " << temp->priority << endl;
           
            temp = temp->next;
            i++;
        }
    }
}

int main() {
    enqueue();
    enqueue();
    enqueue();
    display();
    return 0;
}