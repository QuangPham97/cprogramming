#include "ylib-bts.h"
__sighandler_t sigusr_handler(SInt32 sig_number)
{
    printf("Process PDI %d received signal %d\n",getpid(), sig_number);
    sleep(1);
	exit(-1);
}
int main(int argc, char const *argv[])
{
    // signal(SIGSEGV, sigusr_handler);
	// signal(SIGHUP, sigusr_handler);
	// signal(SIGINT, sigusr_handler);
	// signal(SIGQUIT, sigusr_handler);
	// signal(SIGILL, sigusr_handler);
	// signal(SIGTRAP, sigusr_handler);
	// signal(SIGABRT, sigusr_handler);
    UInt8 size = MAX_TREE_ELEMENT;
    UInt8 array_test[MAX_TREE_ELEMENT];
    genarate_random_number(array_test, size);
    handler_array(array_test, &size);
	printf("------------------- DATA ORIGIN ----------------------------\n");
	show_array(array_test, size);
    search_tree_t  *p_tree = (search_tree_t *)malloc(sizeof(search_tree_t)); 
    ytInit(&p_tree->st_search_tree, (compare_func)compare_st, keyof_st);
    UInt8 index = 0;
    for(; index < size; index++)
    {
        bst_search_node_t *p_node = (bst_search_node_t *)malloc(sizeof(bst_search_node_t));
        p_node->data = array_test[index];
        p_node->context = &array_test[index];
        ytInsert(&p_tree->st_search_tree,&p_node->node_anchor);
    }
	printf("----------------------Traversal PREORDER ----------------------\n");
	traversal(&p_tree->st_search_tree, T_PREORDER);
	printf("----------------------Traversal INORDER -----------------------\n");
	traversal(&p_tree->st_search_tree, T_INORDER);
	printf("----------------------Traversal POSTORDER ---------------------\n");
	traversal(&p_tree->st_search_tree, T_POSTORDER);
	UInt32 data = array_test[0];
	bst_search_node_t *p_node_find = (bst_search_node_t *)(ytFind(&p_tree->st_search_tree, &data));
	printf("p_node_find = %p\n", p_node_find);
	printf("p_node_find->data = %u\n", p_node_find->data);
	printf("p_node_find->context = %p\n", p_node_find->context);
	ytDelete(&p_tree->st_search_tree, (YTNODE *)p_node_find);
	free(p_node_find);
	printf("-----------Traversal INORDER After Delete Node ----------------\n");
	traversal(&p_tree->st_search_tree, T_INORDER);

    /* code */
    return 0;
}
