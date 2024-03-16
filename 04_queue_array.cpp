#include <iostream>
using namespace std;
struct queue
{
    int *arr;
    int size;
    int f;
    int r;
};
int isempty(queue *ptr)
{
    if (ptr->r == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(queue *ptr)
{
    if (ptr->r == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(queue *ptr, int data)
{
    if (isfull(ptr))
    {
        cout << "queue is full" << endl;
    }
    else
    {
         if (isempty(ptr))
        {
            ptr->f = 0; 
        }
        ptr->r++;
        ptr->arr[ptr->r] = data;
    }
}
int dequeue(queue *ptr)
{
    if (isempty(ptr))
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        
        int val;
        val = ptr->arr[ptr->f];
        ptr->f++;
      
        return val;
    }
}
void show(queue *ptr)
{
    if (isempty(ptr))
    {
        cout << "queue is Empty";
    }
    else
    {
        for (int i = ptr->r; i >= ptr->f; i--)
        {
            cout << "Element: " << ptr->arr[i] << endl;
        }
    }
}

int main()
{
    queue *q = new queue;
    q->size = 5;
    q->arr=new int;
    q->f = -1;
    q->r = -1;
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    show(q);
    dequeue(q);
    show(q);
    return 0;
}