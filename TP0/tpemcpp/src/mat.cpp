#include "mat.h"
#include "memlog.h"
#include "msgassert.h"
#include <iomanip>

int mat_ID = 0;

// Macro que realiza swap sem variavel auxiliar
#define ELEMSWAP(x,y) (x+=y,y=x-y,x-=y)

mat_tipo::mat_tipo(const int &m, const int &n)
{
    //verificando dimensões da matriz
    erroAssert(m > 0, "Dimensão Inválida");
    erroAssert(n > 0, "Dimensão Inválida");

    // inicializa as dimensoes da matriz
    this->tamx = m;
    this->tamy = n;
    this->m = new double *[this->tamx];
    erroAssert(this->m != nullptr, "Erro ao alocar matriz!");
    for (int i = 0; i < this->tamx; i++)
    {
        this->m[i] = new double [this->tamy];
        erroAssert(this->m[i] != nullptr, "Erro ao alocar matriz!");
    }

    
    this->id = mat_ID;
    mat_ID++;

}

void mat_tipo::inicializaMatrizNula()
{
    // Descricao: inicializa mat com valores nulos 
    // Entrada: mat
    // Saida: mat
    int i, j = 0;
    for ( i = 0; i < this->tamx; i++)
    {
        for ( j = 0; j < this->tamy; j++)
        {
            this->m[i][j] = 0;
            ESCREVEMEMLOG((long int)(&(this->m[i][j])),sizeof(double),this->id);
        }
        
    }
    
}

double mat_tipo::acessaMatriz() const
{
    // Descricao: acessa mat para fins de registro de acesso 
    // Entrada: mat 
    // Saida: mat
    int i, j = 0;
    double aux, s = 0.0;
    for ( i = 0; i < this->tamx; i++)
    {
        for ( j = 0; j < this->tamy; j++)
        {
            aux = this->m[i][j];
            s += aux;
            LEMEMLOG((long int)(&(this->m[i][j])),sizeof(double),this->id);
        }
    }
    return s; // apenas para evitar que acesso seja eliminado
    
}

void mat_tipo::imprimeMatriz() const
// Descricao: imprime a matriz com a identificacao de linhas e colunas
// Entrada: mat
// Saida: impressao na saida padrao (stdout) 
{
    int i, j = 0;
    // imprime os identificadores de coluna
    printf("%9s"," ");
    for(j=0; j<this->tamy; j++)
        printf("%8d ",j);
    printf("\n");

    // imprime as linhas
    for (i=0; i<this->tamx; i++){
        printf("%8d ",i);
        for(j=0; j<this->tamy; j++){
            printf("%8.2f ",this->m[i][j]);
            LEMEMLOG((long int)(&(this->m[i][j])),sizeof(double),this->id);
        }
        printf("\n");
    }
}

mat_tipo mat_tipo::operator+(const mat_tipo &b)
{
    erroAssert(this->tamx==b.tamx,"Dimensoes incompativeis");
    erroAssert(this->tamy==b.tamy,"Dimensoes incompativeis");
    mat_tipo c(b.tamx, b.tamy);

    //inicializando a matriz com valores zeros para evitar erro
    c.inicializaMatrizNula();
    int i, j = 0;
    // faz a soma elemento a elemento
    for (i=0; i<this->tamx; i++){
        for(j=0; j<this->tamy; j++){
            c.m[i][j] = this->m[i][j]+b.m[i][j];
            LEMEMLOG((long int)(&(this->m[i][j])),sizeof(double),this->id);
            LEMEMLOG((long int)(&(b.m[i][j])),sizeof(double),b.id);
            ESCREVEMEMLOG((long int)(&(c.m[i][j])),sizeof(double),c.id);
        }
    }
    return c;

}

mat_tipo mat_tipo::operator*(const mat_tipo &b)
{
    // Descricao: multiplica as matrizes a e b e armazena o resultado em c
    // Entrada: a,b
    // Saida: c
    // verifica a compatibilidade das dimensoes 
    erroAssert(this->tamy==b.tamx,"Dimensoes incompativeis");

    // cria e inicializa a matriz c
    mat_tipo c(this->tamx, b.tamx);
    //inicializando a matriz com valores zeros para evitar erro
    c.inicializaMatrizNula();

    int i, j, k = 0;
    for (i=0; i<c.tamx;i++){
        for (j=0; j<c.tamy;j++){
            for (k=0; k<this->tamy;k++){
                c.m[i][j] += this->m[i][k]*b.m[k][j];
                LEMEMLOG((long int)(&(this->m[i][k])),sizeof(double),this->id);
                LEMEMLOG((long int)(&(b.m[k][j])),sizeof(double),b.id);
                ESCREVEMEMLOG((long int)(&(c.m[i][j])),sizeof(double),c.id);
            }
        }
  }

    return c;

}


mat_tipo mat_tipo::transpoeMatriz() const
// Descricao: transpoe a matriz a
// Entrada: a
// Saida: a
{
    // inicializa a matriz resultante, garantindo a compatibilidade das dimensões
    mat_tipo c(this->tamy, this->tamx);
    c.inicializaMatrizNula();

    // copia a matriz original transpondo
    for (int i = 0; i < this->tamx; i++) {
        for (int j = 0; j < this->tamy; j++) {
            c.m[j][i] = this->m[i][j];
            LEMEMLOG((long int)(&(this->m[i][j])), sizeof(double), this->id);
            ESCREVEMEMLOG((long int)&(c.m[j][i]), sizeof(double),
                          c.id);
        }
    }
    return c;
}


// Descrição: retorna o elemento na posição (x,y)
// Entrada: x,y
// Saída: o elemento na posição (x,y)
double mat_tipo::getElement(const int &x, const int &y) const {

    // verifica se x e y são válidos
    erroAssert((x >= 0) && (x < this->tamx), "Índice inválido");
    erroAssert((y >= 0) && (y < this->tamy), "Índice inválido");

    return this->m[x][y];
}

// Descrição: retorna o endereço do elemento na posição (x,y)
// Entrada: x,y
// Saída: o endereço do elemento na posição (x,y)
double *mat_tipo::getAddress(const int &x, const int &y) const {

    // verifica se x e y são válidos
    erroAssert((x >= 0) && (x < this->tamx), "Índice inválido");
    erroAssert((y >= 0) && (y < this->tamy), "Índice inválido");

    return &this->m[x][y];
}

// Descrição: atribui ao elemento na posição (x,y) o valor v
// Entrada: x,y,v
// Saída: --
void mat_tipo::setElement(const int &x, const int &y, const double &v) {

    // verifica se x e y são válidos
    erroAssert((x >= 0) && (x < this->tamx), "Índice inválido");
    erroAssert((y >= 0) && (y < this->tamy), "Índice inválido");

    this->m[x][y] = v;
    ESCREVEMEMLOG((long int)(&(this->m[x][y])), sizeof(double), this->id);
}



mat_tipo::~mat_tipo()
{
    // Descricao: destroi a matriz a, que se torna inacessível
    // Entrada: a
    // Saida: a
    int i;
    for ( i = 0; i < this->tamx; i++)
    {
        delete this->m[i];
    }
    delete this->m;

    this->tamx = -1;
    this->tamy = -1;
}
