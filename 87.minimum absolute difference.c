#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>



struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };

 struct TreeNode *createNode(int val){
    struct TreeNode *new = (struct TreeNode *)malloc(sizeof(struct TreeNode)) ; 
    new->left = NULL;  
    new->right = NULL ; 
    new->val = val ; 

    return new ; 
 }

 
int getMinimumDifference(struct TreeNode* root) {
    struct TreeNode *current = root; 


    struct TreeNode *stack[100] ; 
    int top = -1 ; 

    int min_difference = INT_MAX ; 
    struct TreeNode *prev = NULL ; 

    while(current!=NULL || top!=-1){
        while(current!=NULL){
            stack[++top] = current ; 
            current = current->left ; 
        }
    

        current = stack[top] ; 
        top-- ; 
    int value = current->val ; 


    if(prev!=NULL){
        int difference = value - prev->val ; 
       if(difference < 0){
            difference = -difference ; 
       }

       if(difference < min_difference){
        min_difference =  difference ; 
       }
    }
       
       prev = current ; 
       current = current->right ; 
    }

    return min_difference ; 

}
  
     

int main(){
    struct TreeNode *four = createNode(4) ; 
    struct TreeNode *second = createNode(2) ; 
    struct TreeNode *sixth = createNode(6) ; 
    struct TreeNode *first = createNode(1) ; 
    struct TreeNode *third = createNode(3) ;
    
    

    four->left = second ; 
    four->right = sixth  ; 

    second->left = first ; 
    second->right = third ; 

    printf("%d" , getMinimumDifference(four)) ; 



    return 0 ; 
}