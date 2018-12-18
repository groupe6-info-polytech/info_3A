#include "algebre.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

mymatrix * creer (int n, int m)
{
  int i, j ;
  mymatrix * tmp = malloc(sizeof(mymatrix)) ;
  tmp->n = n ;
  tmp->m = m ;
  // allocation de la matrice
  tmp->M = malloc(n*sizeof(float *)) ;
  for (i=0; i<n; i++)
    (tmp->M)[i] = malloc(m*sizeof(float)) ;
  // initialisation à 0
  for (i=0; i<n; i++)
  {
    for (j=0; j<m; j++)
      (tmp->M)[i][j] = 0 ;
  }
  return tmp ;
}


mymatrix * concatener (mymatrix *A, mymatrix *B)
{
  mymatrix *C ;
  int i, j, k ;
  assert(A->n == B->n) ;
  C = creer(A->n, A->m+B->m) ;
  for (i=0; i < A->n; i++)
  {
    k = 0 ;
    for (j=0; j < A->m;  j++,k++)
      (C->M)[i][k] = (A->M)[i][j] ;
    for (j=0; j < B->m;  j++,k++)
      (C->M)[i][k] = (B->M)[i][j] ;
  }
  return C ;
}

void print_matrix(mymatrix *A)
{
  int i, j ;

  for (i=0; i<A->n; i++)
  {
    for (j=0; j<A->m; j++)
      printf("%f\t", (A->M)[i][j]) ;
    printf("\n") ;
  }
}
