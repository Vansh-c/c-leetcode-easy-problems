#include <stdio.h> 

int picked = 1; // example picked number

int guess(int num) {
    if(num > picked) return -1;
    if(num < picked) return 1;
    return 0;
}


int guessNumber(int n){
     int l = 1   ;
     int h = n ; 
     int mid ; 

     if(guess(n) == 0 ) return n ;


     while(l<=h){
        mid = (l+h)/2 ; 
        if(guess(mid) == 0) return mid ; 

        else if(guess(mid) == 1){
            l = mid+1; 
        }

        else if(guess(mid) == -1){
            h = mid-1; 
        }
     }

     return l ; 
}


int main(){
    printf("%d" , guessNumber(3)) ; 

    return 0 ;
}