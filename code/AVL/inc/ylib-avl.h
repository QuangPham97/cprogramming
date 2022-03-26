#ifndef _YLIB_BTS_H_H
#define _YLIB_BTS_H_H
#include "types.h"
#include <signal.h>
#define COMPARE_ERROR                   2
#define FISRT_IS_EQUAL_TO_SECOND        0
#define FISRT_IS_GREATER_THAN_SECOND    1
#define FISRT_IS_LESS_THAN_SECOND       -1 
#define T_PREORDER                     0
#define T_INORDER                       1
#define T_POSTORDER                     2
#define INVALID_DATA                    0xfffff
#define MAX_TREE_ELEMENT                100

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

typedef struct _bst_search_node_t
{
    YTNODE node_anchor;
    UInt32  data;
    UInt8 *context;
}bst_search_node_t;

typedef struct _search_tree_t
{
    YTREE st_search_tree;
}search_tree_t;
typedef SInt32 (*compare_func)(const void *, const void*);
/* ==================== Define Method implement ==========================*/
void ytInit(
    YTREE *, 
    SInt32 (*compare)(const void *, const void *), 
    const void *(*keyof)(const YTNODE *)
);
void ytInsert(
    YTREE *, 
    YTNODE *
);
SInt32 compare_st(
    const void *p_elem1,
    const void *p_elem2
);
const void *keyof_st(
    const YTNODE *p_node
);
void preorder(
    YTNODE *p
);
void inorder(
    YTNODE *p
);
void postorder(
    YTNODE *p
);
void traversal(
    YTREE *t, 
    UInt8 order
);
UInt32 keydata(
    const YTNODE *p
);
void genarate_random_number(
	UInt8 *a,
	UInt8 num 
);
void handler_array(
	UInt8 *a, 
	UInt8 *size
);
void show_array(
	UInt8 *a,
	const UInt8 size
);
YTNODE *ytFind(
    YTREE *t,
    const void *item
);

void ytDelete(
    YTREE   *t,
    YTNODE  *p
);

#endif