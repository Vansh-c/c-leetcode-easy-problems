#include <stdio.h> 
#include <stdlib.h>

int partition(int *a , int low , int high){
  int pivot = a[low] ; 
  int i = low+1 ; 
  int j = high;

  while(i<=j){
    while(i<=high && a[i]<=pivot){
      i++ ; 
    }

    while(j>low && a[j]>pivot){
      j-- ; 
    }

    if(i<j){
      int t = a[i] ; 
      a[i] = a[j] ; 
      a[j] = t ; 
      i++ ;
       j--; 
    }
  }

    int tmp = a[low] ; 
    a[low] = a[j] ; 
    a[j] = tmp ; 
  

  return j ;
}


void quicksort(int *a , int low , int high){
  if(low<high){
    int partitionIndex = partition(a , low , high) ; 
    quicksort(a , low , partitionIndex-1) ; 
    quicksort(a  , partitionIndex+1 , high) ; 
  }
}


int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *arr = (int *)malloc(sizeof(int)*1000) ; 
    quicksort(nums1 , 0 , nums1Size-1) ; 
    quicksort(nums2 , 0 , nums2Size-1) ; 
    *returnSize = 0 ; 

      int i = 0 ; 
      int j = 0 ; 
      int k = 0 ; 

      while(i<nums1Size && j<nums2Size){
             if(nums1[i] == nums2[j]){
              if((*returnSize)==0   ||  arr[(*returnSize)-1] != nums1[i]){
                arr[(*returnSize)++] = nums1[i] ; 
              }
              i++ ; 
              j++ ; 
             }

             else if(nums1[i]< nums2[j]){
                 i++ ; 
             }

             else if(nums1[i]> nums2[j]){
              j++ ; 
             }
      }

      return arr ; 
}

int main(){
  int a[] = {3,4,5,2,3,2} ; 
  int a2[] = {3,2,2} ; 
  int returnSize ; 

  quicksort(a, 0 , 4) ; 

  int *r = intersection(a,  5 , a2 , 2 , &returnSize) ; 

  for(int i =0 ; i<returnSize ; i++){
    printf("%d " , r[i]) ;
  }
}