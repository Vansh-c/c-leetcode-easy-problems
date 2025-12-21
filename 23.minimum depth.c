#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 

struct TreeNode{
    int val ; 
    struct TreeNode *left ; 
    struct TreeNode *right ; 
}; 


struct TreeNode *createNode(int data){
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode)) ; 
    newNode->val = data ; 
    newNode->left = NULL ; 
    newNode->right = NULL ; 

    return newNode ; 
}



void  traverseNode(struct TreeNode *head){
   if(head!=NULL){
       printf("%d " , head->val) ; 
    traverseNode(head->left) ; 
    traverseNode(head->right);
   }
}


int minDepth(struct TreeNode* root) {

    if(root == NULL){
        return 0 ;
    }

    int left = minDepth(root->left) ; 
    int right = minDepth(root->right) ; 

    if(root->left == NULL){
        return right+1 ; 
    }

    if(root->right == NULL){
        return left+ 1 ; 
    }


    if(left<right){
        return left + 1 ; 
    }

    else{
        return right + 1 ; 
    }
    

}


int main()
{



    struct TreeNode *head = createNode(3) ;
    struct TreeNode *second = createNode(9) ; 
    struct TreeNode *third = createNode(20) ; 
    struct TreeNode *fourth = createNode(15) ; 
    struct TreeNode *fifth = createNode(7) ; 

    head->left = second ; 
    head->right = third ; 
    third->left = fourth ; 
    third->right = fifth ; 

    traverseNode(head);

    printf("\nminimum depth = %d \n" , minDepth(head)) ; 


    return 0 ;
}