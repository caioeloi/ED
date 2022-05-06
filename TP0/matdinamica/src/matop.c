//---------------------------------------------------------------------
// Arquivo      : matop.c
// Conteudo     : programa de avaliacao do TAD MAT 
// Autor        : Wagner Meira Jr. (meira@dcc.ufmg.br)
// Historico    : 2021-10-18 - arquivo criado
//              : 2021-10-21 - estrutura de diretorios
//              : 2021-10-25 - opcoes de linha de comando 
//              : 2021-11-14 - adequacao para versao 1.1 memlog 
//---------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>
#include <string.h>
#include "mat.h"
#include "memlog.h" 
#include "msgassert.h" 
#include <stdbool.h>
#include <regex.h>

// definicoes de operacoes a serem testadas
#define OPSOMAR 1
#define OPMULTIPLICAR 2
#define OPTRANSPOR 3

// variaveis globais para opcoes
static int opescolhida;
char lognome[100];
int optx, opty, regmem;
char *m1Nome;
char *m2Nome;
char *outNome;
memlog ml;

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
  fprintf(stderr,"matop\n");
  fprintf(stderr,"\t-s \t(somar matrizes) \n");
  fprintf(stderr,"\t-m \t(multiplicar matrizes) \n");
  fprintf(stderr,"\t-t \t(transpor matriz)\n");
  fprintf(stderr,"\t-p <arq>\t(arquivo de registro de acesso)\n");
  fprintf(stderr,"\t-l \t(registrar acessos a memoria)\n");
  fprintf(stderr,"\t-x <int>\t(primeira dimensao)\n");
  fprintf(stderr,"\t-y <int>\t(segunda dimensao)\n");
}


void parse_args(int argc,char ** argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida, optx, opty, regmem, lognome
{

  // variaveis externas do getopt
  extern char * optarg;

  // variavel auxiliar
  int c;

  // inicializacao variaveis globais para opcoes
  opescolhida = -1;
  optx = -1;
  opty = -1;
  regmem = 0;
  lognome[0] = 0;

  // getopt - letra indica a opcao, : junto a letra indica parametro
  // no caso de escolher mais de uma operacao, vale a ultima
  while ((c = getopt(argc, argv, "smtp:x:y:lh")) != EOF)
    switch(c) {
      case 'm':
  avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
        opescolhida = OPMULTIPLICAR;
              break;
      case 's':
  avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
        opescolhida = OPSOMAR;
              break;
      case 't':
  avisoAssert(opescolhida==-1,"Mais de uma operacao escolhida");
        opescolhida = OPTRANSPOR;
              break;
      case 'p': 
        strcpy(lognome,optarg);
  break;
      case 'x': 
        optx = atoi(optarg);
  break;
      case 'y': 
        opty = atoi(optarg);
  break;
      case 'l': 
        regmem = 1;
  break;
      case 'h':
      default:
              uso();
              exit(1);

    }
    // verificacao da consistencia das opcoes
    erroAssert(opescolhida>0,"matop - necessario escolher operacao");
    erroAssert(strlen(lognome)>0,
      "matop - nome de arquivo de registro de acesso tem que ser definido");
    erroAssert(optx>0,"matop - dimensao X da matriz tem que ser positiva");
    erroAssert(opty>0,"matop - dimensao Y da matriz tem que ser positiva");
}

// Descrição: conte o número de vezes que c aparece em str
// Entrada: str,c
// Saída: número de vezes que c aparece em str
unsigned countCharStr(const char *str, const char c) {

    unsigned n = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (c == str[i])
            n++;
    }
}

// Descrição: verifica se outras linhas de um arquivo são consistentes
// Entrada: str
// Saída: retorna verdadeiro se consisntente e falso caso contrário
bool isOtherLineValid(const char *str) {

 
}

// Descrição: verifica se a 1ª linha de um arquivo é consistente
// Entrada: str
// Saída: retorna verdadeiro se consisntente e falso caso contrário
bool isFirstLineValid(const char *str) {

}

// Descrição: verifica se um arquivo contendo uma matriz é válido
// Entrada: string com nome do arquivo
// Saída: matriz construída a partir do arquivo
void isFileValid(char *matrixName) {

  // Abre o arquivo
  FILE *arq;
  arq = fopen(matrixName, "r");
  erroAssert(arq != NULL, "Erro ao ler arquivo");
  

  fclose(arq);


    
}

// Descrição: constrói uma matriz a partir de um nome de um arquivo de entrada
// Entrada: matrixName
// Saída: matriz construída a partir do arquivo
mat_tipo matrixBuilder(char *matrixName) {

  // Abre o arquivo
  FILE *arq;
  arq = fopen(matrixName, "r");
  erroAssert(arq != NULL, "Erro ao ler arquivo");
  
  int i,j,x,y = 0;

  fscanf(arq, "%d %d", &x, &y);
  mat_tipo mat;
  criaMatriz(&mat, x, y);

  while (!feof(arq))
  {
    for (size_t i = 0; i < mat.tamx; i++)
    {
      for ( j = 0; j < mat.tamy; j++)
      {
        fscanf(arq, "%lf", &mat.m[i][j]);
      }
      
    }
    
  }
  
  fclose(arq);

  return mat;
}


int main(int argc, char ** argv)
// Descricao: programa principal para execucao de operacoes de matrizes 
// Entrada: argc e argv
// Saida: depende da operacao escolhida
{
  // ate 3 matrizes sao utilizadas, dependendo da operacao
  mat_tipo a, b, c;
  a = matrixBuilder(m1Nome);

  // interprete opções de linha de comando
  parseArgs(argc, argv);

  // inicie o registre
  ml.iniciaMemLog(lognome);

  // ative o registro se necessário
  regmem ? ml.ativaMemLog() : ml.desativaMemLog();

  // Verifica a integridade do arquivo
  isFileValid(m1Nome);


  // execução dependente da operação escolhida
  switch (opescolhida) {
      case OPSOMAR: {
          // Verifica a integridade do arquivo
          isFileValid(m2Nome);
          // interprete arquivo contendo matriz 2
          b = matrixBuilder(m2Nome);
          // cria e imprime uma matriz que é a soma das que foram lidas
          // as matrizes são destrúidas automaticamente pelo destrutor
          ml.defineFaseMemLog(1);
          acessaMatriz(&a);
          acessaMatriz(&b);
          somaMatrizes(&a, &b, &c);
          ml.defineFaseMemLog(2);
          acessaMatriz(&c);
          if (regmem) imprimeMatriz(&c);
          break;
      }
      case OPMULTIPLICAR: {
          // interprete arquivo contendo matriz 2
          b = matrixBuilder(m2Nome);
          // cria e imprime uma matriz que é o produto das que foram lidas
          // as matrizes são destrúidas automaticamente pelo destrutor
          ml.defineFaseMemLog(1);
          acessaMatriz(&a);
          acessaMatriz(&b);
          multiplicaMatrizes(&a, &b, &c);
          ml.defineFaseMemLog(2);
          acessaMatriz(&c);
          if (regmem) imprimeMatriz(&c);
          break;
      }
      case OPTRANSPOR: {
          // cria e imprime uma matriz sendo a transposta da matriz lida
          ml.defineFaseMemLog(1);
          acessaMatriz(&a);
          transpoeMatriz(&a);
          ml.defineFaseMemLog(2);
          acessaMatriz(&a);
          if (regmem) imprimeMatriz(&a);
          break;
      }
      // Não deve chegar aqui
      default: printf("Here be dragons!\n"); exit(1);
  }

  // Confira se o arquivo de saída atende o formato
  isFileValid(outNome);

  // conclui o registro
  return ml.finalizaMemLog();
}

