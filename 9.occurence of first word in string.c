// find the occurence of first word in a given string

#include <stdio.h> 
#include <string.h>


int strStr(char *haystack , char *needle){
       haystack = strlwr(haystack) ; 
       needle = strlwr(needle) ; 
       int find = 0 ; 

       int i = 0 ; 
       int j = 0 ; 
       
       while(i<strlen(haystack)){
        int n = 0 ; 
        char c = haystack[i] ; 
        j = 0 ; 

        while(j <strlen(needle)){
            if(needle[j]!=haystack[i]){
                if(j>0){
                    i = i-j  ; 

                }
                n = 1 ; 
                break ; 
                
            }
         j++ ;  
         i++ ; 
        }

        // printf("%d " , i);

        if(n==0){
            find = i - j ; 
            printf("%d " , find) ; 
            return 0 ; 
        }
        i++ ; 
       }

       return -1 ; 
}


int main()
{
    char str1[] = "mississippi" ; 
    char str2[] = "issip" ; 
    strStr(str1 , str2) ; 
    return 0 ;
}