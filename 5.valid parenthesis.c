// to see if the given parenthesis is valid or not
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char *s)
{

    char str2[] = ")}]";
    char str1[] = "({[";
    int k = 1;
    bool check = false ; 

    for (int i = 0; i < strlen(s); i++)
    {

        if (s[i] == ' ')
        {
            k++;
        }

                    
        if ((strchr(s, str2[i]) != NULL) && (strchr(str1 ,s[i]) != NULL))
        {

           check = true; ;
        }

      

        if (s[i] == '[' && (s[k] == '{' || s[k] == '(')&& (s[k+1]!='}' || s[k+1]!=')') && s[k] != '\0')
        {
            return false;
        }

        if (s[i] == '{' && (s[k] == '(' || s[k] == '[') && (s[k+1]!=']' || s[k+1]!=')') && s[k] != '\0')
        {
            return false;
        }

          if (s[i] == '(' && (s[k] == '{' || s[k] == '[') && (s[k+1]!='}' || s[k+1]!=']')&& s[k] != '\0')
        {
            return false;
        }

    

        k++ ; 
    }

    printf("%d" , k);

if(check){
    return true;  
}
else{
    return false;
}
}

int main()
{

    char str[] =  "({[})]";
    if (isValid(str))
    {
        printf("is valid parenthesis ");
    }
    else
    {
        printf("not a valid parenthesis");
    }

    return 0;
}