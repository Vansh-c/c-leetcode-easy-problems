// to make palindrome 


#include <stdio.h> 
#include <stdbool.h> 


bool isPalindrome(int x){
    int reverse = 0 ; 

    int orignal_num = x ; 
    

    while(x!=0){
        reverse = 10*reverse + x%10 ; 
        x = x/10 ; 
    }

    if(orignal_num<0){
        return false ; 
    }


    if(reverse == orignal_num){
        return true; 
    }

    else{
       return false ; 
    }
}



int main()
{


    printf("enter the number x \n") ; 
    int x ; 
    scanf("%d" , &x) ; 
    if(isPalindrome(x)){
        printf("entered number is an palindrome") ; 
    }
    else{
        printf("enter number is not an palindrome ") ;
    }
    return 0 ; 
}