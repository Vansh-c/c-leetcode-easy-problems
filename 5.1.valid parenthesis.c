#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char *s)
{
    char str2[] = ")}]";
    char str1[] = "({[";
    char str3[100];
    int top = -1;
    bool check = true; 

    for (int i = 0; i < strlen(s); i++)
    {

        if((s[i] =='{' || s[i]=='[' || s[i] == '(') && s[i+1]=='\0'){
            return false ; 
        }

        if (s[i] == ' ')
        {
            continue;
        }

        if (strchr(str1, s[i]) != NULL)
        {
            str3[++top] = s[i]; 
        }
        else if (strchr(str2, s[i]) != NULL)
        {
            if (top == -1)
            {
                return false; 
            }

            char lastOpen = str3[top--];

            if ((s[i] == ')' && lastOpen == '(') || (s[i] == '}' && lastOpen == '{') ||(s[i] == ']' && lastOpen == '['))
            {
                check = true;; 
            }
            else{
                check = false ;  
            }
        }
    }

    if(check == true){
        return true ; 
    }
    else{
        return false ; 
    }
}

int main() {
    char str[] = "[()";
    if (isValid(str)) {
        printf("Valid parenthesis\n");
    } else {
        printf("Not a valid parenthesis\n");
    }

    return 0;
}
