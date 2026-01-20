#include <stdio.h> 
#include <stdlib.h> 

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *r = (int *)malloc(sizeof(int)*100) ; 

    int initial_element = -1 ; 

    int stack[100]  ;
    int top = -1 ; 

    
    for(int i = 0 ; i<nums1Size ; i++){
        stack[++top] = nums1[i] ; 
    }

    int k = 0  ; 

    while(top!=-1){
        initial_element = -1 ; 
        int check = 0 ; 
        int element = stack[top] ; 

        int p = 0 ; 

        while(nums2[p]!=element){
            p++ ; 
        }

        for(int j = p ;j<nums2Size ; j++ ){
            if(element< nums2[j]){
                initial_element = nums2[j] ; 
                check = 1;  
                break ; 
            }
        }

        if(check == 1){
            r[k++] = initial_element ; 
        }
        else{
            r[k++] = -1 ; 
        }

        top--;
    }

    *returnSize = nums1Size ; 

    int n = 0 ; 

    int l = 0 ; 
    int h = *returnSize-1 ; 

    while(l<h){
        int t = r[l] ; 
        r[l] = r[h] ; 
        r[h] = t ; 

        l++ ; 
        h-- ; 
    }

    return r ; 
}

int main(){
    int a[] = {4, 1 ,2} ; 
    int b[] = {1,3,4,2} ; 

    int sizea = sizeof(a)/sizeof(int) ; 
    int sizeb = sizeof(b)/sizeof(int) ; 
    int returnSize ; 

    int *res = nextGreaterElement(a , sizea , b , sizeb , &returnSize) ; 

    for(int i = 0 ; i<returnSize ; i++){
        printf("%d " , res[i]) ; 
    }




    return 0 ; 
}