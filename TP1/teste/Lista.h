#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;

class TipoCelula
{
    public:
        TipoCelula(char valor);
    private:
        char item;
        TipoCelula *prox;
    
    friend class Lista;
};


class Lista
{
public:
    Lista();
    ~Lista();
    int tamanho = 0;
    void InsereInicio(const char item);
    void InsereFinal(const char item);
    char Remove(const char carta);
    char RemovePosicao(int pos);
    void Limpa();
    void Imprime();

private:
    TipoCelula* topo = nullptr;
    TipoCelula* ultimo = nullptr;
    TipoCelula* Posiciona(int pos, bool antes);
};



#endif
