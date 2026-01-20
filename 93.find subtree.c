#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>



struct TreeNode {
      int val;
     struct TreeNode *left;
      struct TreeNode *right;
  };

bool isSameTree(struct TreeNode *p , struct TreeNode *q){
    if(p==NULL && q==NULL){
        return true ; 
    }

    if(p==NULL || q==NULL){
        return false ; 

    }

    if(p->val != q->val){
        return false ; 
    }

   if( !isSameTree(p->left , q->left)) return false  ;
    if(!isSameTree(p->right , q->right)) return false ; 

    return true ;
}
 
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    struct TreeNode *current = root  ;
    struct TreeNode *stack[1000] ; 
    int top = -1;  

    while(current!=NULL || top!=-1){
        while(current!=NULL){
            stack[++top] = current ; 
            current = current->left ; 
        }

        current = stack[top--] ; 
        
        if(current->val == subRoot->val){
            if(isSameTree(current , subRoot)){
                return true ;
            }
        }

        current = current->right ;
    }

    return false ;
}


struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


int main() {

    struct TreeNode *first = newNode(1) ;
    struct TreeNode *second = newNode(2) ;
    struct TreeNode *third = newNode(3) ; 
    struct TreeNode *fourth = newNode(4) ; 
    struct TreeNode *fifth = newNode(5) ;

    struct TreeNode *sec_four = newNode(4) ; 
    struct TreeNode *sec_first = newNode(1) ;
    struct TreeNode *sec_second = newNode(2) ; 

    third->left = fourth ; 
    third->right = fifth ; 
    fourth->left = first ; 
    fourth->right = second ; 

    sec_four->left = sec_first ; 
    sec_four->right = sec_second ;

    if(isSubtree(third , sec_four)){
        printf("Subtree exists") ;
    }
    else{
        printf("No subtree exists") ;
    }


    return 0;
}