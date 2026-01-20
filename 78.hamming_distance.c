#include <stdio.h> 
#include <stdlib.h> 

int hammingDistance(int x, int y) {
    char num1[50] = {'0'}; 
    char num2[50]  = {'0'};
    int i = 0 ; 
    int j = 0 ; 
    int k = 0 ; 

    
   while(k<49){
    num1[k] = '0' ; 
    num2[k++] = '0' ;
   }

   num1[k] = '\0' ; 
   num2[k] = '\0' ;

    if(x==0) num1[i++]= '0' ; 
    if(y==0) num2[j++] = '0' ; 

    while(x!=0){
       if(x%2==0){
          num1[i] = '0' ;  
          i++ ;
       }
       else{
        num1[i] = '1';
        i++ ;
       }

       x = x/2 ; 

    }
 


    while(y!=0){
        if(y%2==0){
            num2[j] = '0' ; 
            j++ ; 
        }
        else{
            num2[j] = '1' ; 
            j++ ; 
        }

        y = y/2 ; 


    }



    printf("%s\n" , num1 ) ;
    printf("%s\n" , num2);

    int count = 0 ; 
    for(int t = 0 ; t<50 ; t++){
        if(num1[t] != num2[t]){
            count++ ; 
        }
    }

    return count ; 
}

int main()
{

    printf("the hamming distance is %d" , hammingDistance(9,8)) ;


    return 0 ; 
}