#include <assert.h>
#include "ytree.h"

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