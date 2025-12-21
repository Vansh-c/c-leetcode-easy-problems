#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
      int a[26] = {0} ;  
      int b[26] = {0}; 

      if(strlen(s)!=strlen(t)){
        return false ; 
      }

      for(int i = 0  ; i<strlen(s) ; i++){
        int k = 0 ; 
        a[s[i] - 'a']++ ; 
      }

      for(int i = 0 ; i<strlen(t) ; i++){
        int k = 0 ;
        b[t[i] - 'a']++ ;  
      }

      for(int i = 0 ; i<26 ; i++){
        if(a[i]!=b[i]){
            return false ; 
        }
      }

      return true ; 
}

int main()
{

    char *s = "car" ; 
    char *t = "rat" ; 

    if(isAnagram(s,t)){
        printf("they are anagram") ; 
    }
    else{
        printf("not an anagram") ; 
    }


    return 0 ; 
}