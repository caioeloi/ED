#ifndef HASHLE_H
#define HASHLE_H
#include <iostream>
#include <Lista.h>

using namespace std;

class Hash_LE
{
    public:
        Hash_LE(){};
        int Pesquisa(int chave, int mod);
        void Insere(int item, int mod);
        void Remove(int chave);
        static const int M = 100;
        int Hash(int Chave, int mod);
        Lista Tabela[M];
        
};



#endif