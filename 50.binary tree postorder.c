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
 

 
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0 ; 
    int *a = (int*)malloc(sizeof(int) * 100);
    *returnSize = 0;

    if (root == NULL)  
        return a;


    struct TreeNode *stack[100] ; 
    int top = -1 ; 

    struct TreeNode *current= root;  
    struct TreeNode *lastVisited = NULL ; 

    while(current!=NULL || top!=-1){
        if(current!=NULL){
            stack[++top] = current;  
            current = current->left ; 
        }
        else{
            struct TreeNode *other = stack[top]; 

            // if we have non visited right node go  there. 
            if(other->right!=NULL && lastVisited!=other->right){
                current = other->right  ; 
            }
            else{
                a[(*returnSize)++] = other->val ; 
                lastVisited = other ; 
                top-- ;   
            }
        }
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
    int *a = postorderTraversal(head,  &size) ;

    for(int  i = 0 ; i<size ; i++){
        printf("%d " , a[i]) ; 
    }


    return 0 ;
}