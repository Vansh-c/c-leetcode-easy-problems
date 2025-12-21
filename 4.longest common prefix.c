#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char **strs, int strsSize) {
    if (strsSize == 0) return "";
    
   
    if (strlen(strs[0]) == 0) return "";

    char *news = (char *)malloc(strlen(strs[0]) + 1);
  
    
    int j = 0;
    while (strs[0][j] != '\0') {
        char c = strs[0][j];

        for (int i = 1; i < strsSize; i++) {
     
            if (strs[i][j] == '\0' || strs[i][j] != c) {
                news[j] = '\0'; 
                return news;
            }
        }

   
        news[j] = c;
        j++;
    }

    news[j] = '\0';  
    return news;
}

int main() {
    char *strs1[] = {"flower", "flow", "flight"};
  

    printf("Test 1: %s\n", longestCommonPrefix(strs1, 3));  // Expected: "fl"


    return 0;
}
