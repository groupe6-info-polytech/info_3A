//----------------------------------------------------------------------------------------------
//                                       
//                                      Groupe 6
// Benjamin BIGOT, Clément MURAT, Ikram LAGUIR, Lucie HULIN, Matthias ROSATI, Elysa LACOT
//
//----------------------------------------------------------------------------------------------

void affichage_tableau(int tab[], int dim)
{   int i;
    for(i=0;i<dim;i++)
    {   printf("%d  ",tab[i]);
    }
    printf("\n\n");
}
/* Renvoit 1 si x appartient à l'ensemble, 0 sinon */
int appartient_gr_06(int x, int *T1, int s1, int n1)
{   int i = 0, trouve = 0;
    while(i<s1 && trouve==0)
    {   if(T1[i]==x)
        {   trouve = 1;
        }
        i++;
    }
    return trouve;
}
/* Renvoit 1 si T1 inclus dans T2, 0 sinon */
int inclus_gr_06(int *T1, int s1, int n1, int *T2, int s2, int n2)
{   int i = 0, trouve = 1;
    while(i<s1 && trouve==1)
    {   trouve = appartient_gr_06(T1[i], T2, s2, n2);
        i++;
    }
    return trouve;
}
/* Renvoit l'union de T1 et T2 dans T3 */
void union_gr_06(int *T1, int s1, int n1, int *T2, int s2, int n2,
int *T3, int s3, int *n3)
{   int i = 0, j = 0, k = 0;
    while(i<n1 && j<n2)
    {   if(T1[i]<=T2[j])
        {   T3[k]=T1[i];
            if(T1[i]==T2[j])
            {   j++;
                *n3 = *n3 ­1;
            }
            i++;
        }
        else
        {   T3[k]=T2[j];
            j++;
        }
        k++;
    }
    while(i<n1) // Si on a termine le tableau B avant le tableau A
    {   T3[k]=T1[i];
        i++;
    }
    while(j<n2) // Si on a termine le tableau A avant le tableau B
    {   T3[k]=T2[i];
        j++;
    }
}
/* Renvoit l'intersection de T1 et T2 dans T3 */
void inter_gr_06(int *T1, int s1, int n1, int *T2, int s2, int n2,
int *T3, int s3, int *n3)
{   int *A, *B, i, nA, nB, s;
    if(n1<n2)
    {   A = T1;
        B = T2;
        nA = n1;
        nB = n2;
        s = s2;
    }
    else
    {   A = T2;
        B = T1;
        nA = n2;
        nB = n1;
        s = s1;
    }
    *n3 = 0;
    for(i=0;i<nA;i++)
    {   if(appartient_gr_06(A[i],B,s,nB)==1)
        {   T3[*n3] = A[i];
            *n3 = *n3 + 1;
        }
    }
}