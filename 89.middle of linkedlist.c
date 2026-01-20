#include <stdio.h> 
#include <stdlib.h> 


struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode *createNode(int val){
    struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode)) ; 
    newNode->val = val ; 
    newNode->next=  NULL ; 

    return newNode ;
}
 
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *current = head; 
    struct ListNode *returnNode = head ; 

    int count = 0 ; 
    while(current!=NULL){
        count++ ; 
        current = current->next;
    }

    int midway = count/2 ;  
    int i = 0 ; 

    while(i<midway){
          returnNode = returnNode->next ; 
          i++ ; 
    }


    return returnNode ; 
}


void printNode(struct ListNode *head){
    while(head!=NULL){
        printf("%d " , head->val) ; 
        head = head->next; 
    }

    printf("\n") ; 

}

int main()
{

    struct ListNode *first=  createNode(1) ; 
    struct ListNode *second = createNode(2) ; 
    struct ListNode *third = createNode(3) ; 
    struct ListNode *fourth = createNode(4) ; 
    struct ListNode *fifth = createNode(5) ; 
    struct ListNode *sixth = createNode(6) ; 

    first->next = second ; 
    second->next = third ; 
    third->next = fourth ; 
    fourth->next = fifth ; 
    fifth->next = sixth ; 
    sixth->next = NULL ; 

    first = middleNode(first) ; 
    printNode(first) ;


    return 0 ;
}