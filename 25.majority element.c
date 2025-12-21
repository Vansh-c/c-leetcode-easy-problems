#include <stdio.h> 

// notes : this works only for an array having major element more than (n/2) , where n = length of array. 
// below code works , example : {1,1,2,2,2,2,3,3,2} , now here , count is 0 so , candidate becomes 1  than count++ happens and value  of count becomes 2 . 
// now after this , when 2 comes count--  , count becomes 1 and than 0 and than going forward it becomes 2 , now 3 comes count-- , than 2 than count++ finally ount  becomes 1 and 2 is returned. 
int majorityElement(int* nums, int numsSize) {
     int count = 0 ; 
     int majorElement = 0 ; 

     for(int i = 0 ; i<numsSize ; i++){
        if(count == 0){
            majorElement = nums[i] ; 
        }

        if(nums[i] == majorElement){
            count++  ; 
        }
        else{
            count-- ; 
        }
     }

     return majorElement ; 
}

int main()
{

    int a[] = {3,2,3} ; 

    printf("majorelement = %d" , majorityElement(a , sizeof(a)/4)) ; 



    return 0 ;
}