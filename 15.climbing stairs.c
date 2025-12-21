//  program to climb stairs .  

#include <stdio.h>

int climbStairs(int n) {
    if(n<=1){
        return n ; 
    }

    double a = 1 ; double b = 1 ; double tmp ; 


    for(int i = 0; i<n ; i++){
            tmp = a+b ; 
            b = a ; 
            a = tmp ; 
    }

    b = (int)b;


    return b ; 
}


int main()
{
    

    printf("%d" , climbStairs(45)) ; 
    return 0 ;
}