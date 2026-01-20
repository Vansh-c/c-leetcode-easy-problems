#include <stdio.h> 
#include <stdlib.h> 



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
 

int* findMode(struct TreeNode* root, int* returnSize) {
    struct TreeNode *stack[10000] ; 
    int top = -1;  
    *returnSize = 0 ;

    int *r = (int *)malloc(sizeof(int)*10000) ; 

    struct TreeNode *current = root ; 
    int maxcount = 0 ; 
    int previouselement = 0 ; 
    int count = 0 ; 
    int currentelement = 0 ; 
    int startingTrigger = 1 ;   // this is for to start running program

    while(current!=NULL || top!=-1){
        while(current!=NULL){
            stack[++top] = current ; 
            current = current->left ; 
        }

        current = stack[top--] ; 
        currentelement = current->val ; 

        if(startingTrigger == 1){
            startingTrigger = 0 ; 
            count = 1 ; 
        }
        else if(currentelement == previouselement){
            count++ ; 
        }
        else{
            count = 1 ; 
        }

        if(count> maxcount){
            maxcount = count ; 
        }

          previouselement = currentelement ;

        current = current->right ; 
    }


    top = -1 ; 
    currentelement = 0 ; 
    previouselement = 0 ; 
    count = 0 ; 
    startingTrigger = 1 ; 
    current = root ; 

    while(current!=NULL || top!=-1){
        while(current!= NULL){
            stack[++top] = current; 
            current = current->left ; 
        }

        current = stack[top--] ; 
        currentelement  = current->val ; 

        if(startingTrigger==1){
            startingTrigger = 0  ; 
            count = 1 ; 
        }
        else if(currentelement == previouselement){
            count++ ;  
        }
        else{
            count = 1 ; 
        }

        if(count== maxcount){
            r[(*returnSize)++] = currentelement ; 
        }

          previouselement = currentelement ;

          current = current->right ; 
    }

    return r ; 
}

int main(){
    struct TreeNode *head = createNode(1) ; 
    struct TreeNode *second = createNode(2) ; 
    struct TreeNode *second2 = createNode(2) ; 

    head->right = second ; 
    second->left = second2 ; 

    int size ; 

    int *arr = findMode(head , &size) ; 


    for(int i = 0 ; i<size ; i++){
        printf("%d " , arr[i]) ;
    }


    return 0 ; 
}