#include <stdio.h> 

int arrangeCoins(int n) {
   long long int k = 0 ; 
   long long int i = 0 ; 
   long long int count = 0 ; 

   while(i+k+1<=n){
    k++ ; 
    count++ ; 
    i = i+k ; 
   }

   return count ; 


}


int main(){
    printf("%d" , arrangeCoins(6)) ; 

    return 0 ; 
}