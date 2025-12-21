


#include <stdio.h> 
#include <stdlib.h>

struct ListNode{
  int val ; 
  struct ListNode *next ; 
}; 

struct ListNode *createNode(int val){
   struct ListNode *root = (struct ListNode *)malloc(sizeof(struct ListNode) ) ; 
   root->val = val ; 
   root->next = NULL ; 

   return root ; 
}




void printNodes(struct ListNode *root){
  while(root!=NULL){
    printf("%d "  , root->val) ; 
    root = root->next ; 
  }
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
     struct ListNode *ptr = (struct ListNode *)malloc(sizeof(struct ListNode)) ; 
     struct ListNode *p  ; 
     ptr = head ;    

     while(ptr!=NULL && ptr->next!=NULL){
      p =  ptr->next ; 
      if(ptr->val == p->val){
          ptr->next = p->next ; 
          free(p);
      }
      else{
        ptr = ptr->next ; 
      }
      
       
     }

     return head ; 
}


int main()
{

  struct ListNode *head = createNode(1) ; 
  struct ListNode *second = createNode(1) ; 
  struct ListNode *third = createNode(1) ; 

  head->next = second ; 
  second->next = third ; 
  third->next=  NULL ; 

  printNodes(head) ; 
  head = deleteDuplicates(head) ; 
  printf("\n") ; 
  printNodes(head) ; 


  return 0 ;
}