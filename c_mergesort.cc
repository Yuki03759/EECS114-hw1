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
merge(keytype* A1, keytype* A2, int N1, int N2){

    int i = 0;          //the beginning of the left array
    int j = 0;     //the beginning of the right array
    int k = 0;          //the beginning of the new array
    int N = N1+N2;
    int temp[N];
    
    while(i <= N1 && j <= N2){
        if(A1[i] < A2[j]){
            temp[k] = A1[i];
            k++;
            i++;
        }
        else{
            temp[k] = A2[j];
            k++;
            j++;
        }
    }
    
    while(i<=N1){
        temp[k] = A1[i];
        k++;
        i++;
    }
    while(j<=N2){
        temp[k] = A2[j];
        k++;
        j++;
    }
    
    for(int i=0; i < N; i++){
        A1[i] = temp[i];
    }
}

void
mySort(int N, keytype* A){

    if (N==1) return;
    
    int size = (N%2)? N/2+1 : N/2;
 
    mySort(N/2,A);
    mySort(size, A+N/2);
    
    merge(A, A+N/2, N/2, size);
    
    //printArray(A, N);
    
}

/* eof */
