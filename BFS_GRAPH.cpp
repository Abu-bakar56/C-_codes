#include <iostream>
#include <cstdlib>
using namespace std;

struct Queue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(Queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(Queue *q, int val)
{
    if (isFull(q))
    {
        cout << "This Queue is full" << endl;
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        // cout << "Enqueued element: " << val << endl;
    }
}

int dequeue(Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        cout << "This Queue is empty" << endl;
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    // Initializing Queue (Array Implementation)
    Queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = new int[q.size];

    // BFS Implementation
    int node;
    int i = 1;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};
    cout << i;
    visited[i] = 1;
    enqueue(&q, i); // Enqueue i for exploration
    while (!isEmpty(&q))
    {
        int node = dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                cout << j;
                visited[j] = 1;
                enqueue(&q, j);
            }
        }
    }

    delete[] q.arr; // Deallocate memory
    return 0;
}
