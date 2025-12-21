#include <stdio.h> 
#include <string.h>


int value(char c){
    switch(c){
       case 'M':return 1000 ; 
       case 'D':return 500 ; 
       case 'C':return 100 ; 
       case 'L':return 50 ; 
       case 'X':return 10 ; 
       case 'V':return 5;
       case 'I':return 1; 
       default: return 0 ;

    }
}

int romantoInt(char *s){
  int l = strlen(s) ; 
  int total = 0 ; 

  for(int i = 0 ; i<l ; i++){
    int c = value(s[i]) ; 
    int n = value(s[i+1]) ; 
    if(c<n){
        total = total - c ; 
    }
    else{
        total = total + c;  
    }
  }

  return total ; 
}


int main()
{
     char s[] = "MCDLXXVI" ; 

     int r = romtoint(s) ; 
     printf("%d", r) ; 

    return 0 ;
}