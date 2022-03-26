#include <assert.h>
#include "ytree.h"

static YTNODE *setChild(YTNODE *p, UInt8 index, YTNODE *q)
{
    assert(NULL != p);
    assert(NULL != q);
    p->child[index] = q; /* Set q is children of p */
    if(q)
        q->parent = p; /* set p is parrent of q */
    return q;
}

void ytInit(YTREE *tree, SInt32 (*compare)(const void *, const void *), const void *(*keyof)(const YTNODE *))
{
    assert(compare != NULL);
    assert(keyof != NULL);
    tree->root.parent = NULL;
    tree->root.child[0] = NULL;
    tree->root.child[1] = NULL;
    tree->compare = compare;
    tree->keyof = keyof;
    tree->count = 0;

}
/*******************************************************************
 *  Step 1: 
 * 
 * 
 * 
 * 
 * 
 * *****************************************************************/

void ytInsert(YTREE *tree, YTNODE *entry)
{
    assert(NULL != entry);
    assert(NULL != tree);
    if(tree->count == 0) /* Tree is empty */
    {
        /* Setup entry */
        entry->red = 0;/* root is always black */
        entry->child[0] = entry->child[1] = NULL;
        setChild(&(tree->root),0, entry);
        tree->count++;
        return;
    }

}