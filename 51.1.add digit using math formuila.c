#include <stdio.h>
// this is my solution vansh joshi style. not english uncle . 

int addDigits(int num) {
    if(num==0){
        return 0 ; 
    }   



return 1 + (num-1)%9 ; 
}

int main()
{


    printf("number of digits in 567 is %d" , addDigits(567)) ; 



    return 0 ; 
}