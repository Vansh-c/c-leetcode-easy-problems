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


int d= 0 ;

int findheight(struct TreeNode *root){
        struct TreeNode *current = root; 
    if(root==NULL){
        return 0 ; 
    }
    int left = findheight(root->left); 
    int right = findheight(root->right) ;

    if(left+right> d){
        d = left+right ; 
    } 

    if(left>right){
        return left+1 ; 
    }
    else{
        return right + 1;
    }

}
 
int diameterOfBinaryTree(struct TreeNode* root) {
    d = 0 ;
    findheight(root) ; 
    return d ; 
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

    printf("diameter of tree = %d" , diameterOfBinaryTree(head)) ;

 


    return 0 ; 
}