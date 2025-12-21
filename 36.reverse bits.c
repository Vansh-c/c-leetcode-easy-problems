#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

unsigned int reverseBits(unsigned int n) {
    int size = 33 ; 
    char *str = malloc(size*sizeof(char)) ; 
    int i = 0 ; 
    while(n!=0){
        if(n%2==0){
            str[i++] = '0' ; 

        }
        else{
            str[i++] = '1' ; 
        }

        n = n/2 ; 
    }
    
    while(i<32){
        str[i++] = '0' ; 
    }

    str[i] = '\0' ; 

    int len = strlen(str) ; 
    printf("%s \n" , str) ; 

    for(int i = 0 ; i<len/2 ; i++){
        char t = str[i] ; 
        str[i] = str[len - i - 1] ; 
        str[len - i - 1] = t ; 
    }

    int total = 0 ; 
    int ones = 1 ; 

    for(int i = 0 ; i<32 ; i++){
        if(str[i] == '1'){
              total = total + ones ; 
        }
        ones = ones*2 ; 
    }

    return total ; 
}

int main()
{

    int num = 2147483644 ; 

    printf("%d" , reverseBits(num)) ; 

    return 0 ;
}