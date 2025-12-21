#include <stdio.h>

void sort(int *a , int size){
    for(int i = 0 ; i<size ; i++){
        for(int j = i ; j<size ; j++){
            if(a[j]<a[i]){
                int t = a[i] ; 
                a[i] = a[j] ; 
                a[j] = t ; 
            }
        }
    }
}

int missingNumber(int* nums, int numsSize) {
    int element ; 

    sort(nums , numsSize) ; 

    // for(int i = 0 ; i<numsSize ; i++){
    //     printf("%d " , nums[i])  ; 
    // }

    for(int i = 0 ; i<numsSize ; i++){
        if(nums[i]!=i){
            element = i ; 
            break ; 
        }
    }

    return element ; 
}


int main()
{


    int a[] = {3,0,1} ; 
    int size = sizeof(a)/sizeof(int) ; 
    printf("missing number = %d" , missingNumber(a , size)) ; 

    return 0 ; 
}