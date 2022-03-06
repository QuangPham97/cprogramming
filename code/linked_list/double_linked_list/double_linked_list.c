#include "double_linked_list.h"

yNode *create_dl_node(const int data);
int is_dl_empty(const yNode * const head);
void add_fisrt_dl(yNode **head, const int data);
void add_last_dl(yNode **head, const int data);
yNode *get_last_dl(yNode *const head);
yNode *find_dl(yNode *const head, const int data);
void remove_first_dl(yNode **head);
void remove_last_dl(yNode **head);
void clear_list_dl(yNode **head);
void print_dl(yNode *const head);

yNode *create_dl_node(
     const int data
)
{
     yNode *newNode = (yNode *)malloc(sizeof(yNode));
     newNode->data = data;
     newNode->pNext = NULL;
     newNode->pPrevios = NULL;
     return newNode;
}
int is_dl_empty(
     const yNode * const head
)
{
     return head == NULL;
}

void add_fisrt_dl(
     yNode **head,
     const int data
)
{
     yNode *p = create_dl_node(data);
     if(is_dl_empty(*head))
     {
          *head = p;
     }else
     {
          p->pNext = *head;
          (*head)->pPrevios = p;
          *head = p;    
     }
}

void add_last_dl(
     yNode **head,
     const int data
)
{
     yNode *p = create_dl_node(data);
     if(is_dl_empty(*head))
     {
          *head = p;
     }else
     {
          yNode *index = *head;
          while(index->pNext != NULL)
          {
               index = index->pNext;
          }

          index->pNext = p;
          p->pPrevios = index;
     }
}

yNode *get_last_dl(
     yNode *const head
)
{
     if(is_dl_empty(head))
     {
          printf("double link list is empty.");
          return ;
     }
     yNode *index = head;
     while(index->pNext != NULL)
     {
          index = index->pNext;
     }
     return index;
}

yNode *find_dl(
     yNode *const head, 
     const int data
)
{
     if(is_dl_empty(head))
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
void remove_first_dl(
     yNode **head
)
{
     if(is_dl_empty(*head))
     {
          printf("double linked list is empty !\n");
          return ;
     }
     yNode *tmp = *head;
     *head = tmp->pNext;
     (*head)->pPrevios = NULL;
     tmp->pNext = NULL;
     free(tmp);
     tmp = NULL;
}

void remove_last_dl(
     yNode **head
)
{
     if(is_dl_empty(*head))
     {
          printf("double linked list is empty !\n");
          return ;
     }
     if((*head)->pNext == NULL & (*head)->pPrevios == NULL)
     {
          free(*head);
          *head = NULL;
     }else
     {
          yNode *tmp = *head;
          while (tmp->pNext != NULL)
          {
               tmp = tmp->pNext;
          }
          tmp->pPrevios = NULL;
          free(tmp);
          tmp = NULL;
     }
}
void clear_list_dl(
     yNode **head
)
{
     if(is_dl_empty(*head))
     {
          printf("double linked list is empty !\n");
          return ;
     }
     while (*head != NULL)
     {
          yNode *tmp = *head;
          *head = tmp->pNext;
          tmp->pPrevios = NULL;
          tmp->pNext = NULL;
          (*head)->pPrevios = NULL;
          free(tmp);
          tmp = NULL;
     }
     
}
void print_dl(
     yNode *const head
)
{
     int index = 0;
     yNode *p = head;
     for(; p!= NULL;p = p->pNext)
     {
          printf("data[%d] in Address[%p]", p->data, p);
     }
}