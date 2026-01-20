#include <stdio.h>

// dynamic programming is solve the problem once , remember it and reuse it.
// dp array which is gloabl array remmebers it. 
// this is top down  approach this is recursion based . 
int dp[1000] ; 
int lock = 1 ; 

int fib(int n){ 

    if(lock==1){
        for(int i = 0 ; i<1000 ; i++){
        dp[i] = -1 ; 
    }
    lock = 0 ;
    }

  if(n==0 || n==1){
    return n ; 
  }

  if(dp[n]!=-1){    // already completed.
    return dp[n] ; 
  }

  dp[n] = fib(n-1) + fib(n-2) ; 
  return dp[n] ;


}

int main()
{
    


     printf("%d", fib(10));
    return 0;


}