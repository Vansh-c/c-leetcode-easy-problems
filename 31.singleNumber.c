#include <stdio.h> 

int singleNumber(int* nums, int numsSize) {
    int count = 0  ; 
    int elementappearedOnce ; 

    for(int i = 0 ; i<numsSize ; i++){
        count = 0 ; 
        for(int j = 0 ; j<numsSize ; j++){
               if(nums[i] == nums[j]){
                    count++ ; 
               }
        }

        if(count==1){
            elementappearedOnce = nums[i] ; 
        }
    }

    return elementappearedOnce ; 
}


int main()
{
    int arr[]  = {4,1,2,1,2} ; 
    int size = sizeof(arr)/sizeof(int) ; 

    printf("element which is unique = %d" , singleNumber(arr,  size)) ; 


    return 0 ;
}