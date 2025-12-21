// You are given a large integer represented as an integer array digits, 
// where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. 
//  You are given a large integer represented as an integer array digits, 
// where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. 
// The large integer does not contain any leading 0's



#include <stdio.h> 
#include <stdlib.h>


int* plusOne(int* digits, int digitsSize, int* returnSize) {
     int j =0 ; 
     int count = 0 ; 

     int *new_arr1 = (int *)malloc(sizeof(int)*digitsSize) ; 
     int *new_arr2 = (int *)malloc((digitsSize+1)*sizeof(int)) ; 


      for(int i = 0 ; i<digitsSize ; i++){
        if(digits[i] == 9){
            count++ ;
        }
     }

     printf("%d \n" , count) ;

     if(count!=digitsSize){
        for(int i = digitsSize-1 ; i>=0  ; i--){
                if(digits[i]==9){
                    digits[i]= 0 ; 
                }
                else{
                    digits[i] = digits[i] + 1 ; 
                    break ; 
                }
        }


        for(int i = 0  ; i<digitsSize ; i++){
            new_arr1[i] = digits[i] ; 
        }
        *returnSize = digitsSize ; 

        return new_arr1 ; 
     }
     else{
         
        for(int i = 0 ; i<digitsSize+1 ; i++){
            if(i==0){
                new_arr2[i] = 1; 
            }
            else{
                new_arr2[i] = 0 ; 
            }
        }

        *returnSize = digitsSize+1 ; 

        return new_arr2 ; 

     }


}




int main()
{
    int digits[] = {1,1,9} ; 
    int l = sizeof(digits)/sizeof(int) ; 
    int returnsize = l; 


    int *new_arr = plusOne(digits , l , &returnsize) ;
    int l2 = sizeof(new_arr)/sizeof(int) ; 
    printf("%d \n" , l2) ;  

    for(int i = 0 ;i<returnsize; i++){
        printf("%d " , new_arr[i]) ; 
    }

    return 0 ;
}