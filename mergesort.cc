/**
 *  \file mergesort.cc
 *
 *  \brief Implement your mergesort in this file.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.hh"

void
printArray(keytype* A, int arraySize){
    for(int i= 0; i < arraySize; i++){
        printf("A[%d] = %d\n", i, A[i]);
    }
}

void
merge(keytype* A, int start, int end, int arraySize){
    int mid = (start+end)/2;
    int i = start;          //the beginning of the left array
    int j = mid + 1;     //the beginning of the right array
    int k = start;          //the beginning of the new array
    
    keytype* temp = (keytype*)malloc(arraySize*sizeof(keytype));
    
    while(i <= mid && j<= end){
        if(A[i] < A[j]){
            temp[k] = A[i];
            k++;
            i++;
        }
        else{
            temp[k] = A[j];
            k++;
            j++;
        }
    }
    
    while(i<=mid){
        temp[k] = A[i];
        k++;
        i++;
    }
    while(j<=end){
        temp[k] = A[j];
        k++;
        j++;
    }
    
    for(int i=start; i<=end; i++){
        A[i] = temp[i];
    }
    free(temp);
}

void
mergeSort(keytype* A, int start, int end){
    int mid;
    if (start >= end)
        return;
    mid = (start+end)/2;
    
    mergeSort(A, start, mid);
    mergeSort(A, mid+1, end);
    
    merge(A, start, end, end+1);
    
}

void
mySort (int N, keytype* A)
{ 
  mergeSort(A, 0, N-1);
}

/* eof */
