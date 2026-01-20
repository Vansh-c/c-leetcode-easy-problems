#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

char* convertToBase7(int num) {


    char *store = (char *)malloc(sizeof(char)*1000) ;
    int k = 0 ; 
    
    if(num==0){
        store[k++] = '0' ;
    }
    int base = 7  ; 
    int isnegative = 0 ; 
    if(num<0){
       isnegative = 1 ; 
       num = -num ; 
    }
    while(num!=0){

        int remainder = num%base ; 
        store[k++] = remainder + '0' ; 
        num = num/base  ; 
    }

    if(isnegative==1){
        store[k++] = '-' ;
    }

    store[k] = '\0' ; 

    for(int i = 0 ; i<strlen(store)/2 ; i++){
        char c = store[i] ; 
        store[i] = store[strlen(store) - i - 1] ; 
        store[strlen(store) - i - 1] = c ; 
    }

    return store;
}


int main(){
    

   printf("%s " , convertToBase7(-7)) ; 
}

