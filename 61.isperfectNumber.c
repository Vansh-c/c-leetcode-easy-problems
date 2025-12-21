#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 

bool isPerfectSquare(int num) {
   long long  int i = 1 ; 

    if(num==1){
        return true ; 
    }

    int j = 1 ; 

    while(i<=num){
        if(i==num){
            return true ; 
        }
        j = j+2 ; 

        i = i+j  ;
    }

    return false ;  
}





int main()
{


    if(isPerfectSquare(4)){
        printf("perfect square exist") ; 
    }
    else{
        printf("no perfect square") ; 
    }
}