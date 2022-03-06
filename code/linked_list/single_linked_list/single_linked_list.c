#include "single_linked_list.h"

yNode *create_node(unsigned int data);/* return node head */
int is_empty(const yNode *const head);
void add_fisrt(yNode **head, unsigned int data);
void add_last(yNode **head, unsigned int data);
yNode *get_last(yNode *const head);/* return node head */ 
yNode *find(yNode *const head, unsigned int data);/* return node head */
void remove_fist(yNode **head);
void remove_last(yNode **head);
void clear_list(yNode **head);
void print(yNode *const head);


/*****************************************************
 *   Function       :    create_node
 *   Input          :    data *inputData
 *   Ouput          :    new node in linked list
 *   Description    :    A function create a new node
 *                       in linked list
 * ****************************************************/
yNode *create_node(
     unsigned int data
)
{
     yNode *newNode  = (yNode *)malloc(sizeof(yNode));
     newNode->data = data;
     newNode->pNext = NULL;
     return newNode;
}
/*****************************************************
 *   Function       :    create_node
 *   Input          :    data *inputData
 *   Ouput          :    new node in linked list
 *   Description    :    A function check list is empty
 *                       if list hava to head node that is zero 
 * ****************************************************/
int is_empty(
     const yNode *const head
)
{
     return head == NULL; 
}
/*****************************************************
 *   Function       :    create_node
 *   Input          :    data *inputData
 *   Ouput          :    new node in linked list
 *   Description    :    A function check list is empty
 *                       if list hava to head node that is zero 
 * ****************************************************/
void add_fisrt(
     yNode **head, 
     unsigned int data
)
{
     yNode *newNode = create_node(data);
     if(is_empty(*head))
     {
          *head = newNode;
     }
     else
     {
          newNode->pNext = *head;
          /* Update head */
          *head = newNode;
     }
}
/*****************************************************
 *   Function       :    create_node
 *   Input          :    data *inputData
 *   Ouput          :    new node in linked list
 *   Description    :    A function check list is empty
 *                       if list hava to head node that is zero 
 * ****************************************************/
void add_last(
     yNode **head, 
     unsigned int data
)
{
     yNode *newNode = create_node(data);
     if(is_empty(*head))
     {
          *head = newNode;
     }else
     {
          yNode *tmp = *head;
          while(tmp->pNext != NULL)
          {
               tmp = tmp->pNext;
          }
          tmp->pNext = newNode;
          printf("Address[%d] = %p %p\n", tmp->pNext->data, tmp->pNext, newNode);
     }
}
/*****************************************************
 *   Function       :    create_node
 *   Input          :    data *inputData
 *   Ouput          :    new node in linked list
 *   Description    :    A function check list is empty
 *                       if list hava to head node that is zero 
 * ****************************************************/
yNode *get_last(
     yNode *const head
)
{
     if(is_empty(head))
     {
          printf("List is empty!");
          exit(1);
     }else
     {
          yNode *tmp = head;
          while(tmp->pNext != NULL)
          {
               tmp = tmp->pNext;
          }
          return tmp;
     }

}
/*****************************************************
 *   Function       :    create_node
 *   Input          :    data *inputData
 *   Ouput          :    new node in linked list
 *   Description    :    A function check list is empty
 *                       if list hava to head node that is zero 
 * ****************************************************/
yNode *find(
     yNode *const head,
     unsigned int data
)
{
     if(is_empty(head))
     {
          printf("List is empty!");
          exit(1);
     }else
     {
          yNode *tmp = head;
          while (tmp->pNext != NULL)
          {
               if(tmp->data == data)
               {
                    return tmp;
               }
          }

          if(tmp->data == data)
          {
               return tmp;
          }else{
               return NULL;
          }
          
     }
}
/*****************************************************
 *   Function       :    create_node
 *   Input          :    data *inputData
 *   Ouput          :    new node in linked list
 *   Description    :    A function check list is empty
 *                       if list hava to head node that is zero 
 * ****************************************************/
void remove_first(
     yNode **head
)
{
     if(is_empty(*head))
     {
          printf("list is empty");
          return;
     }else
     {
          yNode *tmp = *head;
          if(tmp->pNext == NULL)
          {
               free(*head);
               *head = NULL;
          }else
          {
               (*head) = tmp->pNext; 
               /* Update head */
               tmp->pNext = NULL;
               free(tmp);
          }
     }
}
/*****************************************************
 *   Function       :    create_node
 *   Input          :    data *inputData
 *   Ouput          :    new node in linked list
 *   Description    :    A function check list is empty
 *                       if list hava to head node that is zero 
 * ****************************************************/
void remove_last(
     yNode **head
)
{
     if(is_empty(*head))
     {
          printf("list is empty");
          return;
     }else
     {
          yNode *tmp = *head;
          while(tmp->pNext != NULL)
          {
               tmp = tmp->pNext;
          }
          free(tmp);
          tmp = NULL;
          
     }
}
/*****************************************************
 *   Function       :    create_node
 *   Input          :    data *inputData
 *   Ouput          :    new node in linked list
 *   Description    :    A function check list is empty
 *                       if list hava to head node that is zero 
 * ****************************************************/
void clear_list(
     yNode **head
)
{
     if(is_empty(*head))
     {
          printf("list is empty \n");
          return ;
     }
     while(*head != NULL)
     {
          yNode *p = *head;
          *head = p->pNext;
          free(p);
     }
}
/*****************************************************
 *   Function       :    create_node
 *   Input          :    data *inputData
 *   Ouput          :    new node in linked list
 *   Description    :    A function check list is empty
 *                       if list hava to head node that is zero 
 * ****************************************************/
void print(
     yNode *const head
)
{
     yNode *p = head;
     if(is_empty(head))
     {
          printf("list is empty\n");
          return;
     }
     unsigned int i = 0;
     for(; p != NULL; p = p->pNext)
     {
          printf("[%d]. Address[%d] = %p \n",i++, p->data, p);
     }

}

