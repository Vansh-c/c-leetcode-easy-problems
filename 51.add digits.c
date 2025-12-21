#include <stdio.h>
// this is my solution vansh joshi style. not english uncle . 

int addDigits(int num) {
    if(num==0){
        return 0 ; 
    }   


    int sum = 0  ; 

    while(num!=0 ){
         sum = sum + num%10 ; 
         num = num/10 ;

         if(num==0 && sum>=10){
            num= sum ; 
            sum = 0 ; 
         }

    }

return sum ; 
}

int main() 
{


    printf("number of digits in 567 is %d" , addDigits(567)) ; 



    return 0 ; 
}