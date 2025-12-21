#include <stdio.h> 
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
// My tried solution . 
//  note this fails at large test cases . O[n2] complexity . 
bool isIsomorphic(char* s, char* t) {
   int map_s_to_t[250] = {0} ; 
   int map_t_to_s[256] = {0} ; 

   for(int i = 0 ; i<strlen(s) ; i++){

    if(map_s_to_t[s[i]]==0 && map_t_to_s[t[i]]==0){
        map_s_to_t[s[i]] = t[i] ; 
        map_t_to_s[t[i]] = s[i] ; 
    }

    else{
        if(map_s_to_t[s[i]]!=t[i] || map_t_to_s[t[i]]!=s[i]){
            return false ;
        }
    }

   }

  return true ; 
}

int main()
{


    char *s = "ab" ; 
    char *t = "bb" ; 

    if(isIsomorphic(s ,t)){
        printf("isomorphic") ; 
    }
    else{
        printf("non - isomorphic") ; 
}


    return 0 ;
}