#include <stdio.h> 


void moveZeroes(int* nums, int numsSize) {
    int index =  0  ; 

    for(int i = 0 ; i<numsSize ; i++){
        if(nums[i]!=0){
            nums[index++] = nums[i] ; 
        }

    }
    
    
    while(index<numsSize){
        nums[index++] = 0 ; 
    }
}

int main()
{


    int a[] = {0,0,1} ; 

    int size = sizeof(a)/sizeof(int) ; 

     moveZeroes(a , size) ; 

    for(int i = 0 ; i<size ; i++){
        printf("%d " , a[i]) ; 
    }
    return 0 ; 
}