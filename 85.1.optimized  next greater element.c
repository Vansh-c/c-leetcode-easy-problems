#include <stdio.h>
#include <stdlib.h> 

int* nextGreaterElement(int* nums1, int nums1Size,int* nums2, int nums2Size,int* returnSize) {

    int *r = (int *)malloc(sizeof(int) * nums1Size);
    *returnSize = nums1Size;

    int stack[100];
    int top = -1;

    int nextGreatElement[1000];
    for(int i = 0; i < 1000; i++) {
        nextGreatElement[i] = -1;
    }

    // Build next greater map
    for(int i = 0; i < nums2Size; i++) {
        while(top != -1 && stack[top] < nums2[i]) {  
            nextGreatElement[stack[top]] = nums2[i];
            top--;
        }
        stack[++top] = nums2[i];
    }

    // Answer nums1 queries
    for(int i = 0; i < nums1Size; i++) {
        r[i] = nextGreatElement[nums1[i]];
    }

    return r;
}

int main() {
    int a[] = {4, 1, 2};
    int b[] = {1, 3, 4, 2};

    int sizea = sizeof(a)/sizeof(int);
    int sizeb = sizeof(b)/sizeof(int);
    int returnSize;

    int *res = nextGreaterElement(a, sizea, b, sizeb, &returnSize);

    for(int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }

    return 0;
}
