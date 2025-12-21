#include <stdio.h> 
#include <stdbool.h>


struct TreeNode {
      int val;
     struct TreeNode *left;
      struct TreeNode *right;
  };



int height(struct TreeNode  *root){
    if(root == NULL) return 0 ; 

    int left = height(root->left) ; 
    int right = height(root->right) ; 

    if(left == -1 || right == -1 || left-right>1 || right - left >1){
        return -1 ; 
    }

    return 1 + (left > right ? left : right) ; 
}

 
bool isBalanced(struct TreeNode* root) {
     return height(root) != -1 ; 
}


int main()
{




    return 0 ;
}