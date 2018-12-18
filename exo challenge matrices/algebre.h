#ifndef __ALGEBRE_H
#define __ALGEBRE_H

struct zmatrix {
  int n ; // nombre de lignes
  int m ; // nombre de colonnes
  float **M ; // la matrice nxm
} ;

typedef struct zmatrix mymatrix ;

mymatrix * creer (int n, int m) ;
mymatrix * concatener (mymatrix *A, mymatrix *B) ;
void print_matrix(mymatrix *A) ;

#endif
