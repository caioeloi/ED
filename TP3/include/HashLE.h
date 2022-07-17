#ifndef HASHLE_H
#define HASHLE_H
#include "Arvore.h"

class Hash_LE
{
    public:
        Hash_LE(){};
        Arvore Pesquisa(int chave, int tam_tab);
        void Insere(Email item, int tam_tab);
        void Remove(Email chave, int tam_tab);
        int Hash(int Chave, int tam_tab);
        Arvore *Tabela = new Arvore[1];
        
};

#endif