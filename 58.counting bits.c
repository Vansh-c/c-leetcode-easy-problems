#include <stdio.h> 
#include <stdlib.h> 

int makingcount(int n){ ; 
    int count  = 0 ; 
    while(n>0){
        if(n%2==1){
       count++ ;
        }

        n = n/2 ; 
    }

    return count ; 
}

int* countBits(int n, int* returnSize) {
    int *a = (int *)malloc(sizeof(int)*(n+1)) ; 
    *returnSize = 0 ; 


    for(int i =0 ; i<=n ; i++){
        int r = makingcount(i); 
        a[(*returnSize)++] = r ; 
    }


    return a ; 
}


int main()
{
    int size ; 

     int *a = countBits(5 , &size) ; 

     for(int i = 0 ; i<size ; i++){
            printf("%d " , a[i]) ; 
     }

    

    return 0 ; 
}