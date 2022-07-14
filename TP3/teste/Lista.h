#ifndef LISTA_H
#define LISTA_H
#include "Arvore.h"

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
    void InsereFinal(const Arvore item);
    Arvore Pesquisa(int c);
    void Edita(int c, Email e, int cont);

private:
    TipoCelula* topo = nullptr;
    TipoCelula* ultimo = nullptr;
    TipoCelula* Posiciona(int pos, bool antes);
};


#endif
