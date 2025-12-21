// program to add binary 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* addBinary(const char* a, const char* b) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    int maxLen = (len1 > len2 ? len1 : len2) + 2;

    char *result = (char*)malloc(maxLen);
    result[maxLen - 1] = '\0';

    int carry = 0, i = len1 - 1, j = len2 - 1, k = maxLen - 2;

    while (i >= 0 || j >= 0 || carry) {
        int bit1 = (i >= 0) ? a[i--] - '0' : 0;
        int bit2 = (j >= 0) ? b[j--] - '0' : 0;

        int sum = bit1 + bit2 + carry;
        result[k--] = (sum % 2) + '0';
        carry = sum / 2;
    }

    // Copy the final result into a new buffer
    char* finalResult = strdup(result + k + 1);
    free(result);  // Now safe

    return finalResult;
}


int main()
{
    char a[] = "1010" ; 
    char b[] = "1011" ; 

    char *s = addBinary(a, b) ; 
    printf("%s" , s) ;

    return 0 ;
}