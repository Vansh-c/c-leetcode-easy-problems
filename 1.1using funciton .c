
#include <stdio.h> 
#include <stdlib.h>


int *twosum(int *nums , int sizenum , int target){
        int *store = malloc(2*sizeof(int)) ; 

        for(int i = 0 ; i<sizenum ; i++){
            for(int j = i + 1 ; j<sizenum ; j++){
                  if((nums[i] + nums[j]) == target ){
                  store[0] = i ; 
                  store[1] = j ; 
                  return store ;
                  }
            }

}

return NULL ; 
}



int main(){


    printf("enter value of n \n") ; 
    int n ;
    scanf("%d" , &n) ; 

    int *nums = (int *)malloc(n*sizeof(int)) ; 

    printf("the array is below \n") ; 
    for(int  i = 0 ; i<n ; i++){
        printf("nums[%d] = " , i) ;
        scanf("%d", &nums[i]) ;  
    }


        for(int  i = 0 ; i<n ; i++){
       printf("%d " , nums[i]) ;   
    }

    int target ; 
    printf("enter the value of target \n") ; 
    scanf("%d" , &target) ; 


    int *newarr =  twosum(nums , n  , target) ; 


    if(newarr == NULL){
        printf("try again") ;
}
else{
    printf("%d %d" , newarr[0] , newarr[1]) ; 
}

    free(nums) ; 

    





    return 0 ; 
}