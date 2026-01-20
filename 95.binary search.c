#include <stdio.h> 


int search(int* nums, int numsSize, int target) {
    int low = 0 ; 
    int high = numsSize-1 ; 

    int middle = (low + high)/2 ; 

    while(low<=high){
        if(nums[middle] == target ){
            return middle ; 
        }

        if(nums[middle] > target){
            high = middle-1 ; 
        }

        if(nums[middle]<target){
            low = middle+1 ; 
        }

        middle = (low + high)/2 ; 
    }

    if(low>high){
        return -1; 
    }

    return low ;
}


int main(){

    int arr[] = {1,2,3,4,5,6} ; 
    int l = 6 ; 
    int target = 12; 

    printf("%d" , search(arr, l , target)) ;


    return 0;
}