#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>

struct TreeNode{
    int val ; 
    struct TreeNode *right ; 
    struct TreeNode *left;  
} ; 

struct TreeNode *createNode(int data){
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode)) ; 
    newNode->val =data ; 
    newNode->left = NULL ; 
    newNode->right = NULL ;

    return newNode ; 
}



bool checksides(struct TreeNode *l , struct TreeNode *r){
    if(l == NULL && r == NULL){
        return true ; 
    }

    if(l==NULL ||  r==NULL){
        return false ; 
    }

    if(l->val != r->val){
        return false ;
    }

    bool leftcheck = checksides(l->left , r->right) ; 
    bool rightcheck = checksides(l->right , r->left) ; 

    if(!leftcheck){
        return false ; 
    }

    if(!rightcheck){
        return false ; 
}

    return true ; 
}


bool isSymmetric(struct TreeNode* root) {

  if(root == NULL){
    return true ; 
  } 


  return checksides(root->left, root->right) ;

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


    if(isSymmetric(head)){
        printf("tree is symmetric \n") ; 
    }
    else{
        printf("trees is not symmetric \n") ;
    }

    return 0 ; 
}