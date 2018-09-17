#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack * pNext;
} STACK;

STACK * makeNode(int d)
{
    STACK * pNew = (STACK *)malloc(sizeof(STACK));

    if(pNew)
    {
        pNew->data = d;
        pNew->pNext = NULL;
    }

    return pNew;
}

int isStackEmpty(STACK * pTop)
{
    if(pTop)
    {
        return 0;
    }

    return 1;
}

int push(STACK ** pTop, int dtm)
{
    int success = 0;
    STACK * pNew = makeNode(dtm);

    if(pNew)
    {
        pNew->pNext = *pTop;
        *pTop = pNew;
        success = 1;
    }

    return success;
}

void pop(STACK ** pTop)
{
    STACK * pCur = *pTop;
    if(!isStackEmpty(*pTop))
    {
        *pTop = (*pTop)->pNext;
        free(pCur);
    }
}

int top(STACK * pTop)
{
    if(!isStackEmpty(pTop))
    {
        return pTop->data;
    }
}

void main(void)
{
    STACK * pTop = NULL;

    push(&pTop, 2);
    push(&pTop, 4);
    push(&pTop, 8);
    push(&pTop, 9);

    printf("%d\n", top(pTop));
    pop(&pTop);
    printf("%d\n", top(pTop));
    pop(&pTop);
    printf("%d\n", top(pTop));
    pop(&pTop);
    printf("%d\n", top(pTop));
    pop(&pTop);

    printf("%d\n", top(pTop));
    pop(&pTop);
}
