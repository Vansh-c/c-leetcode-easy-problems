
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
  };
 


struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *current_node = head ; 
    struct ListNode *next_node = head ; 
    struct ListNode *prev = NULL ; 

    while(current_node!=NULL){
        next_node = current_node->next ;      
        current_node->next = prev ; 
        prev = current_node ;  
        current_node = next_node ; 
    }
    
return prev; 
}


void traverse(struct ListNode *root){
    while(root!=NULL){
        printf("%d " , root->val) ; 
        root = root->next ; 
    }

    printf("\n") ; 
}


struct ListNode *createNode(int val){
    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode)) ; 
    node->val = val ; 
    node->next = NULL ; 
    return node ; 
}




int main()
{

    struct ListNode *head = createNode(1) ; 
    struct ListNode *second = createNode(2) ; 
    struct ListNode *third = createNode(3) ; 
    struct ListNode *fourth = createNode(4) ;
    struct ListNode *fifth = createNode(5) ;

    head->next = second ;
    second->next = third ; 
    third->next = fourth ; 
    fourth->next = fifth ; 

    traverse(head) ;
    head = reverseList(head) ;
    traverse(head) ; 



    return 0 ; 
}