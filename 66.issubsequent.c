#include <stdio.h> 
#include <string.h> 
#include <stdbool.h> 


bool isSubsequence(char* s, char* t) {
   int i = 0 ; 
   int j = 0 ; 

   while(s[i]!='\0' && t[j]!='\0'){
    if(s[i] == t[j]){
        i++ ; 
    }

    j++ ; 
   }

   if(strlen(s) != i) return false ; 

   return true ; 
}

int main(){
    char s[] = "abc" ; 
    char t[] = "ahbgdc" ;

    if(isSubsequence(s ,t)){
        printf("it's subsequent") ; 
    }
    else{
        printf("not subsequent") ; 
    }


    return 0 ; 
}