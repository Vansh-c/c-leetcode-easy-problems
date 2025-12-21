#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

char** fizzBuzz(int n, int* returnSize) {
    char **s = (char **)malloc(sizeof(char *)*10000) ; 
    int k = 0 ; 
    *returnSize = 0 ; 


    for(int i = 1 ; i<=n ; i++){
         s[k] = (char*)malloc(sizeof(char)*100) ; 

         if(i%3==0 && i%5==0){
               sprintf(s[k] , "%s" , "FizzBuzz") ; 
         }
         else if(i%5==0){
            sprintf(s[k] , "%s" , "Buzz") ; 
         }
         else if(i%3==0){
            sprintf(s[k] , "%s" ,"Fizz") ; 
         }
         else{
            sprintf(s[k] , "%d" , i) ; 
         }


         k++ ; 
    }

    *returnSize = k ; 
    return s ; 

}
    

int main(){

     int returnSize; 
     char **result = fizzBuzz(20 , &returnSize) ; 

     for(int i = 0 ; i<returnSize ; i++){
        printf("%s " , result[i] ) ;
     }


    return 0 ; 
}