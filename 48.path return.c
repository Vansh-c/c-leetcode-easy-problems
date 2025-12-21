#include <stdio.h> 
#include <stdlib.h>
#include <string.h>



struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };


 struct TreeNode* createNode(int val){
    struct TreeNode *n  = (struct TreeNode *)malloc(sizeof(struct TreeNode)) ; 
    n->val = val ; 
    n->left = NULL ; 
    n->right = NULL ; 

    return n ; 
 }



 void depthFirstSearch(struct TreeNode *root, char **paths , int *returnSize,  char *path){
                     if(!root) return   ; 

                     int l = strlen(path) ;           // initally i == 0  . 
                     l+= sprintf(l+path , "%d" , root->val) ;  // appeding value to the last of the string. 
                     // sprintf appends the string and returns the number of character appends so our length l gets updated.  
                     // here , second thing it does it updates the string length at same time with appending string. 
                     // ex: "" + "1"  


                     // if leaf , store the full path. 
                     if(root->left==NULL && root->right==NULL){
                        paths[*returnSize] = malloc(l + 1) ; 
                        strcpy(paths[*returnSize], path) ; 
                        (*returnSize)++ ; 
                        return ; 
                     }

                     // add "->"  for children. 

                     path[l] = '-' ; 
                     path[l+1] = '>' ; 
                     path[l+2] = '\0' ;
                     l+=2 ; 
                     
                     int oldlen = l ; 

                     if(root->left!=NULL){
                        depthFirstSearch(root->left , paths, returnSize, path) ; 
                        path[oldlen] = '\0' ;   // backtrack .  required as when we have 1->3 , than going in root->right we will have 1->3->5->2 , as we want both to be seperate so.  which is wrong.
                        // thus , by backtracking we remove 3 and 5 , thus , when we got root->right, we have 1-> preserved.  
                     }


                     if(root->right!=NULL){
                        depthFirstSearch(root->right , paths , returnSize, path) ; 
                        path[oldlen] = '\0' ; 
                     }
 }
 

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char **arr = (char **)malloc(1000*sizeof(char *)) ; 
    char path[1000] = "" ; 
    *returnSize = 0 ; 
    depthFirstSearch(root , arr,  returnSize ,path) ;  

    return arr; 

}


int main()
{

    struct TreeNode *h1 = createNode(1) ; 
    struct TreeNode *h2  = createNode(3) ; 
    struct TreeNode *h3 = createNode(5) ; 
    struct TreeNode *h4 = createNode(2) ; 


    h1->left = h2 ; 
    h2->right = h3 ; 
    h1->right = h4; 

    int returnSize; 

    char **r =  binaryTreePaths(h1 , &returnSize) ; 

    for(int i = 0 ; i<returnSize ; i++){
        printf("%s " , r[i]) ; 
    }




    return 0 ;
}