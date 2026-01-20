#include <stdio.h> 
#include <stdbool.h>
#include <string.h>

bool repeatedSubstringPattern(char* s) {
    bool isrepeated = true ; 

    if(strlen(s)==1 || strlen(s)==0){
        return true ; 
    }

    int hash[26] = {0} ; 
    int l = 1 ; 

    int first_character = s[0] ; 
    hash[s[0] - 'a'] = 1 ; 

    int i = 1 ; 
    while(s[i]!='\0' && s[i]!=first_character){
        hash[s[i] - 'a'] = 1 ; 
        i++ ; 
        l++ ; 
    }

    printf("%d" , i) ;


    while(s[i]!='\0'){
        if(hash[s[i]-'a'] == 0){
            printf("\n%c\n", s[i]) ;
            return false ; 
        }
        i++ ; 
    }

    if(i%l !=0) return false; 

    return  true ; 
}

int main()
{

    char str[] = "abcabcabc" ; 

    if(repeatedSubstringPattern(str)){
        printf("string is repeated") ; 
    }
    else{
        printf("not in  repeateed string pattern") ;
    }
}