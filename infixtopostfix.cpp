#include <iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    char *arr;
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

int stacktop(stack *ptr)
{
    return ptr->arr[ptr->top];
}
void push(stack *ptr, char data)
{
    if (isfull(ptr))
    {
        cout << "stack is full";
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}
char pop(stack *ptr)
{
    if (isempty(ptr))
    {
        cout << "stack is empty ";
        return -1;
    }
    else
    {
        char val;
        val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int isoperater(char ch)
{
    if (ch == '+' || ch == '/' || ch == '*' || ch == '-' || ch == '^')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int peracedance(char ch)
{
    if (ch == '^')
    {
        return 4;
    }
    else if (ch == '/' || ch == '*')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
char *infix_into_postfix(char *infix)
{
    stack *s = new stack;
    s->size = 100;
    s->top = -1;
    s->arr = new char[s->size];
    char *postfix = new char[s->size];

    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (!isoperater(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else if (peracedance(infix[i]) > peracedance(stacktop(s)))
        {
            push(s, infix[i]);
            i++;
        }
        else
        {
            postfix[j] = pop(s);
            j++;
        }
    }
    while (!isempty(s))
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char *infix = " (A+B^D)/(E-F)+G";
    cout << "infix to postfix =" << endl;
    cout << infix_into_postfix(infix);
    return 0;
}