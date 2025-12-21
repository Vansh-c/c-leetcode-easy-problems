// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.



#include <stdio.h> 
#include <stdlib.h>



int main()
{


     printf("enter value of n \n") ; 
     int n ; 
     scanf("%d" , &n) ; 

     int *nums = malloc(n*sizeof(int)) ; 

    

     for(int i = 0 ; i<n ; i++){
        printf("nums[%d] = " , i) ; 
        scanf("%d" , &nums[i]) ; 
        printf("\n") ; 
     }



     int len = n; 
     int stor[2] = {-1 , -1} ;
     int k = 0 ;
     printf("enter your target value \n") ; 
     int target ; 
     scanf("%d" , &target) ; 
     
     
     printf("the array is \n") ; 
     for(int i = 0 ; i<n ; i++){
        printf("%d " , nums[i]) ; 
     }


     printf("\n\n") ; 

     printf("the indices are \n") ; 


     for(int i = 0 ; i<len ; i++){
        for(int j = i+1;j<len ; j++){
            if((nums[i] + nums[j]) == target ){
                stor[0] = i ; 
                stor[1] =  j ; 
                break ; 

            }
        }

        if( stor[0]!= -1){
            break ; 
        }

    }


   if(stor[0]!=-1){
       for(int i = 0 ; i<2 ; i++){
        printf("%d " , stor[i]) ; 
     }
   }
   else{
    printf("boooom") ; 
   }

    return 0 ;
}

