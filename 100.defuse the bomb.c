#include <stdio.h> 
#include <stdlib.h> 

int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    int *store = (int *)malloc(sizeof(int)*codeSize) ; 

    for(int i = 0 ; i<codeSize ; i++){
        store[i] = 0 ;
    }

    int i = 0 ; 
    int p = 0 ; 
    int y =0 ; 

    while(i<codeSize){
      if(k>0){
        p  = 1 ;
        y = 0 ; 
        while(y<k){
             int index = (p+i)%(codeSize) ; 
             store[i] += code[index] ; 
             p++ ; 
             y++ ;  

        }
    }

 else if (k < 0) {
    p = i - 1;
    y = 0;

    while (y > k) {
        int index = p;

        if(p<0){
            p+=codeSize ;
        }

        if (index < 0) {
            index = codeSize - 1;
        }

        store[i] += code[index];
        y--;
        p--;
    }
}


    else if(k==0){
         y = 0 ; 
         while(y<k){
            store[i] = 0 ; 
            y++ ; 
         }
    }

    i++ ; 


}

    *returnSize = codeSize ;


    return store ;


}


int main(){
    int a[] = {5,7,1,4} ;
    int l = 4 ; 
    int returnSize ; 

    int k = -2 ; 
    int *r = decrypt(a,l , k , &returnSize) ; 

    for(int i = 0 ; i<returnSize ; i++){
        printf("%d " , r[i]) ;
    }

    return 0 ;
}