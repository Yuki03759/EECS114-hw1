/**
 *  \file insertion-sort.cc
 *
 *  \brief Implement your insertion sort in this file.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.hh"

int 
bsearch(keytype* A, int low, int high, int key){
    int mid;
    if(low == high)
        return low;
  
    mid = (high + low)/2;
    if (key > A[mid])
        return bsearch(A, mid+1, high, key);
    else if(key < A[mid])
        return bsearch(A, low, mid, key);
    return mid;
}


void
insertionSortB(keytype* A, int N){
    int key, i, j, result, tmp;
    
    for(int i = 1; i < N; i++){
        result = bsearch(A, 0, i, A[i]);
        tmp = A[i];
        for(j = i - 1; j >= result; j--)
            A[j + 1] = A[j];
        A[result] = tmp;
    }
}


void
mySort(int N, keytype* A)
{
  /* Lucky you, you get to start from scratch */
  insertionSortB(A, N);
  //bsearch(A, 0, N, 5); 
}


/* eof */
