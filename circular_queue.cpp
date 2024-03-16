#include <iostream>
using namespace std;
struct queue
{
    int size;
    int f;
    int b;
    int *arr;
};
int isempty(queue *q)
{
    if (q->f == q->b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(queue *q)
{
    if (q->f == (q->b + 1) % q->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(queue *q, int val)
{
    if (isfull(q))
    {
        cout << "queue is full";
    }
    else
    {
        q->b = (q->b + 1) % q->size;
        q->arr[(q->b + 1) % q->size] = val;
    }
}
int dequeue(queue *q)
{
    if (isempty(q))
    {
        cout << "queue is empty";
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        int data;
        data = q->arr[(q->f + 1) % q->size];
        return data;
    }
}
int main()
{
    queue q;
    q.size = 4;
    q.f = 0;
    q.b = 0;
    q.arr = new int;

    enqueue(&q, 89);
    enqueue(&q, 55);
    enqueue(&q, 11);

    cout << "dequeue element is :"
         << "  " << dequeue(&q);

    enqueue(&q, 33);
    return 0;
}