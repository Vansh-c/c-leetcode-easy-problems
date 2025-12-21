#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 

char* addStrings(char* num1, char* num2) {
    if(strcmp(num1 , "0")==0 && strcmp("0" , num2)==0){
        return "0" ;
    }


    char *res = (char *)malloc(1000*sizeof(char)) ; 
    int k = 0 ;  

    int i = strlen(num1) -1 ; 
    int j = strlen(num2) -1 ; 

    int carry =0 ; 

    while(i>=0 || j>=0 || carry){
        int n1 , n2 ;
       if(i>=0){
            n1 = num1[i--] - '0' ; 
       } 
       else{
        n1 = 0 ; 
       }


       if(j>=0){
        n2 = num2[j--] - '0' ; 
       }
       else{
        n2 = 0  ; 
       }


       int sum = n1 + n2 + carry ; 
       res[k++] = sum%10 + '0' ; 
       carry = carry/10 ; 
    }

    res[k] = '\0' ; 

    for(int i = 0 ; i<strlen(res)/2 ; i++){
        char c = res[i] ; 
        res[i] = res[strlen(res) - i - 1] ; 
        res[strlen(res) -1-i] = c ; 
    }


    return res ;  
}

int main()
{

    char *r = addStrings("3876620623801494171" , "6529364523802684779") ;
    printf("%s" , r) ; 
    

    return 0 ; 
}