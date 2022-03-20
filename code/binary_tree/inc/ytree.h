#ifndef _Y_TREE_H_
#define _Y_TREE_H_
#include "types.h"
typedef struct __ytnode__ YTNODE;
struct __ytnode__
{
    YTNODE  *child[2];
    YTNODE  *parent;
    UInt8   red;
};

typedef struct 
{
    YTNODE  root;
    SInt32  (*compare)(const void *, const void *);
    const void *(*keyof)(const YTNODE *);
    UInt32  count;
}YTREE;

/* Method implement */
void ytInit(YTREE *, SInt32 (*compare)(const void *, const void *), const void *(*keyof)(YTNODE *));
void ytInsert(YTREE *, YTNODE *);

#endif