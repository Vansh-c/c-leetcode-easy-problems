// program to get roman to integert 



#include <stdio.h> 

int romantoInt(char *s){

    int i = 0 ; 

    int total = 0 ; 
    while(s[i]!= '\0'){

        if(s[i]=='C' && s[i+1] == 'M' && s[i+1]!='\0'){
            total = total + 900 ; 
            i++ ;
            i++ ;
            continue ; 
        }


       if(s[i] == 'M'){
        total = total + 1000 ;  ; 
       }

       if(s[i] == 'C' && s[i+ 1] == 'D' && s[i] !='\0'){
        total = total + 400 ; 
        i++ ; 
        i++ ;
        continue ; 
       }

       if(s[i] == 'D'){
        total = total + 500 ; 
       }

       if(s[i] == 'X' && s[i+1]== 'C' && s[i+1]!='\0'){
        total = total + 90 ; 
        i++ ;
        i++ ;
        continue ; 
       }

       if(s[i] == 'C'){
        total = total + 100 ; 
       }

       
       if(s[i] == 'X' && s[i+1]== 'L' && s[i+1]!='\0'){
        total = total + 50 ; 
        i++ ;
        i++ ;
        continue ; 
       }



       if(s[i] == 'L'){
        total = total + 50 ;
       }

       if(s[i]=='I' && s[i+1] == 'X' && s[i+1]!='\0'){
         total = total + 9 ;
         i++ ; 
         i++ ; 
         continue ; 
       }

       if(s[i] == 'X'){
        total+=10 ; 
       }

       if(s[i] == 'I' && s[i + 1] == 'V' && s[i+1]!='\0'){
        total +=4 ; 
        i++ ; 
        i++ ; 
        continue ; 
       }

       if(s[i] == 'V'){
        total+=5 ;
       }

       if(s[i] == 'I'){
        total+=1; 
       }
       i++ ; 
    }

    return total ; 
}


int main()
{
    char s[] = "MCDLXXVI" ; 

    int r = romantoInt(s) ; 
    printf("%d" , r) ;


    return 0 ;
}