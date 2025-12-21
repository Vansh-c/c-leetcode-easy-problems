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
 

int sumOfLeftLeaves(struct TreeNode* root) {

    int count = 0 ; 
    if(root == NULL) return 0 ; 
    
    if(root->left!=NULL){
        if(root->left->left==NULL && root->left->right == NULL){
            count += root->left->val  ; 
        }
        else{
            count += sumOfLeftLeaves(root->left) ; 
        }
    }
  
     count += sumOfLeftLeaves(root->right) ;

     return count ; 
    
}


int main(){

    struct TreeNode *first = createNode(3) ; 
    struct TreeNode *sec = createNode(9) ; 
    struct TreeNode *third = createNode(20) ; 
    struct TreeNode *fourth = createNode(15); 
    struct TreeNode *fifth = createNode(7) ; 

    first->left = sec ; 
    first->right= third ; 

    third->left = fourth ; 
    third->right = fifth ; 

    int sum = sumOfLeftLeaves(first) ; 

    printf("%d" , sum) ; 


    return 0 ;
}