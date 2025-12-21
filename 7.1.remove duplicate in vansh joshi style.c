#include <stdio.h> 
#include <stdbool.h>
int remove_duplicate(int *a , int *l){
    int index = 0 ;
    int count = 0 ;  
    int unique[100] ; 
    bool check ; 

    int i = 0 ; 
    while(i<*l){
        check = true ; 
        if(i!=0){

            for(int j = 0 ; j<count ; j++){
                if(a[i] == unique[j]){
                    check = false ; 
                    break  ; 
                }
            }
        }
        
        
        if(check){
            a[index++] = a[i] ;  
            unique[count] = a[i] ; 
            count++  ; 
        }



       i++;  

        
    }

    *l=  index; 
}

int main()
{

    int a[] = {-1 , 0 , 5,5,-3,-3} ; 
    int len = sizeof(a)/sizeof(int) ; 

    remove_duplicate(a, &len) ;
    printf("%d\n", len); 

    for(int i = 0 ; i<len ; i++){
        printf(" %d" , a[i]) ; 
    }
    return 0 ;
}