#include <stdio.h> 
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
// My tried solution . 
//  note this fails at large test cases . O[n2] complexity . 
bool isIsomorphic(char* s, char* t) {
    char store[strlen(s)] ; 
    int k = 0 ; 
    char mapped[strlen(s)]  ; 
    for(int i = 0 ; i<strlen(s) ; i++){
            k = 0 ; 

            while(k<i && i<strlen(s)){
                
                if(s[i]== store[k]){
                    if(t[i] != mapped[k] ){
                        return false ;
                    }
                }

                if(t[i] == mapped[k]){
                    if(s[i]!=store[k]){
                        return false;
                    }
                }
                k++ ; 
            }
    
            store[k] = s[i] ; 
            mapped[k++] = t[i]  ;
    }

    return true; 
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