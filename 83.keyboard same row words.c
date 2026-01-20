#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>


char** findWords(char** words, int wordsSize, int* returnSize) {
    char *row1= "qwertyuiop"; 
    char *row2 = "asdfghjkl" ;
    char *row3 = "zxcvbnm" ;
    int check1 = 1  ;
    int check2 = 1 ; 
    int check3= 1; 

    int store1[26] = {0} ; 
    int store2[26]  = {0};
    int store3[26]  = {0};
    char **r = (char **)malloc(sizeof(char *)*wordsSize) ;
    int k = 0 ;

    // now storing each element in this above hash table .
    for(int i = 0 ; i<strlen(row1) ; i++){
        store1[row1[i]-'a'] = 1 ; 
    }

    for(int i = 0 ; i<strlen(row2) ; i++){
        store2[row2[i] - 'a'] = 1 ;
    }

    for(int i = 0 ; i<strlen(row3) ; i++){
        store3[row3[i] - 'a'] =1; 
    }

    // checking for each row . 

    for(int i = 0 ; i<wordsSize; i++){
           check1 =1 ;
           check2 = 1 ; 
           check3 =  1 ;
            
           int j = 0 ; 
           while(words[i][j]!='\0'){
            char p  = tolower(words[i][j]) ; 

            if(store1[p-'a']!=1){
                check1 = 0 ; 
            }

            if(store2[p-'a']!=1){
                check2 = 0 ; 
            }

            if(store3[p-'a']!=1){
                check3 = 0;
            }

            j++ ; 
           }

           if(check1 || check2 || check3){
            r[k] = (char *)malloc(strlen(words[i]) + 1);
            strcpy(r[k], words[i]);
            k++;
           }

        
    }

    *returnSize = k; 
    
    return r;

}


int main(){

    char *words[] = {"Hello","Alaska","Dad","Peace"} ; 
    int l = 4 ; 
    int returnSize ;
    char **result = findWords(words , l , &returnSize) ;

    for(int i = 0 ; i<returnSize ; i++){
        printf("%s " , result[i]) ;
    }



    return 0;
}