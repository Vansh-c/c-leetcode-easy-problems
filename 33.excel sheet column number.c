#include <stdio.h> 
#include <string.h>



int titleToNumber(char* columnTitle) {
    int count = 0 ; 
    int mult = 1; 

    if(strlen(columnTitle)==1){
        return columnTitle[0] - 'A' + 1 ;
    }

    for(int i = 0 ; i<strlen(columnTitle)/2 ; i++){
        char tmp = columnTitle[i] ; 
        columnTitle[i] = columnTitle[strlen(columnTitle) - i - 1] ; 
        columnTitle[strlen(columnTitle) - i - 1] = tmp ; 
    }

    for(int i = 0 ; i<strlen(columnTitle) ; i++){
        count = count + (columnTitle[i] - 'A' + 1)*mult ; 
        printf("%d\n" , count) ; 
        mult = mult*26 ;  
    }

    printf("%s\n" , columnTitle) ; 

    return count  ; 
}



int main()
{
    char str[] = "ZY" ; 

    printf("title number = %d" , titleToNumber(str)) ; 


    return 0 ;
}