#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>


struct TreeNode {
      int val;
      struct TreeNode *left;
     struct TreeNode *right;
  };


struct TreeNode *createNode(int data){
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode)) ; 
    newNode->val =data ; 
    newNode->left = NULL ; 
    newNode->right = NULL ;

    return newNode ; 
}



int maxDepth(struct TreeNode* root) {
    int count = 0 ; 


    if(root==NULL){
        return 0 ; 
    }

    int leftside = maxDepth(root->left) ; 
    int rightside = maxDepth(root->right) ; 

    if(leftside>rightside){
        count = leftside ; 
    }
    else{
        count = rightside ; 
    }

    return count + 1 ; 
    
}


int main()
{

        struct TreeNode *head =createNode(1) ; 
    struct TreeNode *second = createNode(2) ; 
    struct TreeNode *second1 = createNode(2) ; 
    struct TreeNode *third = createNode(3) ; 
    struct TreeNode *third1 = createNode(3) ; 

    struct TreeNode *fourth = createNode(4) ; 
    struct TreeNode *fourth1 = createNode(4) ;

    head->left = second ; 
    head->right = second1 ; 
    second->left=  third ; 
    second->right = fourth ; 
    second1->left = fourth ; 
    second1->right = third ;

    printf("maximum depth is %d" , maxDepth(head)) ; 


    return 0 ; 
}