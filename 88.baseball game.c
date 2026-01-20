#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int makeInteger(char *s){
    int negative = 0 ; 
    int  sum = 0 ; 
    int i = 0 ; 

    while(s[i]!='\0'){
        if(s[i]=='-'){
            i++ ; 
            negative = 1 ;
            continue ; 
        }
        sum = sum*10 + (s[i]-'0') ; 
        i++ ; 
    }

    if(negative==1){
        return -sum ; 
    }

    return sum ;
}


int calPoints(char** operations, int operationsSize) {
   int stack[1000] ; 
   int top = -1;  

   int i = 0   ; 

   while(i<operationsSize){
    char *st = operations[i] ; 

    if(strcmp(st , "C")==0){
        top-- ; 
    }

    else if(strcmp(st , "D")==0){
        int value = stack[top] ;
        stack[++top] = 2*value ; 
    }

    else if(strcmp(st , "+")==0){
        int total = 0;
        int firstelement = stack[top] ; 
        int secondelement = stack[top-1] ; 

        total = firstelement + secondelement ; 
        stack[++top] = total ;  
    }
    else{
        stack[++top] = makeInteger(st) ;
    }

    i++ ;
   }

   int sum = 0 ; 

   while(top!=-1){
    printf("%d " , stack[top]);
    sum+= stack[top--] ;
   }

   printf("\n") ;

   return sum ;


}




int main(){
    printf("%d\n" , makeInteger("-14")) ;

    char *s[] = {"5","2","C","D","+" } ; 

    int l = 5 ; 

    printf("baseball score = %d" , calPoints(s , l)) ;


}