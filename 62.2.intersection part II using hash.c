#include <stdio.h> 
#include <stdlib.h> 


int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *hash = (int *)malloc(sizeof(int)*1000) ; 
    int *arr = (int *)malloc(sizeof(int)*1000) ; 
    *returnSize = 0 ; 

    for(int i = 0 ; i<nums1Size ; i++){
        hash[nums1[i]] = 1; 
    }

    for(int i = 0 ; i<nums2Size ; i++){
        if(hash[nums2[i]==1]){
            arr[(*returnSize)++] = nums2[i] ; 
            hash[nums2[i]] = 0 ; 
        }

    }

    free(hash) ;

    return arr ; 
}


int main()
{


    int a1[] = {1,1,2,3,4,5,6,7,6} ; 
    int a2[] = {1,4,6} ; 
    int returnSize ; 

    int *r = intersection(a1 , sizeof(a1)/4 , a2  , sizeof(a2)/4 , &returnSize) ; 

    for(int i = 0 ; i<returnSize ; i++){
        printf("%d " , r[i]) ; 
    }
}