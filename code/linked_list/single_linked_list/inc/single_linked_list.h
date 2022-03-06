#ifndef _SINGLE_LINKED_LIST_
#define _SINGLE_LINKED_LIST_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct YNODE
{
     unsigned int data;
     struct YNODE *pNext;
}yNode;

typedef struct YLIST
{
     yNode *head ;
     yNode *tail ;
}yList;



#endif