#include <stdio.h> 
#include <stdbool.h>

bool isPowerOfFour(int n) {

    if(n==0){
        return false ; 
    }

    if(n==1){
        return true ; 
    }
   
   long long int num = 1 ; 

   while(num<n){
    num = num*4 ; 
  } 

  return num==n ; 
}


int main()
{

   if(isPowerOfFour(16)){
    printf("in power of 4") ;
   }
   else{
    printf("not in power of 4") ; 
   }

    return 0 ; 
}