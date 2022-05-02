//---------------------------------------------------------------------
// Arquivo	: mat.c
// Conteudo	: implementacao do TAD MAT DINAMICAMENTE
// Autor	: Wagner Meira Jr. (meira@dcc.ufmg.br)
// Historico	: 2022-04-20 - arquivo criado
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
    // verifica se a matriz foi alocada corretamente
    erroAssert(M != NULL, "Erro ao alocar matriz!");

    for (int i = 0; i < m; i++)
    {
        M[i] = (double *)malloc(sizeof(double)*n);
        // verifica se a matriz foi alocada corretamente
        erroAssert(M[i] != NULL, "Erro ao alocar matriz!");
        

    }
    
    return M;
    
}

void zeraMatriz(double **M, int m, int n){

    for (int i = 0; i < m; i++)
    {
        // adicionando 0 aos elementos da matriz por precaucao
        for (int j = 0; i < n; j++)
        {
            M[i][j] = 0;
        }
    }
}

void leElemento(int *m, int *n){
    FILE *arq;
	arq = fopen("arquivo.txt", "r");
    // verifica se foi possível abrir o arquivo
    erroAssert(arq != NULL, "Erro ao ler arquivo");
    int i,j = 0;
    fscanf(arq, "%d %d", m, n);
    fclose(arq);
}

void preencheMatriz(double **M, int m, int n){
    FILE *arq;
	arq = fopen("arquivo.txt", "r");
    // verifica se foi possível abrir o arquivo
    erroAssert(arq != NULL, "Erro ao ler arquivo");
    int i,j = 0;
    fscanf(arq, "%d %d", &m, &n);
    printf("%d %d\n", m,n);
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

double **somaMatriz(double **A, double **B, int ma, int na, int mb, int nb){
    //verifica se as dimensões das matrizes são corretas para realizar a adição
    erroAssert(ma == mb && na == nb, "Impossível realizar a adição");
    double **C;
    C = criaMatriz(ma,na);
    for (int i = 0; i < ma; i++)
    {
        for (int j = 0; j < na; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
        
    }
    return C;
}

double **multiplicaMatriz(double **A, double **B, int ma, int na, int mb, int nb){

    //verifica se as dimensões das matrizes são corretas para realizar a multiplicação
    erroAssert(na == mb, "Impossível realizar a multiplicação");
    double **C;
    int i,j,k = 0;
    C = criaMatriz(ma,nb);
    for (i = 0; i < ma; i++){
        for (j = 0; j < nb; j++){
            for (k=0; k < na; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("\n");
    return C;
}


double **transpoeMatriz(double **A, int m, int n){
    double **B;
    B = criaMatriz(n,m);
    int i, j;

    for (i = 0; i < n; i++){
        for(j = 0 ; j < m; j++){
            B[i][j] = A[j][i];
        }
    }

    return B;
}


void imprimeMatriz(double **M, int m, int n){
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf ", M[i][j]);
        }
        printf("\n");
        
    }
    
}

void liberaMatriz(double **M, int m){
    for (int i = 0; i < m; i++)
    {
        free(M[i]);
    }
    free(M);
}



int main(int argc, char const *argv[])
{
    int m, n;

    double **M;
    leElemento(&m, &n);
    M = criaMatriz(m, n);
    preencheMatriz(M, m, n);
    imprimeMatriz(M, m, n);
    printf("\n");
    printf("\n");
    double **aux;
    aux = transpoeMatriz(M, m, n);
    double **aux2;
    aux2 = somaMatriz(M, M, m,n,m,n);
    
    imprimeMatriz(aux, n, m);

    return 0;
}