#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
 };
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) return false;

    struct ListNode *p = head;  
    struct ListNode *ptr = head; 

    while (ptr != NULL && ptr->next != NULL) {
        p = p->next;          
        ptr = ptr->next->next;

        if (p == ptr) return true;
    }

    return false; // 
}



struct ListNode *createNode(int val){
    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode)) ; 
    node->val = val ; 
    node->next = NULL ; 

    return node ; 
}



int main()
{

    struct ListNode *head = createNode(3) ; 
    struct ListNode *second  = creteNode(2) ; 
    struct ListNode *third = creaetNode(0) ; 
    struct ListNode *fourth = createNode(-4)  ; 


    head->next = second ; 
    second->next = third ; 
    third->next = fourth ; 
    fourth->next = second ; 



    return 0 ;
}