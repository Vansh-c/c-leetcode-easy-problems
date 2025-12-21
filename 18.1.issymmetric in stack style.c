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


struct TreeNode *stack1[100] ; 
struct TreeNode *stack2[100] ; 
int top1 = -1 ; 
int top2 = -1 ; 

bool checksides(struct TreeNode *l, struct TreeNode *r) {
    while (l != NULL || r != NULL || top1 != -1 || top2 != -1) {

        // Traverse both left sides
        while (l != NULL || r != NULL) {
            if ((l == NULL && r != NULL) || (l != NULL && r == NULL)) {
                return false;
            }
            stack1[++top1] = l;
            stack2[++top2] = r;
            l = l->left;
            r = r->right;   // <-- mirror direction (left vs right)
        }

        // Pop from stack
        l = stack1[top1--];
        r = stack2[top2--];

        // Compare values
        if (l->val != r->val) {
            return false;
        }

        // Move to opposite children (mirror)
        l = l->right;
        r = r->left;
    }

    return true; // If traversal completes, tree is symmetric
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