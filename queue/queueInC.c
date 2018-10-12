#include <stdio.h>
#include <stdlib.h>

/*
    Queue : First In First Out
    Top pointer and bottom pointer
*/

typedef struct node
{
    int data;
    struct node * pNext;
} NODE;

typedef struct queue
{
    NODE * pHead;
    NODE * pTail;
}QUEUE;

NODE * makeNode(int data)
{
    NODE * pMem = (NODE *)malloc(sizeof(NODE));

    if(pMem)
    {
        pMem->data = data;
        pMem->pNext = NULL;
    }

    return pMem;
}

/*
    Gets the element at the front of the queue without removing it.
*/
int peek(QUEUE * pQueue)
{
    if(pQueue)
    {
        if(pQueue->pHead)
        {
            return pQueue->pHead->data;
        }
    }
}

/*
    Checks if the queue is empty.
*/
int isEmpty(QUEUE * pQueue)
{
    int success = 1;
    
    if(pQueue)
    {
        if((pQueue->pHead == pQueue->pTail == NULL))
        {
            success = 0;
        }
    }

    return success;
}

/*
    Add a node into the queue : add at the head
*/
int enqueue(QUEUE * pQueue, int data)
{
    int success = 0;
    NODE * pNode = makeNode(data);

    if((pNode != NULL))
    {
        if(pQueue->pHead != NULL)
        {
            pQueue->pHead->pNext = pNode;
        }

        pQueue->pHead = pNode;

        if(pQueue->pTail == NULL)
        {
            pQueue->pTail = pNode;
        }

        success = 1;
    }

    return success;
}

/*
    Remove a node from the queue : removal from the Tail end
*/
int dequeue(QUEUE * pQueue)
{
    int success = 0;

    if(pQueue)
    {
        if(pQueue->pTail)
        {
            NODE * pLast = pQueue->pTail;
            pQueue->pTail = pLast->pNext;
            free(pLast);
            success = 1;
        }
    }

    return success;
}

/*
    Display all the items in the queue
*/

void displayQueue(QUEUE * pQueue)
{
    NODE * pCur = pQueue->pTail;

    if(pCur)
    {
        while(pCur != NULL)
        {
            printf("data %d \n", pCur->data);
            pCur = pCur->pNext;
        }
    }
    else
    {
        printf("No item in Queue\n");
    }
}

void main(void)
{
    QUEUE pQueue = {NULL, NULL};

    printf("en %d\n", enqueue(&pQueue, 5));
    displayQueue(&pQueue);

    printf("en %d\n", enqueue(&pQueue, 13));
    printf("en %d\n", enqueue(&pQueue, 25));
    displayQueue(&pQueue);

    printf("en %d\n", enqueue(&pQueue, 143));
    displayQueue(&pQueue);

    printf("dq %d\n", dequeue(&pQueue));
    displayQueue(&pQueue);

    printf("dq %d\n", dequeue(&pQueue));
    printf("dq %d\n", dequeue(&pQueue));
    displayQueue(&pQueue);

    printf("dq %d\n", dequeue(&pQueue));
    printf("dq %d\n", dequeue(&pQueue));
    displayQueue(&pQueue);

}
