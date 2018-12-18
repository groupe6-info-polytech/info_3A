import copy as cp
def recherche_pivot(M,i):
    n=len(A)   # taille de matrice
    i_pivot=i 
    ##################### ICI
    for k in range(i+1,n): 
    
        if abs(M[k][i]>abs(M[i_pivot][i])): # abs= valeur absolue
               i_pivot=k
    return i_pivot

def echange_lignes(M,i,j):
    n_col=len(M[0])
    for k in range(n_col):
        M[i][k],M[j][k]=M[j][k],M[i][k]

#def transvection_ligne(M,i,j,poids):
#    n_col=len(M[0])
#    for k in range(n_col):
#        M[i][k]+=poids*M[j][k]

def triangularisation(A,B):
    n=len(A)
    n_A=len(A[0])
    n_B=len(B[0])
    for i in range(n):
        i_pivot=recherche_pivot(A,i)
        echange_lignes(A,i,i_pivot)
        echange_lignes(B,i,i_pivot)
        for k in range(i+1,n):
            poids=-A[k][i]/float(A[i][i])
            for l in range(n_A):  #l=0
                M[k][l]+=poids*M[i][l]
            for g in range(n_B):
                M[k][l]+=poids*M[i][g] #g=0
            

def resol_syst_tri(T,B):
    n=len(T)
    X=[0.]*n
    for i in range(n-1,-1,-1):
        X[i]=(B[i][0]-sum(T[i][j]*X[j] for j in range(i+1,n)))/T[i][i]
    return X





def resol_Gauss(A,B):
    B_c=cp.deepcopy(B)
    triangularisation(A,B_c)
    X=resol_syst_tri(A,B_c)
    return X





          