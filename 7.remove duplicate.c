// program to remove duplicates 

#include <stdio.h>
#include <stdlib.h>


int removeDuplicates(int* nums, int numsSize) {
    int diff_element = 0 ; 

    for(int i = 1 ; i<numsSize ; i++){
        if(nums[i]!=nums[diff_element]){
            diff_element++ ; 
            nums[diff_element] = nums[i] ; 
        }
    }

    for(int i = 0 ; i<(diff_element + 1) ; i++){
        printf("%d " , nums[i]) ;
    }


    return diff_element+1 ;  
}


int main()
{

    int a[] = {0,0,1,1,1,2,2,3,3,4} ; 
    int l = sizeof(a) / sizeof(int) ; 


    int len = removeDuplicates(a , l) ; 
    printf("\nthe new length is %d\n"  , len) ; 

    for(int i = 0 ; i<len ; i++){
        printf("%d ", a[i]) ; 
    }
    return 0 ;
}