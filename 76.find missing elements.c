#include <stdio.h> 
#include <stdlib.h> 


int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int *store = (int *)malloc(sizeof(int)*(numsSize+1)) ;
    int *res = (int *)malloc(sizeof(int)*numsSize) ; 
    int k = 0 ; 

    for(int i = 0 ; i<numsSize+1 ; i++){
        store[i] = 0 ; 
    }
    
    for(int i = 0 ; i<numsSize;  i++){
        store[nums[i]]++ ; 
    }


    for(int i = 0  ; i<numsSize+1; i++){
        printf("%d " , store[i]) ; 
    }

    printf("\n") ;

    for(int i = 1 ; i<numsSize+1;  i++){
        if(store[i]== 0 ){
            res[k++] = i ; 
        }
    }

    *returnSize = k ; 

    return res ; 
}

int main(){
    int a[] = {4,3,2,7,8,2,3,1} ;
    int l = sizeof(a)/sizeof(int) ;
    int returnSize; 
    
    int *r = findDisappearedNumbers(a , l , &returnSize) ; 

    for(int i = 0 ; i<returnSize ; i++){
        printf("%d " , r[i]) ; 
    }
}