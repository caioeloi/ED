#ifndef ARVORE_H
#define ARVORE_H
#include "Email.h"

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
        int chave = -1;
        void Insere(Email item);
        Email Pesquisa(Email chave);
        void Remove(Email chave);
        TipoNo *raiz = nullptr;
    private:
        void InsereRecursivo(TipoNo* &p, Email item);
        Email PesquisaRecursivo(TipoNo* p, Email chave);
        void RemoveRecursivo(TipoNo* &p, Email chave);
        void Antecessor(TipoNo* q, TipoNo* &r);
};
#endif