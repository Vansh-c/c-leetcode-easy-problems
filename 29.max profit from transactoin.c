#include <stdio.h> 
#include <limits.h>


int maxProfit(int* prices, int pricesSize) {
    int lowest_price = INT_MAX ; 
    int maxprofit = 0 ; 

    for(int i = 0 ; i<pricesSize ; i++){
             if(lowest_price> prices[i]){
                lowest_price = prices[i] ; 
             }
             else if(prices[i] - lowest_price > maxprofit){
                maxprofit = prices[i] - lowest_price ; 
             }

            }
            
            
            return maxprofit ; 
 
}

int main()
{

    int prices[] = {2,  4,  1} ; 

    printf("profit = %d"  , maxProfit(prices , sizeof(prices)/ sizeof(int))) ; 


    return 0;
}