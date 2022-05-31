#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include <string>
#include "Carta.h"

using namespace std;

class TipoCelula
{
    public:
        TipoCelula(Carta valor);
    private:
        Carta item;
        TipoCelula *prox;
    
    friend class Lista;
};


class Lista
{
public:
    Lista();
    int tamanho = 0;
    Carta GetItem(int pos);
    void InsereInicio(const Carta item);
    void InsereFinal(const Carta item);
    Carta Remove(const Carta carta);
    Carta RemovePosicao(int pos);
    void Limpa();
    void Imprime();

private:
    TipoCelula* topo = nullptr;
    TipoCelula* ultimo = nullptr;
    TipoCelula* Posiciona(int pos, bool antes);
};



#endif
