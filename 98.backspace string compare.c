#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <string.h> 

bool backspaceCompare(char* s, char* t) {
    int stack1[100] = {0};
    int stack2[100] = {0};
    int top1 = -1 ;  
    int top2 = -1 ; 
    
    int i = 0 ; 
    while(s[i]!='\0'){
        if(s[i] == '#'){
            if(top1>=0){
                top1-- ; 
            }

        //    if(top1>=0){
        //     stack1[top1] = 0 ; 
        //    }
        }
        else{
            stack1[++top1]  = s[i] - 'a' ; 
        }
        i++ ; 

    }

    int j = 0 ; 

    while(t[j]!='\0'){
        if(t[j] == '#'){
            if(top2>=0){
                top2--;
            }
            // if(top2>=0){
            //     stack2[top2] = 0 ;
            // }
        }
        else{
            stack2[++top2] = t[j] - 'a'; 
        }
        j++ ; 
    }


    if(top1!=top2){
        return false ; 
    }

    int h =  0 ; 

    while(h<=top1){
        printf("%d %d\n" , stack1[h] , stack2[h]) ;
        if(stack1[h] != stack2[h]){
            return false ; 
        }
        h++ ;
    }


    return true ; 
}

int main(){


    char *s = "xywrrmp" ; 
    char *t = "xywrrmu#p" ; 

    if(backspaceCompare(s,t)){
        printf("both strings are same") ; 
    }
    else{
        printf("both str not same") ;
    }


    return 0 ;
}