#include <stdio.h> 
#include <stdbool.h>

bool canWinNim(int n) {
    if(n<=3){
        return true ; 
    }

    int toggle = 0;  
    while(n-3>0){
 
        if(toggle == 0){    
            toggle = 1 ; 
            n = n-1 ; 
        }
        else{
            toggle = 0 ; 
            n = n-3 ;
        }
        
    }


    if(n>=0 && toggle == 1){
        return false ; 
    }



   return true;  
}


int main()
{


    if(canWinNim(5)){
        printf("i won") ; 
    }
    else{
        printf("I failed"); 
    }
    return 0;
}