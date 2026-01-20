#include <stdio.h> 
#include <stdlib.h> 


struct Node{
    int val ; 
    int numChildren  ;
    struct Node **children ; 
} ; 


// below is createNode function 

struct Node* createNode(int val, int numChildren) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->numChildren = numChildren;

    if (numChildren > 0) {
        node->children = (struct Node**)malloc(numChildren * sizeof(struct Node*));
    } else {
        node->children = NULL;
    }

    return node;
}


void preOrderHelper(struct Node *root  , int *res , int *index){
    if(root == NULL) return ; 

    res[*index] = root->val ;
    (*index)++  ; 

    for(int i = 0 ; i<root->numChildren ; i++){
        preOrderHelper(root->children[i] , res , index) ; 
    }
}


int *preorder(struct Node *root , int *returnSize){
    int *res = (int *)malloc(sizeof(int) * 1000) ;
    *returnSize=  0 ; 

    preOrderHelper(root, res , returnSize) ;
    return res ;
}



int main(){

    struct Node* root = createNode(1, 3);
    struct Node* n2 = createNode(2, 0);
    struct Node* n3 = createNode(3, 1);
    struct Node* n4 = createNode(4, 0);
    struct Node* n5 = createNode(5, 0);

    root->children[0] = n2;
    root->children[1] = n3;
    root->children[2] = n4;

    n3->children[0] = n5;

    int returnSize;
    int* result = preorder(root, &returnSize);

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    printf("\n") ;


    return 0;
}