#include <stdio.h> 
#include <stdlib.h> 

// in recursion only top-bottom memoization possible. here we can only use bottom-top memoization.


int minCostClimbingStairs(int* cost, int costSize) {
    if(costSize==0) return 0 ;
    if(costSize==1) return cost[0]  ; 


    int dp[costSize] ;
    dp[0] = cost[0] ;
    dp[1] = cost[1] ;

    for(int i = 2 ; i<costSize ; i++){
        if(dp[i-1] < dp[i-2]){
            dp[i] = cost[i] + dp[i-1] ; 
        }
        else{
            dp[i] = cost[i] + dp[i-2] ;
        }
    }

    // u can reach top from last step or second last step . 
    if(dp[costSize-1] < dp[costSize-2]){
        return dp[costSize-1] ; 
    }
    else{
        return dp[costSize-2] ;
    }
}

int main() {
    // Example 1
    int cost1[] = {10, 15, 20};
    int n1 = sizeof(cost1)/sizeof(cost1[0]);
    printf("Minimum cost = %d\n", minCostClimbingStairs(cost1, n1)); // Output: 15

    // Example 2
    int cost2[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int n2 = sizeof(cost2)/sizeof(cost2[0]);
    printf("Minimum cost = %d\n", minCostClimbingStairs(cost2, n2)); // Output: 6

    return 0;
}