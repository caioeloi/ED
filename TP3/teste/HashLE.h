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
        Arvore Pesquisa(int chave, int tam_tab);
        void Insere(Arvore item, int tam_tab);
        void Remove(int chave, int tam_tab);
        static const int M = 10;
        int Hash(int Chave, int tam_tab);
        Lista Tabela[M];
        
};



#endif