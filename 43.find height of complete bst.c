#include <stdio.h> 
#include <stdlib.h> 


 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 
int countNodes(struct TreeNode* root) {
    if(root == NULL){
        return 0 ; 
    } 

    int count = 0 ; 

    int left = countNodes(root->left) ; 
    int right = countNodes(root->right) ; 



    return left+right +1; 
 
}


struct TreeNode *createNode(int data){
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode)) ; 
    newNode->val = data ; 
    newNode->left = NULL ; 
    newNode->right = NULL ; 

    return newNode ; 
}


int main()
{

    struct TreeNode *first = createNode(1) ; 
    struct TreeNode *second = createNode(2) ; 
    struct TreeNode *third = createNode(3) ; 
    struct TreeNode *fourth = createNode(4); 
    struct TreeNode *fifth = createNode(5) ; 
    struct TreeNode *sixth = createNode(6) ; 

    

    first->left = second ; 
    second->left = fourth ; 
    second->right = fifth ; 

    first->right = third ; 
    third->left = sixth ; 

    printf("%d" , countNodes(first)) ; 


    return 0 ;
}