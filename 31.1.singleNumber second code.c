#include <stdio.h> 
#include <stdbool.h>

// here we used xor operator , here xor remains while every else gets cancelled out.    

int singleNumber(int* nums, int numsSize) {

   int result = 0 ; 

   for(int i = 0 ; i<numsSize ; i++){
    result = result^nums[i] ; 
   }

   return result ; 
}


int main()
{
    int arr[]  = {4,1,2,1,2} ; 
    int size = sizeof(arr)/sizeof(int) ; 

    printf("element which is unique = %d" , singleNumber(arr,  size)) ; 


    return 0 ;
}