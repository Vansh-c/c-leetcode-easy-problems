#include <stdio.h> 
#include <stdbool.h> 


bool isPowerOfThree(int n) {
   if(n==0){
    return false ; 
   }   

   if(n==1){
    return true ; 
   }

   int num = 1; 

   while(num<n){
      num = num*3 ; 
   }

   return num==n ; 

}


int main()
{

   if(isPowerOfThree(27)){
    printf("this is in powre of 3") ; 
   }
   else{
    printf("not in powr of 3") ; 
   }

    return 0 ; 
}