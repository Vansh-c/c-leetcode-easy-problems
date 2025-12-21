#include <stdio.h> 
#include <string.h> 
#include <stdbool.h> 

bool canConstruct(char* ransomNote, char* magazine) {
    int store1[26] = {0} ; 
    int store2[26] = {0} ; 


    for(int i = 0 ; i<strlen(ransomNote) ; i++){
        store1[ransomNote[i] - 'a']++ ; 
    }

    for(int i = 0 ; i<strlen(magazine) ; i++){
        store2[magazine[i] - 'a']++ ; 
    }


    int count = 0 ; 

    for(int i = 0 ; i<26 ; i++){
        if(store1[i] > store2[i]){
            return false ; 
        }
    }

   return true ; 

}


int main(){

    char s[] = "bg"; 
    char t[] = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj" ;

    if(canConstruct(s,t)){
        printf("ransomNote can be constructed") ; 
    }
    else{
        printf("ransomNote cannot be constructed")  ; 
    }
}