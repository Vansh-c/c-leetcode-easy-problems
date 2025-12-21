#include <stdio.h> 
#include <string.h> 


int firstUniqChar(char* s) {
    int l = strlen(s) ; 

    int store[26] = {0} ; 

    for(int i = 0 ; i<l ; i++){
        store[s[i] - 'a']++ ;
    }

    for(int i = 0 ; i<l ; i++){
        if(store[s[i] - 'a']==1){
            return i ; 
        }
    }
 return -1; 
}

int main()
{
    char s[] = "roaor" ; 

    printf("%d" , firstUniqChar(s)) ;
    


    return 0 ; 
}