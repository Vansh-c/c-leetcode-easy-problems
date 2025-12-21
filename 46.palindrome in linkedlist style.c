#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>


  
struct ListNode {
      int val;
      struct ListNode *next;
 };
 
bool isPalindrome(struct ListNode* head) {
    struct ListNode *prev = NULL ; 
    struct ListNode *p = head ; 
    struct ListNode *next  = head ; 
    int k = 0 ; 
    struct ListNode *orignalhead = head ; 

    
    int *a = (int *)malloc(sizeof(int)*200) ;


    while(p!=NULL){
        a[k] = next->val ; 
        k++ ; 
        next = p->next ; 
        p->next= prev ; 
        prev = p ; 
        p = next ;  
    }

    for(int i = 0 ; i<k ; i++){
        printf("%d " , a[i]) ; 
    }

    for(int i = 0 ; i<k ; i++){
        if(a[i]!=prev->val){
            return false; 
        }

        prev= prev->next ; 
    }
 


    return true ; 
}


struct ListNode *createNode(int val){
   struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode)) ; 
   newNode->val = val ; 
   newNode->next= NULL ; 

   return newNode ; 
}

int main()
{


    struct ListNode *first = createNode(1) ; 
    struct ListNode *second = createNode(2) ; 
    struct ListNode *third = createNode(4) ; 
    struct ListNode *fourth = createNode(1) ; 

    first->next = second ; 
    second->next = third ; 
    third->next = fourth ; 
    
    
    if(isPalindrome(first)){
        printf("it's an palindrome") ; 
    }
    else{
        printf("not an palindrome") ; 
    }

    return 0 ;
}