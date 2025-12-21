#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool isPalindrome(char* s) {

    for(int i = 0 ; i<strlen(s) ; i++){
        s[i] = tolower(s[i]) ; 
    }

    char *new_s = (char *)malloc(sizeof(char)*strlen(s)) ; 

    int i = 0 ; 
    int j = 0 ; 

    while(s[i]!= '\0'){
        if(!ispunct(s[i] )&& s[i]!=' '){
            s[j] = s[i] ; 
            j++;
        }
        i++ ; 
    }

    s[j] = '\0' ; 

    for(int i = strlen(s)-1 ; i>=0 ; i--){
        new_s[strlen(s) - i - 1] = s[i] ;  
    }
 



    printf("%s\n" , s) ; 
    printf("%s\n" , new_s) ; 

    for(int i = 0 ; i<strlen(s) ; i++){
        if(s[i]!=new_s[i]){
            return false ; 
        }
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