#include <stdio.h> 
#include <string.h> 
#include <stdbool.h>

char findTheDifference(char* s, char* t) {
    bool remains_same = true ; 
    char store1[26] = {0}; 
    char store2[26] = {0}; 


    for(int i = 0 ; i<strlen(s) ; i++){
        store1[s[i]-'a']++ ; 
    }

    for(int i = 0 ; i<strlen(t) ; i++){
        store2[t[i]-'a']++ ; 
    }

    for(int i = 0 ; i<26 ; i++){
        if(store1[i] != store2[i]){
                 printf("%d\n" , i) ;
                 return  i + 'a'; 
        }
    }

    return ' ' ;  

}

int main()
{
    char str[] = "abcd" ; 
    char t[] = "abecd" ; 

    printf("%c" , findTheDifference(str, t)) ; 




    return 0 ; 
}