#include <assert.h>
#include "ylib-bts.h"

const void *keyof_st(const YTNODE *p_node)
{
    return p_node ? &(((bst_search_node_t *)p_node)->data) : NULL;
}
/*******************************************************************
 *  Function    :   compare_st
 *  Input       :   const void *p_elem1
 *                  const void *p_elem2
 *  Output      :   result compare
 * 
 *  Description :   
 * *****************************************************************/
SInt32 compare_st(const void *p_elem1, const void *p_elem2)
{
    if(NULL == p_elem1 || NULL == p_elem2)
        return COMPARE_ERROR;
    if(*(UInt32 *)p_elem1 == *(UInt32 *)p_elem2)
    {
        return FISRT_IS_EQUAL_TO_SECOND;   
    }else if(*(UInt32 *)p_elem1 > *(UInt32 *)p_elem2)
    {
        return FISRT_IS_GREATER_THAN_SECOND;
    }else{
        return FISRT_IS_LESS_THAN_SECOND;
    }
}
/*******************************************************************
 *  Function    :   set_child
 *  Input       :   YTNODE  *p
 *                  UInt8   index
 *                  YTNODE  *q
 *  Output      :   YTNODE
 * 
 *  Description :   
 * *****************************************************************/
static YTNODE *set_child(YTNODE *p, UInt8 index, YTNODE *q)
{
    
    
    p->child[index] = q; /* Set q is children of p */
    if(q)
        q->parent = p; /* set p is parrent of q */
    return q;
}
/*******************************************************************
 *  Function    :   keydata
 *  Input       :   YTNODE *p
 *                  
 *  Output      :   data
 * 
 *  Description :   
 * *****************************************************************/
UInt32 keydata(const YTNODE *p)
{
    return p ? ((bst_search_node_t *)p)->data : INVALID_DATA;
}
/*******************************************************************
 *  Function    :   ytInit
 *  Input       :   YTREE   *p
 *                  SInt32 compare
 *                  const void *keyof
 *  Output      :   void
 * 
 *  Description :   
 * *****************************************************************/
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
 *  Function    :   ytInsert
 *  Input       :   YTREE   *p
 *                  YTNODE  *entry
 *  Output      :   void
 * 
 *  Description :   
 * *****************************************************************/
void ytInsert(YTREE *tree, YTNODE *entry)
{
    assert(NULL != entry);
    assert(NULL != tree);
    YTNODE *p;
    YTNODE *q;

    if((p = tree->root.child[0]) == 0) /* Tree is empty */
    {
        /* Setup entry */
        entry->red = 0;/* root is always black */
        entry->child[0] = entry->child[1] = NULL;
        set_child(&(tree->root),0, entry);
        tree->count++;
        LOG_MSG(LOG_DEBUG,"Insert node root  %p", entry);
        return;
    }
    for(;;)
    {
        if(tree->compare(tree->keyof(p), tree->keyof(entry)) == FISRT_IS_GREATER_THAN_SECOND)
        {
            q = p->child[0];
            if(q == NULL)
            {
                entry->child[0] = entry->child[1] = 0;
                set_child(p, 0, entry);
                tree->count++;
                LOG_MSG(LOG_DEBUG,"Insert node left  %p", entry);
                break;
            }
            p = q;
        }
        if(tree->compare(tree->keyof(p), tree->keyof(entry)) == FISRT_IS_LESS_THAN_SECOND)
        {
            q = p->child[1];
            if(q == NULL)
            {
                entry->child[0] = entry->child[1] = 0;
                set_child(p, 1, entry);
                tree->count++;
                LOG_MSG(LOG_DEBUG,"Insert node right %p", entry);
                break;
            }
            p = q;
        }else{

        }

    }

}
/*******************************************************************
 *  Function    :   preorder
 *  Input       :   YTNODE   *p
 *                  
 *  Output      :   void
 * 
 *  Description :   
 * *****************************************************************/
void preorder(YTNODE *p)
{
    if(!p)
    {   
        return;
    }else{
        printf("%u ",keydata(p));
        preorder(p->child[0]);
        preorder(p->child[1]);
    }
}
/*******************************************************************
 *  Function    :   inorder
 *  Input       :   YTNODE   *p
 *                  
 *  Output      :   void
 * 
 *  Description :   
 * *****************************************************************/
void inorder(YTNODE *p)
{
    if(!p)
    {   
        return;
    }else{
        inorder(p->child[0]);
        printf("%u ",keydata(p));
        inorder(p->child[1]);
    }
}
/*******************************************************************
 *  Function    :   postorder
 *  Input       :   YTNODE *p
 *      
 *  Output      :   void
 * 
 *  Description :   
 * *****************************************************************/
void postorder(YTNODE *p)
{
    if(!p)
    {   
        return;
    }else{
        postorder(p->child[1]);
        printf("%u ",keydata(p));
        postorder(p->child[0]);
    }
}
/*******************************************************************
 *  Function    :   traversal
 *  Input       :   YTREE   *t
 *                  UInt8   order
 *  Output      :   void
 * 
 *  Description :   
 * *****************************************************************/
void traversal(YTREE *t, UInt8 order)
{
    YTNODE *p = t->root.child[0];
    switch (order)
    {
    case T_PREORDER:
        /* code */
        {
            preorder(p);
            printf("\n");         
        }
        break;
    case T_INORDER:
        {
            inorder(p);
            printf("\n"); 
        }
        break;
    case T_POSTORDER:
        {
            postorder(p);
            printf("\n"); 
        }
        break;
    default:
        break;
    }
}
/*******************************************************************
 *  Function    :   find_node
 *  Input       :   YTREE   *t
 *                  const void (*keyof)(const YTNODE *)
 *  Output      :   void
 * 
 *  Description :   
 * *****************************************************************/
YTNODE *ytFind(
    YTREE *t,
    const void *item
)
{
    YTNODE *p;

    for(p = t->root.child[0]; p; )
    {
        SInt32 diff = t->compare(item, t->keyof(p));
        if(diff == FISRT_IS_GREATER_THAN_SECOND)
        {
            p = p->child[1];
        }else if(diff == FISRT_IS_LESS_THAN_SECOND)
        {
            p = p->child[0];
        }else{
            return p;
        }
        
    }
    return NULL;
}
/*******************************************************************
 *  Function    :   ytDelete
 *  Input       :   YTREE   *t
 *                  const YTNODE *p
 *  Output      :   void
 * 
 *  Description :   
 * *****************************************************************/
void ytDelete(
    YTREE   *t,
    YTNODE  *p_node
)
{
    YTNODE *p;
    YTNODE *q;
    YTNODE *parent;
    assert(NULL != p_node);
    if((p = t->root.child[0]) == NULL)
        return;
    if(p == p_node)
    {
        /* if p_node is root */
        /* then find node leaf of child[1] then set child is root.child[0]*/
        q = p->child[1];
        while (q->child[0])
        {
            q = q->child[0];
        }
        set_child(q, 0, p->child[0]);
        set_child(&(t->root), 0, p->child[1]);
        t->count--;
    }else if(NULL == p_node->child[0] && NULL == p_node->child[1])
    {
        /*if node is node leaf */
        p_node->parent->child[0] = p_node->parent->child[1] = NULL;
        t->count--;
    }else{

        parent = p_node->parent;
        if(p_node == parent->child[0])
        {
            if(p_node->child[0] && p_node->child[1])
            {
                q = p_node->child[1];
                while(q->child[0])
                {
                    q = q->child[0];
                }
                set_child(q, 0, p_node->child[0]);
                set_child(parent, 0, p_node->child[1]);
                t->count--;
            }else if(p_node->child[0])
            {
                set_child(parent, 0, p_node->child[0]);
            }else{
                set_child(parent, 0, p_node->child[1]);
            }
        }else{
            if(p_node->child[0] && p_node->child[1])
            {
                q = p_node->child[1];
                while(q->child[0])
                {
                    q = q->child[0];
                }
                set_child(q, 0, p_node->child[0]);
                set_child(parent, 1, p_node->child[1]);
                t->count--;
            }else if(p_node->child[0])
            {
                set_child(parent, 1, p_node->child[0]);
            }else{
                set_child(parent, 1, p_node->child[1]);
            }
        }
        
    }
    
}
