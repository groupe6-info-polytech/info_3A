#include <stdio.h>
#include "algebre.h"

// Fonctions pour descente de Gauss
int recherche_pivot(mymatrix *M, int n, int i) // Prend comme paramètres la matrice concaténée M et la taille de la matrice n (à rentrer manuellement)
{
  int i_pivot; // indice du pivot
  int k;       // ligne
  i_pivot = i;
  for (k = i + 1; k < n; k++)
  {
    if ((M->M)[k][i] > (M->M)[i_pivot][i])
      i_pivot = k;
  }
  return i_pivot;
}

void echange_lignes(mymatrix *M, int i, int j, int n) // i et j sont les lignes, n est la taille de la matrice
{
  int n_col = n;
  int k; // colonne
  int temp;
  for (k = 0; k < n_col; k++)
  {
    temp = (M->M)[j][k];
    (M->M)[j][k] = (M->M)[i][k];
    (M->M)[i][k] = temp;
  }
}

int inversible(mymatrix *B, int n, int k)
{
  int i;
  int j;
  int value;
  value = 1;
  i = 0;
  j = 0;
  while (i < n && value != 0)
  {
    while (j < k && value != 0)
    {
      if ((B->M)[i][j] != 0)
      {
        value = 1;
      }
      else
      {
        value = 0;
      }
      i++;
    }
  }
  return value;
}

int gauss(mymatrix *A, mymatrix *B, int n_A, int n_B) // Fonction appelée pour triangulariser
// Paramètres : Matrice A, matrice identité B, taille de la matrice carrée A et nombre de colonnes de la matrice B
{
  int i;
  int i_pivot;
  int k;
  int poids;
  int l;
  int g;
  int n;
  n = n_A;
  for (i = 0; i < n; i++)
  {
    i_pivot = recherche_pivot(A, n_A, i);
    echange_lignes(A, i, i_pivot, n_A);
    echange_lignes(B, i, i_pivot, n_B);
    for (k = i + 1; k < n; k++)
    {
      poids = -(A->M)[k][i] / (A->M)[i][i];
      for (l = 0; l < n_A; l++)
      {
        (A->M)[k][l] += poids * (A->M)[i][l];
      }
      for (g = 0; l < n_B; g++)
      {
        (A->M)[k][l] += poids * (A->M)[i][g];
      }
    }
  }
  printf("Matrice de fin");
  printf("\n");
  print_matrix(A);
  printf("\n");
  printf("Matrice identite de fin");
  printf("\n");
  print_matrix(B);
  printf("\n");

  return inversible(B, n_A, n_B);
}

int main()
{
  mymatrix *A = creer(3, 3);
  mymatrix *B = creer(3, 1);
  int i;

  for (i = 0; i < 3; i++)
    (A->M)[i][i] = 1;
  (B->M)[0][0] = 1;
  (B->M)[1][0] = 2;
  (B->M)[2][0] = 3;

  // Tester l'algorithme avec une matrice donnée dans l'exercice
  mymatrix *D = creer(3, 3);
  mymatrix *E = creer(3, 1);

  (D->M)[0][0] = 1;
  (D->M)[0][1] = 1;
  (D->M)[0][2] = 2;
  (D->M)[1][0] = 1;
  (D->M)[1][1] = -1;
  (D->M)[1][2] = -1;
  (D->M)[2][0] = 1;
  (D->M)[2][1] = 0;
  (D->M)[2][2] = 1;

  (E->M)[0][0] = 5;
  (E->M)[1][0] = 1;
  (E->M)[2][0] = 3;

  printf("Matrice de depart");
  printf("\n");
  print_matrix(D);
  printf("\n");
  printf("Matrice identite");
  printf("\n");
  print_matrix(E);
  printf("\n");

  printf("%i", gauss(D, E, 3, 1));
  printf("\n");
}
