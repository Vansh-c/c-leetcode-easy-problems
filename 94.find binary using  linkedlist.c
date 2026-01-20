#include <stdio.h> 
#include <stdlib.h> 


 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
int getDecimalValue(struct ListNode* head) {
    int sum = 0 ; 
    int total = 1 ;
    struct ListNode *ptr = head ;
    struct ListNode *stack[100] ;
    int top = -1 ;

    while(ptr!=NULL){
        stack[++top] = ptr;  
        ptr= ptr->next; 
    }

    while(top!= -1){
        if(stack[top]->val == 1){
            sum = sum + total ; 
        }
        total = total*2 ; 
        top-- ;
    }

 
    return sum ;
}


struct ListNode *createNode(int val){
    struct ListNode *newNode  = (struct ListNode *)malloc(sizeof(struct ListNode)) ;
    newNode->val = val ; 
    newNode->next = NULL  ;

    return newNode ;
}

int main(){
    
    struct ListNode *head = createNode(1) ;
    struct ListNode *second = createNode(0) ;
    struct ListNode *third = createNode(1) ;
    struct ListNode *fourth = createNode(1);

    head->next = second ; 
    second->next = third ; 
    third->next = fourth ; 

    printf("value = %d" , getDecimalValue(head)) ;



    return 0 ;
}