#ifndef ARVORE_H
#define ARVORE_H
#include <iostream>
#include <string>
#include "Email.h"
#include "msgassert.h"
using namespace std;


class TipoNo
{
    public:
        TipoNo(Email item);
        private:
        Email item;
        TipoNo *esq;
        TipoNo *dir;
        friend class Arvore;
};



class Arvore
{
    public:
        int chave;
        void Insere(Email item);
        Email Pesquisa(Email chave);
        void Remove(Email chave);
        void PreOrdem(TipoNo* p);
        //void InOrdem(TipoNo* p);
        //void PosOrdem(TipoNo* p);
        TipoNo *raiz = nullptr;
    private:
        void InsereRecursivo(TipoNo* &p, Email item);
        Email PesquisaRecursivo(TipoNo* p, Email chave);
        void RemoveRecursivo(TipoNo* &p, Email chave);
        void Antecessor(TipoNo* q, TipoNo* &r);

        
};


#endif
