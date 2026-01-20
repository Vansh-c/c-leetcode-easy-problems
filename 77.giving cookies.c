#include <stdio.h> 
#include <stdlib.h> 


void merge(int *a , int  low , int mid , int high){
    int i = low ; 
    int j = mid+1 ; 
    int k = low ;
    int b[100] ; 

    while(i<=mid && j<=high){
        if(a[i]<=a[j]){
           b[k] = a[i] ;
           i++ ; 
           k++ ;  

        }

        else if(a[j] < a[i]){
            b[k] = a[j] ; 
            j++ ; 
            k++ ; 
        }

    }

    while(i<=mid){
        b[k] = a[i] ; 
        i++ ; 
        k++ ; 
    }


    while(j<=high){
        b[k] = a[j] ; 
        k++ ; 
        j++ ; 
    }
    for(int i = low  ; i<=high ; i++){
       a[i] = b[i]; 
    }
    
}


void mergesort(int *a , int low , int high){
    if(low<high){
        int mid = (high + low)/2 ; 
        mergesort(a , low  , mid)  ; 
        mergesort(a, mid+1 , high) ; 
        merge(a , low , mid  , high) ; 
    }
}



int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int count = 0 ; 
 
    mergesort(g , 0 , gSize-1) ; 
    mergesort(s , 0 , sSize-1) ; 

    int i = 0 ; 
    int j = 0 ; 

    while(i<gSize && j<sSize){
        if(g[i] <= s[j]){
            count++ ;
            i++ ; 

        }
        j++ ; 
    }


    return count ; 
 
}


int main()
{

    int g[] = {10,9,8,7} ; 
    int s[] = {5,6,7,8} ; 

    int gSize = sizeof(g)/sizeof(int) ; 
    int sSize= sizeof(s)/sizeof(int) ; 

    printf("%d"  , findContentChildren(g , gSize , s , sSize)) ; 
     

    return 0 ;
}