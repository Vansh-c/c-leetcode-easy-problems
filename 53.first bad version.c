#include <stdio.h> 
#include <stdbool.h>

bool isBadVersion(int version){
 
}

int firstBadVersion(int n) {
    int num ; 
   
    int left = 0 ; 
    int right = n;  

    
    while(left<right){
        int mid = (left + right)/2 ; 
        if(isBadVersion(mid)){
            right = mid ; 
        }

      else{
          left = mid+1 ; 
      }
    }
   return num ; 
}