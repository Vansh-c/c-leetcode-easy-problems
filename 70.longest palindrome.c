#include <stdio.h> 
#include <string.h>
#include <stdbool.h>


int longestPalindrome(char* s) {
    int store[200] = {0}; 
    int i = 0 ; 

    while(s[i]!='\0'){
          store[(int)s[i]]++ ; 
          i++ ; 
    }

    int count = 0 ; 
    bool remainingOdd = 0 ; 


    for(int i = 0 ; i<200 ; i++){
        if(store[i]%2==0){
             count+= store[i] ; 
        }

        if(store[i]%2==1){
            count += store[i] -1 ; 
            remainingOdd = true ; 
        }
    }


    if(remainingOdd) return count+1;  


    return count ; 

}


int main(){
    char s[]  = "abccccdd" ; 

    printf("maximum palindrome = %d" , longestPalindrome(s)) ; 

    return  0 ;
}