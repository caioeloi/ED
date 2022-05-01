//---------------------------------------------------------------------
// Arquivo	: mat.c
// Conteudo	: implementacao do TAD MAT 
// Autor	: Wagner Meira Jr. (meira@dcc.ufmg.br)
// Historico	: 2021-10-18 - arquivo criado
//		: 2021-10-21 - estrutura de diretorios
//              : 2021-11-14 - adequacao para versao 1.1 memlog
//---------------------------------------------------------------------

#include "msgassert.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double **criaMatriz( int m, int n){
    // verifica se os valores de m e n são validos
    erroAssert(m>0,"Dimensao nula");
    erroAssert(n>0,"Dimensao nula");

    double **M;

    M = (double **)malloc(sizeof(double *) * m);
    erroAssert(M != NULL, "Erro ao alocar matriz!");

    for (int i = 0; i < n; i++)
    {
        M[i] = (double *)malloc(sizeof(double)*n);
        erroAssert(M[i] != NULL, "Erro ao alocar matriz!");

    }

    return M;
    
}

void leElemento(int *m, int *n){
    FILE *arq;
	arq = fopen("arquivo.txt", "r");
    erroAssert(arq != NULL, "Erro ao ler arquivo");
    int i,j = 0;
    fscanf(arq, "%d %d", m, n);
    fclose(arq);
}

void preencheMatriz(double **M, int m, int n){
    FILE *arq;
	arq = fopen("arquivo.txt", "r");
    erroAssert(arq != NULL, "Erro ao ler arquivo");
    int i,j = 0;
    fscanf(arq, "%d %d", &m, &n);
    while (!feof(arq)){
        for ( i = 0; i < m; i++)
        {
            for ( j = 0; j < n; j++)
            {
                fscanf(arq, "%lf ", &M[i][j]);
            } 
        }
    }

    fclose(arq);
}

double **somaMatriz(double **A, double **B, int m, int n){
    double **C;
    C = criaMatriz(m,n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
        
    }
    
    return C;
}



int main(int argc, char const *argv[])
{
    int m, n;
    double **M;
    leElemento(&m, &n);
    M = criaMatriz(m, n);
    preencheMatriz(M, m, n);
    printf("m = %d\nn = %d\n", m,n);
    return 0;
}
