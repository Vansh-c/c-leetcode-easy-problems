#include <stdio.h> 
#include <stdlib.h>


int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1 ; 

    int **result = (int **)malloc(sizeof(int *)*(rowIndex+1)); 

    for(int i = 0 ; i<rowIndex + 1 ; i++){
        result[i] = (int *)malloc((i+1)*sizeof(int)) ; 

        result[i][0] = 1 ; 
        result[i][i] = 1  ; 

        for(int j = 1 ; j<i; j++){
            result[i][j] =result[i-1][j-1] + result[i-1][j] ; 
        }
    }

    return result[rowIndex] ; 
}


int main()
{

    int rowIndex = 3 ; 
    int returnSize ; 

    int *a = getRow(rowIndex , &returnSize) ; 

    for(int i = 0 ; i<returnSize ; i++){
       printf("%d " , a[i]) ; 
    }


    return 0 ;
}