#include <iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    char *arr;
};
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
void push(stack *ptr, char data)
{
    if (isfull(ptr))
    {
        cout << "stack is full ";
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
        cout << "stack is empty ";
    }
    else
    {
        int val;
        val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int match(char a, char b)
{
    if (a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int parathnesismatch(char *exp)
{
    stack *s = new stack;
    s->size = 100;
    s->top = -1;
    s->arr = new char;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(s, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isempty(s))
            {
                return 0;
            }
            else
            {
                char popped = pop(s);
                if (!match(popped, exp[i]))
                {
                    return 0;
                }
                
            }
        }
    }
    if (isempty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char exp[] = "(a+b)}" ;
    if (parathnesismatch(exp))
    {
        cout << "parathnesis is matched and balanced";
    }
    else
    {
        cout << "parathnesis is not matched and balanced";
    }
    return 0;
}