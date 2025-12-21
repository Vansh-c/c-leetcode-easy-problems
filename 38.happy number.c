#include <stdio.h> 
#include <stdbool.h>

bool isHappy(int n) {
    int count = 0 ; 
    while(n!=1){

        if(n<5){
            return false ; 
        }
        int total = 0 ; 
        int r  = 0 ; 
      while(n!=0){
        r  = n%10 ; 
        total = total + r*r ; 
        n = n/10  ; 
      }

      n = total ; 
    }

    return true;  
}


int main()
{

    if(isHappy(19)){
        printf("19 is a happy number") ; 
    }
    else{
        printf("19 is not a happy number") ; 
    }


    return 0 ;      
}