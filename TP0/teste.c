#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "msgassert.h"
#define INITRANDOMRANGE 10

#define ELEMSWAP(x,y) (x+=y,y=x-y,x-=y)


typedef struct mat{
	double **m;
	int tamx, tamy;
	int id;
} mat_tipo;

void criaMatriz(mat_tipo * mat, int tx, int ty, int id)
// Descricao: cria matriz com dimensoes tx X ty
// Entrada: mat, tx, ty, id
// Saida: mat
{
    
    erroAssert(mat != NULL, "Erro ao alocar matriz!");

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
}

void inicializaMatrizNula(mat_tipo * mat)
// Descricao: inicializa mat com valores nulos 
// Entrada: mat
// Saida: mat
{
  int i, j;
  // inicializa todos os elementos da matriz com 0, por seguranca 
  for (i=0; i<mat->tamx; i++){
    for(j=0; j<mat->tamy; j++){
      mat->m[i][j] = 0;
      //ESCREVEMEMLOG((long int)(&(mat->m[i][j])),sizeof(double),mat->id);
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
      //ESCREVEMEMLOG((long int)(&(mat->m[i][j])),sizeof(double),mat->id);
    }
  }
}

void destroiMatriz(mat_tipo *a)
// Descricao: destroi a matriz a, que se torna inacessível
// Entrada: a
// Saida: a
{
  // apenas um aviso se a matriz for destruida mais de uma vez
    
    
    for (int i = 0; i < a->tamx; i++)
    {
        free(a->m[i]);
    }
    free(a->m);
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
      //LEMEMLOG((long int)(&(mat->m[i][j])),sizeof(double),mat->id);
    }
  }
  return s; // apenas para evitar que acesso seja eliminado
}

void imprimeMatriz(mat_tipo * mat)
// Descricao: imprime a matriz com a identificacao de linhas e colunas
// Entrada: mat
// Saida: impressao na saida padrao (stdout) 
{
  int i,j;

  // imprime os identificadores de coluna
  printf("%9s"," ");
  for(j=0; j<mat->tamy; j++)
    printf("%8d ",j);
  printf("\n");

  // imprime as linhas
  for (i=0; i<mat->tamx; i++){
    printf("%8d ",i);
    for(j=0; j<mat->tamy; j++){
      printf("%8.2f ",mat->m[i][j]);
      //LEMEMLOG((long int)(&(mat->m[i][j])),sizeof(double),mat->id);
    }
    printf("\n");
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

  if (c->m != NULL)
  {
    destroiMatriz(c);
  }

  // inicializa a matriz c garantindo a compatibilidade das dimensoes
  criaMatriz(c,a->tamx, a->tamy, c->id);
  inicializaMatrizNula(c);

  // faz a soma elemento a elemento
  for (i=0; i<a->tamx; i++){
    for(j=0; j<a->tamy; j++){
      c->m[i][j] = a->m[i][j]+b->m[i][j];
      //LEMEMLOG((long int)(&(a->m[i][j])),sizeof(double),a->id);
      //LEMEMLOG((long int)(&(b->m[i][j])),sizeof(double),b->id);
      //ESCREVEMEMLOG((long int)(&(c->m[i][j])),sizeof(double),c->id);
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

  // cria e inicializa a matriz c
  criaMatriz(c,a->tamx, b->tamy,c->id);
  inicializaMatrizNula(c);

  // realiza a multiplicacao de matrizes
  for (i=0; i<c->tamx;i++){
    for (j=0; j<c->tamy;j++){
      for (k=0; k<a->tamy;k++){
        c->m[i][j] += a->m[i][k]*b->m[k][j];
        //LEMEMLOG((long int)(&(a->m[i][k])),sizeof(double),a->id);
        //LEMEMLOG((long int)(&(b->m[k][j])),sizeof(double),b->id);
        //ESCREVEMEMLOG((long int)(&(c->m[i][j])),sizeof(double),c->id);
      }
    }
  }
}

void transpoeMatriz(mat_tipo *a)
// Descricao: transpoe a matriz a
// Entrada: a
// Saida: a
{
  int i,j,dim;
  
  // determina a maior dimensao entre tamx e tamy
  dim = (a->tamx>a->tamy?a->tamx:a->tamy);

  // faz a transposicao como se a matriz fosse quadrada
  for (i=0; i<dim; i++){
    for(j=i+1; j<dim; j++){
    //   ELEMSWAP((a->m[i][j]),(a->m[j][i]));
    //   ESCREVEMEMLOG((long int)(&(a->m[i][j])),sizeof(double),a->id);
    //   ESCREVEMEMLOG((long int)(&(a->m[j][i])),sizeof(double),a->id);
    }
  }
  // inverte as dimensoes da matriz transposta
  ELEMSWAP(a->tamx,a->tamy);
}





int main(int argc, char const *argv[])
{
    mat_tipo a, b, c;
    int optx = 5;
    int opty = 5;

    criaMatriz(&a,optx,opty,0);
    inicializaMatrizAleatoria(&a);
    criaMatriz(&b,optx,opty,1);
    inicializaMatrizAleatoria(&b);
    criaMatriz(&c,optx,opty,2);
    inicializaMatrizNula(&c);
    imprimeMatriz(&a);
    printf("\n\n");
    imprimeMatriz(&b);
    printf("\n\n");
    imprimeMatriz(&c);
    printf("\n\n");
    somaMatrizes(&a,&b,&c);
    imprimeMatriz(&c);



    return 0;
}
