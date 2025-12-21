#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* stack1[100];
struct TreeNode* stack2[100];
int top1 = -1, top2 = -1;

while ((p != NULL || top1 != -1) || (q != NULL || top2 != -1)) {
    while (p != NULL || q != NULL) {
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
            return false;
        stack1[++top1] = p;
        stack2[++top2] = q;
        p = p->left;
        q = q->left;
    }

    p = stack1[top1--];
    q = stack2[top2--];

    if (p->val != q->val)
        return false;

    p = p->right;
    q = q->right;
}

return true;



}

int main() {
    struct TreeNode *a = createNode(1);
    a->left = createNode(2);
    a->right = createNode(3);

    struct TreeNode *b = createNode(1);
    b->left = createNode(2);
    b->right = createNode(3);

    if (isSameTree(a, b))
        printf("Trees are same\n");
    else
        printf("Trees are not same\n");

    return 0;
}
