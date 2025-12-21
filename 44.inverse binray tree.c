#include <stdio.h> 
#include <stdlib.h> 


 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 
 void manageSides(struct TreeNode *left, struct TreeNode *right){
     if(left!=NULL && right!=NULL){  
    int temp = left->val ; 
    left->val = right->val; 
    right->val = temp ; 

    manageSides(left->left , right->right) ; 
    manageSides(left->right , right->left) ;
} 

       
 }

struct TreeNode* invertTree(struct TreeNode* root) {
    if(root == NULL){
        return NULL ; 
    }
 

   struct TreeNode *temp = root->left ; 
   root->left = root->right; 
   root->right = temp ;

   invertTree(root->left) ; 
   invertTree(root->right) ;
   
   return root ; 

    


}


struct TreeNode *createNode(int data){
    struct TreeNode *newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode)) ; 
    newNode->val = data ; 
    newNode->left = NULL ; 
    newNode->right = NULL ; 

    return newNode ; 
}


void traversenode(struct TreeNode *root){
    if(root!=NULL){
    traversenode(root->left) ;
    printf("%d " , root->val) ; 
    traversenode(root->right) ;
    } 
}


int main()
{

    struct TreeNode *first = createNode(1) ; 
    struct TreeNode *second = createNode(2) ; 
    struct TreeNode *third = createNode(3) ; 
    struct TreeNode *four =createNode(4) ;
    struct TreeNode *fifth = createNode(5) ; 
    struct TreeNode *sixth = createNode(6) ;
    struct TreeNode *seventh = createNode(7) ; 
    struct TreeNode *eight = createNode(8) ; 
    struct TreeNode *ninth = createNode(9) ; 



    
    four->left = second ;
    four->right = seventh ; 

    second->left = first ; 
    second->right = third ; 

    seventh->left = sixth ; 
    seventh->right - ninth ; 

    traversenode(four) ; 

    four = invertTree(four) ; 
    printf("\n") ; 
    traversenode(four) ;
    

    

    first->left = second ; 
    

     


    return 0 ;
}