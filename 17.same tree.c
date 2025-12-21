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



bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    
    if (p == NULL && q == NULL) return true;  // both NULL → fine
    if (p == NULL || q == NULL) return false; // one NULL → mismatch
    if (p->val != q->val) return false;      // values differ → mismatch

    // recurse left and right
    if (!isSameTree(p->left, q->left)) return false;
    if (!isSameTree(p->right, q->right)) return false;

    return true;  // everything matches
}
 

         



int main()
{

    struct TreeNode *head =createNode(1) ; 
    struct TreeNode *second = createNode(2) ; 
    struct TreeNode *third = createNode(3) ; 

    second->left = third ; 
    second->right = head ; 


    struct TreeNode *head1 = createNode(1) ; 
    struct TreeNode *second1 = createNode(2) ; 
    struct TreeNode *third1 = createNode(3) ; 

    second1->left=  head1 ; 
    second->right = third1 ; 


    if(isSameTree(second , second1)){
        printf("nodes are same") ; 
    }
    else{
        printf("trees are not same") ; 
    }






    return 0 ; 
}