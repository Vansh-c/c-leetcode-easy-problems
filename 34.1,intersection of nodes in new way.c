#include <stdio.h> 
#include <stdlib.h> 


struct ListNode{
    int val ; 
    struct ListNode *next ; 
} ; 

struct ListNode *createNode(int val){
    struct ListNode *node = (struct ListNode*)malloc(sizeof(struct ListNode)) ; 
    node->val = val ; 
    node->next = NULL ; 
    return node ; 
}


struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int meet = 0 ; 
    struct ListNode *ptr = headB ; 
    struct ListNode  *p = headA ; 

    while(ptr!=p){
        if(ptr==NULL){
            ptr = headA ; 
        }
        else{
            ptr = ptr->next ; 
        }

        if(p==NULL){
            p = headB;
        }
        else{
            p = p->next ; 
        }
    }

 

     return  p ; 


}


void traverse(struct ListNode *root){
    while(root!=NULL){
        printf("%d " , root->val) ; 
        root = root->next ; 
    }
}

int main()
{


    struct ListNode *heada = createNode(4) ; 
    struct ListNode *one = createNode(1) ; 
    struct ListNode *eight = createNode(8) ; 
    struct ListNode *four = createNode(4) ; 
    struct ListNode *five = createNode(5)  ; 

    struct ListNode *headb = createNode(5) ; 
    struct ListNode *six = createNode(6) ; 
    struct ListNode *one1 = createNode(1) ; 

    heada->next = one ; 
    one->next = eight ; 
    eight->next = four ; 
    four->next = five ; 

    headb->next = six ; 
    six->next = one1 ;
    one1->next = eight ; 


    struct ListNode *intnode = getIntersectionNode(heada,  headb) ; 

    traverse(intnode) ; 


    return 0 ;
}