#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <ctype.h> 


int countSegments(char* s) {
    if(strlen(s)==0){
        return 0 ; 
    }
    int count = 0 ; 
    int i = 0 ; 

    int l = strlen(s) ; 
 

    while(i<l){

        while(i<l && s[i]==' '){
            i++ ; 
        }
        
         if(i<l){
            count++ ; 
         } 

         while(i<l && s[i]!=' '){
            i++ ; 
         }
    }

    return count ; 

}

int main()
{
    char s[] =  "    ";
    printf("%d" , countSegments(s)) ;


    return 0 ; 
}