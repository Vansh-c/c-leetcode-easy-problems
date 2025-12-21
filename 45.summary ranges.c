#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char **result = (char **)malloc(numsSize*sizeof(char *)) ;
    int k =  0  ; 
      


    for(int i = 0 ; i<numsSize; i++){
            int number = nums[i] ; 


            if(i+1==numsSize){
                   char buffer[30] ;
                sprintf(buffer , "%d" , nums[i]) ; 
                result[k++] = strdup(buffer) ; 
                continue ; 
            }

            if(i+1<numsSize && nums[i]+1 != nums[i+1]){
                char buffer[30] ;
                sprintf(buffer , "%d" , nums[i]) ; 
                result[k++] = strdup(buffer) ; 
                continue ; 
            }


            int start = nums[i] ; 
            while(i+1<numsSize && nums[i]+1 == nums[i+1] ){
                   i++ ; 
            }

            int end = nums[i] ; 
            char buffer[30] ; 
            sprintf(buffer, "%d->%d" , start , end) ; 
            result[k++] = strdup(buffer) ; 
             


    
    }

    *returnSize = k ; 

    return result ; 

}

int main()
{

    int a[] = {0,1,2,4,5,7} ;
    int numsSize ;  

    char **res = summaryRanges(a , sizeof(a)/sizeof(int) , &numsSize) ; 

    for(int i = 0 ;  i<numsSize ; i++){
             printf("%s " , res[i]) ; 
    }


    return 0 ;
}