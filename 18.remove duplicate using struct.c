#include <stdio.h> 
#include <stdlib.h>

struct Node{
    int data ; 
    struct Node *next ; 
};


void printNodes(struct Node *ptr){
    while(ptr!=NULL){
        printf("%d " , ptr->data) ; 
        ptr = ptr->next ;
    }
}

struct Node *deleteDuplicate(struct Node *first){
        struct Node *ptr = (struct Node*)malloc(sizeof(struct Node)) ; 
    struct Node *p = (struct Node*)malloc(sizeof(struct Node)) ; 
    ptr = first ; 
    p = first->next ; 

    while(ptr->data == p->data && ptr->next!=NULL){
        ptr = p->next ; 
        p = p->next ; 
    }

   
    free(p) ; 
    return first;  
}



int main()
{
  struct Node *first = (struct Node*)malloc(sizeof(struct Node)); 
  struct Node *second = (struct Node*)malloc(sizeof(struct Node)); 
  struct Node *third = (struct Node*)malloc(sizeof(struct Node)); 
  struct Node *fourth = (struct Node*)malloc(sizeof(struct Node)); 

  first->data = 1 ; 
  first->next = second ; 
  second->data = 1 ; 
  second->next = third ; 
  third->data = 2 ; 
  third->next = fourth ;
  fourth->data = 3 ; 
  fourth->next = NULL ;

  printNodes(first) ; 

  printf("\nafter deleting duplicates \n") ; 
  first = deleteDuplicate(first)  ;

  printNodes(first) ;
    return 0 ;
}