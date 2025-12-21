#include <stdio.h> 
#include <stdlib.h>


struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };


 struct TreeNode *createNode(int data){
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode)) ; 
    newNode->val = data ; 
    newNode->left = NULL ; 
    newNode->right = NULL ; 

    return newNode; 
}
 

 
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    struct TreeNode *stack[100] ; 
    int top = -1; 
    *returnSize = 0  ; 
    int *a  = (int *)malloc(100*sizeof(int)) ; 
    struct TreeNode *current = root ;  


    while(current!=NULL || top!=-1){


        
        while(current!=NULL){
            a[(*returnSize)++] = current->val ; 
            stack[++top] = current ; 
            current = current->left ; 
        }

        current= stack[top--]; 
    

        current = current->right ; 

    }

    return a ; 
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

    int size ; 
    int *a = preorderTraversal(head,  &size) ;

    for(int  i = 0 ; i<size ; i++){
        printf("%d " , a[i]) ; 
    }


    return 0 ;
}