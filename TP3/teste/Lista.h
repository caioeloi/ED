#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <string>
#include "Arvore.h"

using namespace std;

class TipoCelula
{
    public:
        TipoCelula(Arvore valor);
    private:
        Arvore item;
        TipoCelula *prox;
    
    friend class Lista;
};


class Lista
{
public:
    Lista();
    int tamanho = 0;
    Arvore GetItem(int pos);
    void InsereInicio(const Arvore item);
    void InsereFinal(const Arvore item);
    Arvore RemovePosicao(int pos);
    void Limpa();

private:
    TipoCelula* topo = nullptr;
    TipoCelula* ultimo = nullptr;
    TipoCelula* Posiciona(int pos, bool antes);
};


#endif