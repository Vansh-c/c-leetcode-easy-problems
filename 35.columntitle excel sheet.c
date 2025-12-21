#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


char* convertToTitle(int columnNumber) {
char *str = malloc(100 * sizeof(char));
int i = 0 ; 


while (columnNumber > 0) {
    columnNumber--;  // adjust for 1-based indexing
    str[i++] = (columnNumber % 26) + 'A';
    columnNumber /= 26;
}
str[i] = '\0';


int len = strlen(str);
for(int j = 0; j < len / 2; j++) {
    char t = str[j];
    str[j] = str[len - j - 1];
    str[len - j - 1] = t;
}


    return str ; 
}

int main()
{

    printf("%s " , convertToTitle(28)); 



    return 0 ;
}