#include <stdio.h> 
#include <string.h>

int findComplement(int num) {

  char str[50] ; 
  int k = 0 ; 

  while(num!=0){
    int r = num%2 ; 
    if(r==0){
        str[k++] = '0' ; 
    }
    else{
        str[k++] = '1' ; 
    }
    num = num/2 ; 

  }
  str[k] = '\0' ;

  printf("%s \n" , str) ;

  int sum = 0 ; 
  long long int c = 1 ; 

  int j = 0 ; 

  while(str[j]!='\0'){
      if(str[j] == '0'){
        sum = sum + c ; 
      }
      c = c*2 ; 
      j++; 
  }

  return sum ; 
    
}

int main(){

    printf("%d" , findComplement(2)) ; 
}