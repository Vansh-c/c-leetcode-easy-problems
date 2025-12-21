#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <string.h>

bool ismapped(char *s , char *s2){
      int a1[26] = {-1} ; 
      int a2[26] = {-1} ; 

     for(int i = 0 ; i<26 ; i++){
        int p = s[i] - 'a' ; 
        int c = s2[i] - 'a' ; 


        if(a1[i]==-1 && a2[i]==-1){
            a1[p] = c;
            a2[c] = p;
        }

        if(a1[p]!=c || a2[c]!=p){
            return false ; 
        }
     }

      return true ; 
}

int main()
{


    char *s = "aba" ; 
    char *s2 = "cei" ; 

    if(ismapped(s , s2)){
        printf("mapping is correct") ; 
    }
    else{
        printf("mapping is not correct") ; 
    }

    return 0 ; 
}