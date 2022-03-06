#ifndef _DOUBLE_LINKED_LIST_
#define _DOUBLE_LINKED_LIST_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct YNODE
{
     int data;
     struct YNODE *pNext;
     struct YNODE *pPrevios;
}yNode;

#endif