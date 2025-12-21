#include <stdio.h> 
#include <stdlib.h>

struct TreeNode{
    int val ; 
    struct TreeNode *left ; 
    struct TreeNode *right ; 
} ; 


struct TreeNode *createNode(int data){
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode)) ; 
    newNode->val = data ; 
    newNode->left = NULL ; 
    newNode->right = NULL ; 

    return newNode; 
}


int *inorderTraversal(struct TreeNode *root,  int *returnSize){
     int *res = (int *)malloc(sizeof(int)*100) ;
     *returnSize = 0 ;  



     struct TreeNode  *stack[100] ;
     int top = -1 ; 
     struct TreeNode *current = root ; 



     while(current != NULL || top!= -1){
        while(current != NULL){
            stack[++top] = current ; 
            current = current->left ; 
        }

        current = stack[top--] ; 
        res[(*returnSize)++] = current->val ; 

        current = current->right ; 
     }

     return res ; 
}



int main()
{
     
    struct TreeNode *head = createNode(1) ; 
    struct TreeNode *second = createNode(2) ; 
    struct TreeNode *third = createNode(3) ; 
    struct TreeNode *fourth = createNode(4) ; 
    struct TreeNode  *fifth = createNode(5) ; 


    head->left = second ;
    head->right = third ; 
    second->left = fourth ; 
    second->right = fifth ;

    int size  ; 

    int *a = inorderTraversal(head , &size) ; 
 

    for(int i = 0 ; i<size ; i++){
        printf("%d " , a[i]) ; 
    }


    return 0 ; 
}