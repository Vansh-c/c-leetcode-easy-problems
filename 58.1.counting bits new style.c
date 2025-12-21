#include <stdio.h> 
#include <stdlib.h>


int* countBits(int n, int* returnSize) {
    int *a = (int*)malloc((n+1) * sizeof(int));
    *returnSize = n + 1;

    a[0] = 0;

    for (int i = 1; i <= n; i++) {
        a[i] = a[i >> 1] + (i & 1);
    }

    return a;
}


int main()
{
     int size ; 
     int *a = countBits(5 , &size) ; 

     for(int i = 0 ; i<a ; i++){
        printf("%d " , a[i]) ; 
     }



    return 0 ; 
}
