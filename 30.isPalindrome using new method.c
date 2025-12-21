#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char* s) {

    int left = 0 ;
    int right = strelen(s) - 1 ; 

    while(left!=right){
        while(left<right && !isalnum(s[left])){
            left++ ; 
        }

        while(left<right && isalnum(s[right])){
            right-- ; 
        }

        if(tolower(s[left])!= tolower(s[right])){
            return false;  
        }

        left++ ; 
        right-- ; 
    }

    return true;  



}

int main()
{
    char s[] = "race a car" ; 


   if(isPalindrome(s)){
    printf("given string is an palindrome") ; 
   } 
   else{
    printf("given string  is not an palindrome ") ; 
   }




    return 0 ;
}