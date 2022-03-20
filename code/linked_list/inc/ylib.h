#ifndef _YLIB_H_
#define _YLIB_H_
#include "types.h"

typedef struct __ylnode__ YLNODE;
struct __ylnode__
{
    YLNODE      *next;
    YLNODE      *previous;
    /* data */
};

typedef struct
{
    YLNODE  node;
    UInt32  count;
    /* pthread_mutext_t sem_lock */
    /* data */
}YLIST;

void ylInit(YLIST *pList);
void ylPushTail(YLIST *pList, YLNODE *pNode);
void ylPushHead(YLIST *pList, YLNODE *pNode);
void showAllList(YLIST *pList);
YLNODE *ylNext(YLNODE *pNode);
YLNODE *ylFirst(YLIST *pList);
void ylDeleteNode(YLIST *pList, YLNODE *pNode);
void ylInsertNodeBefor(YLIST *pList, YLNODE *pNode, YLNODE *pBefor);
UInt32 ylCount(YLIST *pList);


#endif