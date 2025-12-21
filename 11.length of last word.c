// to find length of last word in c 



#include <stdio.h>
#include <string.h>



int lengthOfLastWord(char* s) {
    int i = strlen(s)-1 ; 
    int length = 0 ; 
    int found = 0 ; 
    int j = strlen(s)-1 ;

    while(i>=0){

        if(s[i]==' ' && found == 0 ){
            i-- ; 
            continue ; 
        }

        found = 1 ; 
        if(s[i]!=' '){
            length++ ; 
            i-- ; 
            continue ; 
        }

        else{
            break ; 
        }
        i-- ; 
    }

    return length; 
}


int main()
{

    char str[] = "l" ; 

    printf("%d " , lengthOfLastWord(str)) ; 


    return 0 ;
}