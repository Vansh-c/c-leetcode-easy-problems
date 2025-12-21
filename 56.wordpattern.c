#include <stdio.h> 
#include <stdbool.h> 
#include <stdlib.h>
#include <string.h>

bool wordPattern(char* pattern, char* s) {
    char store[1000][1000];  // store words
    int u = 0;  // word index
    int r = 0;  // char index
    int k = 0;  // string index

    while (s[k] != '\0') {
        if (s[k] != ' ') {
            store[u][r++] = s[k];
        } else {
            store[u][r] = '\0';
            u++;   // move to next word
            r = 0;
        }
        k++;
    }
    store[u][r] = '\0';  // terminate the last word
    u++;                  // total words

    int numWords = u;

    if (numWords != strlen(pattern)) {
        return false;
    }

    char *map[26];
    for (int i = 0; i < 26; i++) map[i] = NULL;
                 // to check that  if any other letter already maps to this word
    for (int i = 0; i < numWords; i++) {
        int idx = pattern[i] - 'a';

        if (map[idx] == NULL) {
            for (int j = 0; j < 26; j++) {
                if (map[j] && strcmp(map[j], store[i]) == 0)
                    return false;
            }
            map[idx] = store[i];   // assign mapping. 
        } else {
            if (strcmp(map[idx], store[i]) != 0)
                return false;
        }
    }

    return true;
}



int main()
{


     char *s = "aa aa aa aa" ; 
     char *pattern = "aaa" ; 

     if(wordPattern(pattern , s)){
        printf("pattern matches")  ; 
     }
     else{
        printf("pattern do not matches") ; 
     }



    return 0 ;
}