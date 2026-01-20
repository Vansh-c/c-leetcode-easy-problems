#include <stdio.h> 
#include <stdlib.h> 



struct TreeNode {
      int val;
     struct TreeNode *left;
      struct TreeNode *right;
  };
 
int totalTilt = 0 ; 
int depthFirstSearch(struct TreeNode* root) {
    if(root == NULL){
        return 0 ; 
    }

    int leftnode = depthFirstSearch(root->left) ; 
    int rightnode = depthFirstSearch(root->right) ; 

    int tilt = leftnode - rightnode ; 

    if(tilt<0){
        tilt = -tilt ; 
    }

    totalTilt +=tilt ; 

    return root->val + leftnode + rightnode ; 
}

int findTilt(struct TreeNode* root){
    totalTilt = 0 ;
    depthFirstSearch(root) ; 
    return totalTilt ;
}

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


int main() {
 
    struct TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(9);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(7);

    int result = findTilt(root);
    printf("Total tilt = %d\n", result); 

    return 0;
}