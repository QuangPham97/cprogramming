#include "ylib.h"

/* Impliment code */
void ylInit(YLIST *pList)
{
    /* assigned next or previous NULL */
    pList->node.next        = NULL;
    pList->node.previous    = NULL;
    pList->count            = 0;
}

void ylPushTail(YLIST *pList, YLNODE *pNode)
{
    /* If List is empty */
    if(pList->node.next == NULL)
    {
        /* pList--->pNode--->NULL and increasing count to 1*/
        pList->node.next        = pNode;
        pList->node.previous    = pNode;
        pNode->next             = NULL;
        pNode->previous         = NULL;
        pList->count            = 1;
    }else{
        /* If List is Not empty */
        if(pNode == pList->node.next) /* If pNode dupplicate pList->node.next then panic*/
        {
            exit(-1);
        }
        pNode->next = NULL;
        pNode->previous = pList->node.previous; /* assigned link previous to node previous. Example pNode_insert->previous->pNode_old */
        pList->node.previous->next = pNode;
        /* update pList->node.previous = pNode It means update pList shift to pNode */
        pList->node.previous = pNode;
        pList->count++;
    }
}
void ylPushHead(YLIST *pList, YLNODE *pNode)
{
    /* if List is empty */
    if(pList->node.next == NULL)
    {
        /* pList--->pNode--->NULL and increasing count to 1*/
        pList->node.next        = pNode;
        pList->node.previous    = pNode;
        pNode->next             = NULL;
        pNode->previous         = NULL;
        pList->count            = 1;
    }else{
        pNode->next = pList->node.next;
        pNode->previous = NULL;
        pList->node.next->previous = pNode;
        pList->node.next = pNode;
        pList->count++;
    }
}

YLNODE *ylNext(YLNODE *pNode)
{
    return(pNode->next);
}

YLNODE *ylFirst(YLIST *pList)
{
    return(pList->node.next);
}
void ylDeleteNode(YLIST *pList, YLNODE *pNode)
{
    if(pList->count == 0) /* List is empty */
        return;
    if(pNode->next == NULL) /* pList point to last node */
    {
        pList->node.previous = pNode->previous;
    }else{
        pNode->next->previous = pNode->previous;
    }
    
    if(pNode->previous ==  NULL)
    {
        pList->node.next = pNode->next;
    }else{
        pNode->previous->next = pNode->next;
    }
    pList->count--;
}

void ylInsertNodeBefor(YLIST *pList, YLNODE *pNode, YLNODE *pBefor)
{
    if(pBefor->next == NULL)
    {
        ylPushTail(pList, pBefor);   
    }else if(pBefor->previous == NULL)
    {
        ylPushHead(pList, pBefor);
    }else{
        pNode->previous = pBefor->previous;
        pNode->next = pBefor;
        pBefor->previous->next = pNode;
        pBefor->previous = pNode;
        pList->count++;
    }   
}
UInt32 ylCount(YLIST *pList)
{
    return(pList->count);
}