// program to find the square root without using math function


#include <stdio.h> 


int mySqrt(int x) {
    if(x==1){
        return 1 ; 
    }

    int start = 1, end = x ; int ans = 0 ; 

    while(start<=end){
        int mid = (start+end)/2 ; 

        if(mid<=(x/mid)){
            ans = mid ; 
            start = mid + 1 ; 
        }
        else{
            end = mid - 1 ; 
        }
    }

    return ans;
 
}


int main()
{


    printf("%d" , mySqrt(4)) ; 
    return 0 ;
}