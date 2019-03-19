#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

typedef struct Queue {
    unsigned int length;
    unsigned int capacity;
    int *storage;
} Queue;

/*
    Creates a queue by allocating the appropriate amount of memory for an
    instance of the Queue struct, and initializes all of the fields of the
    struct. Also allocates memory for the queue's storage structure. 
*/
Queue *createQueue(unsigned capacity)
{
    Queue *new_queue = malloc(sizeof(Queue));
    new_queue->storage = malloc(sizeof(int)*capacity);
    new_queue->length = 0;
    new_queue->capacity = capacity;
    return new_queue;
}

/*
    Adds the given item to the end of the queue. If the queue does
    not have room, expand the queue's available storage so that it 
    does have room for the additional item.
*/
void enqueue(Queue *q, int item)
{
    if(q->length == q->capacity)
    {
        int old = q->capacity;
        q->capacity *= 2;
        q->storage = realloc(q->storage, q->capacity);
    }
    q->storage[q->length] = item;
    q->length++;
}

/*
    Removes the item at the front of the queue and returns it. 
    If the queue is empty, this function should return -1.
*/
int dequeue(Queue *q)
{
    if(!q->length)
    {
        return -1;
    }
    int item = q->storage[0];
    for(int index=1; index < q->length; index++)
    {
        q->storage[index-1] = q->storage[index];
    }
    q->length--;
    return item;
}

/*
    Frees the memory used to hold the queue instance and its
    associated storage. 
*/
void destroyQueue(Queue *q)
{
    free(q->storage);
    free(q);
}


#ifndef TESTING
int main(void)
{
    Queue *q = createQueue(4);

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);

    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));

    destroyQueue(q);

    return 0;
}
#endif