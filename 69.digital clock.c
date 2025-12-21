#include <stdio.h>
#include <stdlib.h> 



int countBits(int n){
    int  bit_num = 0  ; 
    while(n>0){
        bit_num = bit_num + n%2 ;
        n = n/2 ; 

    }

    return bit_num ; 
}


char** readBinaryWatch(int turnedOn, int* returnSize) {
    char **r  = (char**)malloc(sizeof(char*)*720) ; 
    int k = 0; 

    for(int hour = 0 ; hour<12 ; hour++){
        for(int min = 0 ; min<60  ; min++){
            if(countBits(hour) + countBits(min) == turnedOn){
                r[k] = (char*)malloc(6*sizeof(char)); 

                sprintf(r[k] , "%d : %d" , hour , min) ; 
                k++ ; 
            }
        }
    }

    *returnSize =  k ; 



    return r ; 
}


int main(){
    
    
    int returnSize  ;
    char **res  = readBinaryWatch(1 , &returnSize ) ; 

    for(int i = 0 ; i<returnSize ; i++){
        printf("%s \n" , res[i]) ; 
    }

    return 0 ;
}