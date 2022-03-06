#include "single_linked_list.h"

int main(int argc, char **argv)
{
     yNode *head = NULL;
     unsigned int a[5] = {1, 2, 3, 4, 5};
     unsigned int i = 0;
     for(; i < 5; i++)
     {
         add_last(&head, a[i]);
     }
     print(head);
     add_last(&head, 10);
     print(head);
     remove_first(&head);
     print(head);
     clear_list(&head);
     print(head);



     return EXIT_SUCCESS;
}