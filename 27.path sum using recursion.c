#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode *createNode(int val){
   struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode) ) ; 
   root->val = val ; 
   root->left = NULL ; 
   root->right = NULL ; 

   return root ; 
}


bool hasPathSum(struct TreeNode* root, int targetSum) {
        
    if(root == NULL){
        return 0 ;
    }
    // checking if the node is leaf node or not . 
    if(root->left == NULL && root->right == NULL){
        return root->val == targetSum ; 
    }

    int remainder = targetSum - root->val ; 

    return hasPathSum(root->left , remainder)  || hasPathSum(root->right , remainder) ;
}

int main()
{


    struct TreeNode *head = createNode(5) ; 
    struct TreeNode *fourth = createNode(4) ; 
    struct TreeNode *eleveth = createNode(11) ; 
    struct TreeNode *seventh = createNode(7) ; 
    struct TreeNode *second = createNode(2) ; 

    struct TreeNode *eighth = createNode(8) ; 
    struct TreeNode *thirteen = createNode(13) ; 
    struct TreeNode *four2 = createNode(4) ; 
    struct TreeNode *one = createNode(1) ; 

    head->left = fourth  ; 
    fourth->left = eleveth ; 
    eleveth->left = seventh ; 
    eleveth->right = second  ; 

    head->right = eighth ; 
    eighth->left = thirteen ; 
    eighth->right =four2 ; 
    four2->right = one ; 

    if(hasPathSum(head , 27)){
        printf("it's true") ; 
    }
    else{
        printf("path not found") ; 
    }




    return  0 ; 
}