#include <stdio.h> 


int divide(int dividend, int divisor) {
    long long int count = 0 ; 
    long long int sum = divisor; 


     long long int origDiv = divisor  ; 
     long long int origDend = dividend ; 

     int negative = 0 ; 
     if(origDiv^origDend){
            negative = 1 ; 
     }


     if(origDend<0){
        origDend = -origDend ; 
     }

     if(origDiv<0){
        origDiv = -origDiv ; 
     }

     while(origDend >= sum){
        count++ ; 
        sum+= origDiv;  
     }

     if(negative){
        count = -count ;
     }

    return count ; 
}


int main()
{

    printf("10 divided by three = %d" , divide(-2147483647 , -3)) ; 



    return  0 ; 
}