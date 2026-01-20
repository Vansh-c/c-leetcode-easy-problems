#include <stdio.h> 
#include <stdlib.h>

struct Node{
    int val ; 
    int numChildren ; 
    struct Node **children ; 
} ; 


struct Node *createNode(int val , int numChildren){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node)) ; 
    node->val = val; 
    node->numChildren = numChildren ; 

    if(numChildren > 0){
        node->children = (struct Node **)malloc(sizeof(struct Node *)*numChildren) ;
    }
    else{
        node->children = NULL ;
    }

    return node ;
}


int *preorder(struct Node *root , int *returnSize){
    if(root == 0){
        *returnSize = 0 ; 
        return NULL ;
    }

    int *result = (int *)malloc(sizeof(int)*1000) ;

    struct Node *stack[1000] ; 
    int top = -1;  

    stack[++top] = root ; 

    int k = 0 ; 

    while(top != -1){
        struct Node *current = stack[top--] ; 

        result[k++] = current->val ; 

        // pushing children in reverse order . 
        for(int i = current->numChildren - 1 ; i>=0 ; i--){
            stack[++top] = current->children[i] ;
        }


    }

    *returnSize = k ;


 return result ;

}

int main()
{
    struct Node *first = createNode(1, 3) ; 
    struct Node *second = createNode(2,0) ;
    struct Node *third = createNode(3,1) ; 
    struct Node *fourht = createNode(4,0) ; 
    struct Node *fifth = createNode(5,0) ; 

    first->children[0] = second ; 
    first->children[1] = third ; 
    first->children[2] = fourht ; 

    third->children[0] = fifth ; 

    int returnSize ; 

    int *r = preorder(first ,&returnSize ) ; 

    for(int i = 0 ; i<returnSize  ; i++){
        printf("%d " , r[i]) ;
    }





    return 0 ;
}