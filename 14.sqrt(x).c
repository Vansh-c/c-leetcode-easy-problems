// program to find the square root without using math function


#include <stdio.h> 


int mySqrt(int x) {
    if(x==1){
        return 1 ; 
    }

    double num = 0 ; 

    while((num*num)<=(x)){
        num++ ; 
    }


    num = (int)num ; 
    return num-1 ; 
}


int main()
{


    printf("%d" , mySqrt(2147395600)) ; 
    return 0 ;
}