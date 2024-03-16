#include <iostream>
using namespace std;

const int size = 5;
int top = -1;
int* arr = new int[size];

int isFull(){
	if(top==size-1){
		return 1;
	}
	else{
		return 0;
	}
}

int isEmpty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

void push(int num) {
    if (isFull()) {
        cout << "Stack is Full, Element can't be pushed";
    } else {
        arr[++top] = num;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack is Empty";
    } else {
        cout << "Popped: " << arr[top] << endl;
        top--;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is Empty";
    } else {
        for (int i = top; i >= 0; i--) {
            cout << "Element: " << arr[i] << endl;
        }
    }
}

void topDisplay() {
    if (isEmpty()) {
        cout << "Stack is Empty";
    } else {
        cout << "Element at Top: " << arr[top] << endl;
    }
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    display();
    pop();
    topDisplay();
    return 0;
}
