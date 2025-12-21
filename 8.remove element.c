// this is an program to remove an element 


#include <stdio.h> 

int removeElement(int* nums, int numsSize, int val) {
    int remained = 0 ; 

    for(int i = 0 ; i<numsSize ; i++){
        if(nums[i]!=val){
            nums[remained] = nums[i] ; 
            
            remained++ ; 
    }
    }

    for(int i = 0 ; i<remained ; i++){
        printf("%d " , nums[i]);
    }

    return remained; 
}



int main()
{
  int a[] = {0,1,2,2,3,0,4,2} ; 
  printf("%d" , removeElement(a , sizeof(a)/4,2) ); 

    return 0 ;
}