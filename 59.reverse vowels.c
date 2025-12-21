#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>


char* reverseVowels(char* s) {
    
    int i = 0 ; 
    int j = strlen(s)-1 ; 

    while(i<j){

        while(tolower(s[i])!='a' && tolower(s[i])!='e' && tolower(s[i])!='i' && tolower(s[i])!='o'   && tolower(s[i])!='u'){
            i++ ; 
            if(i==strlen(s) || i>j) {
                break ; 
            }
        }

        while(tolower(s[j])!='a' && tolower(s[j])!='e' && tolower(s[j])!='i' && tolower(s[j])!='o'   && tolower(s[j])!='u'){
            j-- ; 
            if(j==0 || i>j){
                break  ;
            }
        }

        if(i>j) break ; 

        char t = s[i] ; 
        s[i] = s[j] ; 
        s[j]= t ;


        i++ ; 
        j-- ; 
    }

    printf("%s\n" , s);

    return s ; 
}  

int main()
{


    char s[]  = "IceCreAm" ; 

    char *s2 = reverseVowels(s) ; 

    printf("%s" , s2) ;


    return 0 ; 
}