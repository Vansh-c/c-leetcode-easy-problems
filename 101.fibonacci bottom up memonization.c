#include <stdio.h>

// dynamic programming is solve the problem once , remember it and reuse it.
// dp array which is gloabl array remmebers it. 

int dp[1000] ; 
int fib(int n){
  if(n==0 || n==1) return n ; 

  dp[0] = 0 ; 
  dp[1] = 1  ;

  for(int i = 2 ; i<=n ; i++){
    dp[i] = dp[i-1] + dp[i-2] ; 
  }

  return dp[n] ;
    

}

int main()
{
    


     printf("%d", fib(10));
    return 0;


}