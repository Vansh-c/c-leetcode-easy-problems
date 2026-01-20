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
    int *a = (int *)malloc(sizeof(int) *100) ; 
    *returnSize = 0 ; 

    struct TreeNode *stack1[100] ; 
    struct TreeNode *stack2[100] ; 
    int top1= -1 ; 
    int top2 = -1 ; 

    stack1[++top1] = root; 

    while(top1!=-1){
        struct TreeNode *node = stack1[top1--] ; 
        stack2[++top2] = node ; 

        if(node->left!=NULL) {
            stack1[++top1] = node->left ; 

        }

        if(node->right!=NULL){
            stack1[++top1] = node->right; 
        }


    }

    while(top2!=-1){
        a[(*returnSize)++] = stack2[top2--]->val ; 
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

    int *arr = postorderTraversal(head , &size) ; 

    for(int i = 0 ; i<size;  i++){
        printf("%d " , arr[i]) ; 
    }

 


    return 0 ; 
}