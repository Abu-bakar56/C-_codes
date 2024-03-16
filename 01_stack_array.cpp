#include <iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    int *arr;
};
int isempty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(stack *ptr, int data)
{
    if (isfull(ptr))
    {
        cout << "stack is full" << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}
int pop(stack *ptr)
{
    if (isempty(ptr))
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        int val;
        val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
void show(stack *ptr)
{
    if (isempty(ptr))
    {
        cout << "Stack is Empty";
    }
    else
    {
        for (int i = ptr->top; i >= 0; i--)
        {
            cout << "Element: " << ptr->arr[i] << endl;
        }
    }
}
void  topDisplay(stack *ptr)
{
    if (isempty(ptr))
    {
        cout << "Stack is Empty";
        
    }
    else
    {
        cout << "Element at Top: "<<ptr->arr[ptr->top]<<endl;
        
    }
}
int main()
{
    stack *s=new stack;
    s->arr = new int ;
    s->size = 5;
    s->top = -1;
    push(s,1);
    push(s,2);
    push(s,3);
    push(s,4);
    push(s,5);
    show(s);
    pop(s);
    topDisplay(s);
    return 0;
}