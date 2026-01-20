#include <stdio.h> 
#include <stdlib.h> 


struct Node{
    int val ; 
    int numChildren ; 
    struct Node **children ; 
} ; 

struct Node *createNode(int val , int numChildren){
    struct Node *node=  (struct Node *)malloc(sizeof(struct Node)) ; 
    node->val = val ; 
    node->numChildren = numChildren ; 


    if(numChildren>0){
        node->children = (struct Node**)malloc(sizeof(struct Node*)*numChildren) ;


    }
    else{
        node->children = NULL ; 
    }


    return node ;
}


int maxDepth(struct Node* root) {
    if(root==NULL){
        return 0 ; 
    }

    int maxHeight = 0 ; 

    for(int i = 0 ; i<root->numChildren ; i++){
        int childHeight = maxDepth(root->children[i]) ; 
        if(childHeight > maxHeight){
            maxHeight = childHeight ; 
        }
    }

    return 1+ maxHeight ; 
}



int main(){

    struct Node *first = createNode(1,3) ; 
    struct Node *third = createNode(3,2) ; 
    struct Node *two = createNode(2,0) ; 
    struct Node *four = createNode(4,0) ; 
    struct Node *five = createNode(5,0) ;
    struct Node *sixth = createNode(6,0) ; 


    first->children[0] = third ; 
    first->children[1] = two ; 
    first->children[2] = four ; 

    third->children[0] = five ; 
    third->children[1]  = sixth ; 

    printf("Maxdepth = %d" , maxDepth(first)) ; 


    return 0 ;
}