#include <stdio.h> 
#include <limits.h>




int thirdMax(int* nums, int numsSize) {

    if(numsSize == 1){
        return nums[0] ; 
    }


    if(numsSize == 2){
        if(nums[0] > nums[1]){
            return nums[0] ; 
        }
        return nums[1] ; 
    }

  long long int max = LLONG_MIN; ; 
  long long int secmax = LLONG_MIN; ; 
  long long int third_max = LLONG_MIN; ; 
  int counter = 0 ;

  for(int i = 0 ; i<numsSize ; i++){
    int x = nums[i] ; 

    if(x==max || x== secmax || x == third_max){
        continue ; 
    }

    counter++ ; 

    if(x> max){
        third_max = secmax ; 
        secmax = max ; 
        max = x ; 
    }
    else if(x>secmax){
          third_max = secmax ; 
          secmax = x ; 
    }
    else if(x> third_max){
        third_max = x ; 
    }
  }

  if(counter<3){
    return max;  
  }

  return third_max ; 
 
}


int main(){

    int a[] = {2,1,2,3} ;  

    printf("the third max number = %d" , thirdMax(a ,4)) ; 


    return 0 ; 
}