#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h> 

bool divisorGame(int n) {
    bool dp[n+1] ;

    dp[1] = false ;

    for(int i = 2 ; i<=n ; i++){
       dp[i] = false ;

       for(int d = 1 ; d<i ; d++){
        if(i%d==0){
            if(dp[i-d] == false){
                dp[i] = true ; 
                break; 
            }
        }
       }
    }


    return dp[n] ;
       
    }



int main(){

    if(divisorGame(27)){
        printf("Alice wins") ;
    }
    else{
        printf("bobbo wins") ;
    }

    return 0;
}