#include <stdio.h> 
#include <stdlib.h> 

double findMaxAverage(int* nums, int numsSize, int k) {
    double max = 0 ; 
    double windowsum = 0 ;
    for(int i = 0 ; i<k ; i++){
       windowsum = windowsum + nums[i] ; 
    }

    max = windowsum ; 

    for(int i = k ; i<numsSize ; i++){
        windowsum = windowsum - nums[i-k] + nums[i] ;
        if(windowsum>max){
            max = windowsum ;
        }
    }

    return max/k;

}


int main(){


    int a[] = {1,12,-5,-6,50,3} ; 
    int size = 6 ;
    int k = 4 ;

    printf("max average = %lf" , findMaxAverage(a , size , k)) ;

    return 0;
}