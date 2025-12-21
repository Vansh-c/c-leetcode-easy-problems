#include <stdio.h> 
#include <stdbool.h>
bool containsDuplicate(int* nums, int numsSize) {
   int arr[100] = {0} ; 
   int k = 0 ; 
   
   int i = 0 ; 
   while(i<numsSize){
      k = i + 1 ; 
      while(k<numsSize){
        if(nums[i] == nums[k]){
            return true ; 
        }

        k++ ; 
      }

      i++  ; 
   }
}


int main()
{

    int a[] = {0,4,5,0,3,6} ; 

    if(containsDuplicate(a , sizeof(a)/sizeof(int))){
        printf("it contains duplicates ") ; 
    }
    else{
        printf("it's an unique array") ; 
    }


    return 0 ; 
}