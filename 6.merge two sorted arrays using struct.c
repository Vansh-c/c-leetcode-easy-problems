// make a program to 


#include <stdio.h> 
#include <stdlib.h>

int *merge(int *a1 , int *a2 , int l1 , int l2 , int *r); 


int main()
{
    int a1[] = {1,2,4} ; 
    int a2[] = {1,3,4} ; 

    int l1 = sizeof(a1)/sizeof(int) ; 
    int l2 = sizeof(a2)/ sizeof(int) ; 

    int total = l1 + l2 ; 

    int *r = (int *)malloc(total*sizeof(int)) ; 

    int *merge_arr = merge(a1 , a2 , l1 , l2 , r) ; 

    for(int i = 0 ; i<total ; i++){
        printf("%d " , merge_arr[i]) ; 
    }


    return 0 ; 
}

int *merge(int *a1 , int *a2 , int l1 , int l2 , int *r){

    int i = 0 ; 
    int j = 0 ; 
    int k = 0 ; 

   while(i<l1 && j<l2){
    if(a1[i]<a2[j]){
       r[k] = a1[i] ; 
       i++ ; 
       k++ ; 
    }
    else{
         r[k] = a2[j] ; 
         j++ ; 
         k++ ; 
    }
   }

        printf("%d %d  %d\n" , i , j , k);


   while(i<l1){
    r[k] = a1[i] ; 
    i++ ; 
    k++ ; 
   }


    while(j<l2){
    r[k] = a2[j] ; 
    j++ ; 
    k++ ; 
   }


   return r ; 


}
