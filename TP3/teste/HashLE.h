#ifndef HASHLE_H
#define HASHLE_H
#include <iostream>
#include "Lista.h"
#include "Arvore.h"

using namespace std;

class Hash_LE
{
    public:
        Hash_LE(){};
        Arvore Pesquisa(int chave);
        void Insere(Arvore item);
        void Remove(int chave);
        static const int M = 10;
        int Hash(int Chave);
        Lista Tabela[M];
        
};



#endif