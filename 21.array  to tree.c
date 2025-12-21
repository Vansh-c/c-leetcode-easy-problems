#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int val ; 
    struct TreeNode *left ; 
    struct TreeNode *right ; 
} ;

struct TreeNode *treeBuilder(int *a , int left , int right){

    if(left>right){
        return NULL ; 
    }

    int mid = (right + left)/2 ; 

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode)) ; 

    root->val = a[mid] ; 

    root->left = treeBuilder(a , left , mid-1) ; 
    root->right = treeBuilder(a , mid+1 , right) ; 

    return root ; 

}



struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return treeBuilder(nums , 0 , numsSize-1); 

}


void inorder(struct TreeNode *root){
    if(root == NULL) return ;

    
    inorder(root->left) ; 
    printf("%d " , root->val) ; 
    inorder(root->right) ; 
}


int main(){


    int a[] = {-10,-3,0,5,9} ; 
    int l = sizeof(a)/ sizeof(int) ; 

    struct TreeNode *tree =sortedArrayToBST(a , l) ; 


    inorder(tree) ; 


    return 0 ;
}