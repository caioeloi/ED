#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>
#include <string.h>
#include "memlog.h" 
#include "msgassert.h" 


#define INITRANDOMRANGE 10

typedef struct mat{
	double **m;
	int tamx, tamy;
	int id;
} mat_tipo;



mat_tipo* criaMatriz(int tx, int ty, int id)
// Descricao: cria matriz com dimensoes tx X ty
// Entrada: mat, tx, ty, id
// Saida: mat
{
    mat_tipo *mat;
    mat = (mat_tipo *) malloc(sizeof(mat_tipo));
    
    //erroAssert(mat != NULL, "Erro ao alocar matriz!");

    // verifica se os valores de tx e ty são validos
    erroAssert(tx>0,"Dimensao nula");
    erroAssert(ty>0,"Dimensao nula");
    
    mat->m = (double **)malloc(sizeof(double *) * tx);
    // verifica se a matriz foi alocada corretamente
    erroAssert(mat->m != NULL, "Erro ao alocar matriz!");
    
    for (int i = 0; i < tx; i++)
    {
        mat->m[i] = (double *)malloc(sizeof(double)*ty);
        // verifica se a matriz foi alocada corretamente
        erroAssert(mat->m[i] != NULL, "Erro ao alocar matriz!");

    }
    // inicializa as dimensoes da matriz
    mat->tamx = tx;
    mat->tamy = ty;
    // inicializa o identificador da matriz, para rastreamento
    mat->id = id;
    return mat;
}


void destroiMatriz(mat_tipo *a)
// Descricao: destroi a matriz a, que se torna inacessível
// Entrada: a
// Saida: a
{

    // apenas um aviso se a matriz for destruida mais de uma vez
    avisoAssert(((a->tamx>0)&&(a->tamy>0)),"Matriz já foi destruida");
    
    for (int i = 0; i < a->tamx; i++)
    {
        free(a->m[i]);
    }
    free(a->m);
    free(a);

}


void inicializaMatrizNula(mat_tipo * mat)
// Descricao: inicializa mat com valores nulos 
// Entrada: mat
// Saida: mat
{
  int i, j;
  // inicializa todos os elementos da matriz com 0, por seguranca 
  for (i=0; i < mat->tamx; i++){
    for(j=0; j < mat->tamy; j++){
      mat->m[i][j] = 0;
    }
  }
}

void inicializaMatrizAleatoria(mat_tipo * mat)
// Descricao: inicializa mat com valores aleatorios
// Entrada: mat 
// Saida: mat
{
  int i, j;
  // inicializa a matriz com valores nulos, por seguranca
  inicializaMatrizNula(mat);
  // inicializa a parte alocada da matriz com valores aleatorios
  for (i=0; i<mat->tamx; i++){
    for(j=0; j<mat->tamy; j++){
      mat->m[i][j] = drand48()*INITRANDOMRANGE;
    }
  }
}


void somaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c)
// Descricao: soma as matrizes a e b e armazena o resultado em c
// Entrada: a, b
// Saida: c
{
  int i,j;
  // verifica se as dimensoes das matrizes a e b sao as mesmas
  erroAssert(a->tamx==b->tamx,"Dimensoes incompativeis");
  erroAssert(a->tamy==b->tamy,"Dimensoes incompativeis");

  // inicializa a matriz c garantindo a compatibilidade das dimensoes
  if (c != NULL)
  {
      destroiMatriz(c);
  }
  
  c = criaMatriz(a->tamx, a->tamy, c->id);
  inicializaMatrizNula(c);

  // faz a soma elemento a elemento
  for (i=0; i<a->tamx; i++){
    for(j=0; j<a->tamy; j++){
      c->m[i][j] = a->m[i][j]+b->m[i][j];
    }
  }
}

void multiplicaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c)
// Descricao: multiplica as matrizes a e b e armazena o resultado em c
// Entrada: a,b
// Saida: c
{
  int i,j,k;
  // verifica a compatibilidade das dimensoes 
  erroAssert(a->tamy==b->tamx,"Dimensoes incompativeis");

  // inicializa a matriz c garantindo a compatibilidade das dimensoes
  if (c != NULL)
  {
    destroiMatriz(c);
  }
  // cria e inicializa a matriz c
  c = criaMatriz(a->tamx, b->tamy,c->id);
  inicializaMatrizNula(c);

  // realiza a multiplicacao de matrizes
  for (i=0; i<c->tamx;i++){
    for (j=0; j<c->tamy;j++){
      for (k=0; k<a->tamy;k++){
        c->m[i][j] += a->m[i][k]*b->m[k][j];
      }
    }
  }
}

void imprimeMatriz(mat_tipo *mat){
    for (int i = 0; i < mat->tamx; i++)
    {
        for (int j = 0; j < mat->tamy; j++)
        {
            printf("%lf ", mat->m[i][j]);
        }
        printf("\n");
        
    }
    
}

double acessaMatriz(mat_tipo * mat)
// Descricao: acessa mat para fins de registro de acesso 
// Entrada: mat 
// Saida: mat
{
  int i, j;
  double aux, s=0.0;
  for (i=0; i<mat->tamx; i++){
    for(j=0; j<mat->tamy; j++){
      aux = mat->m[i][j];
      s+=aux;
      LEMEMLOG((long int)(&(mat->m[i][j])),sizeof(double),mat->id);
    }
  }
  return s; // apenas para evitar que acesso seja eliminado
}


int main(int argc, char const *argv[])
{
    int optx = 2;
    int opty = 2;
    mat_tipo *a, *b, *c;
    a = criaMatriz(optx,opty,0);
    inicializaMatrizAleatoria(a);
    b = criaMatriz(optx,opty,1);
    inicializaMatrizAleatoria(b);
    c = criaMatriz(optx,opty,2);
    inicializaMatrizNula(c);
    imprimeMatriz(a);
    printf("\n\n");
    imprimeMatriz(b);
    printf("\n\n");
    imprimeMatriz(c);
    printf("\n\n");
    double x;
    x = acessaMatriz(a);
    x = acessaMatriz(b);
    x = acessaMatriz(c);
    somaMatrizes(a,b,c);
    imprimeMatriz(c);


    return 0;
}
