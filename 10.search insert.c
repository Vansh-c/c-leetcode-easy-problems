#include <stdio.h> 

int searchInsert(int* nums, int numsSize, int target) {
    int i = 0;

    while (i < numsSize) {
        if (nums[i] >= target) {
            return i;
        }

        if(target>nums[i] && i==numsSize-1){
            return numsSize; 
        }

        if(target<nums[i] && i == 0){
            return 0 ; 
        }

        
        i++;
    }

    return -1 ; 


    // If target is greater than all elements, it should be inserted at the end
}

int main() {
    int a[] = {1, 3, 5, 6};
    int target = 4;
    int size = sizeof(a) / sizeof(int);

    printf("%d\n", searchInsert(a, size, target));

    return 0;
}
