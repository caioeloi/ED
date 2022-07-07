#ifndef ARVORE_H
#define ARVORE_H
#include <iostream>
#include <string>

using namespace std;


class TipoNo
{
    public:
        TipoNo(char item);
        private:
        char item;
        TipoNo *esq;
        TipoNo *dir;
        friend class Arvore;
};



class Arvore
{
    public:
        void Insere(char item);
        char Pesquisa(char chave);
        void Remove(char chave);
        void PreOrdem(TipoNo* p);
        void InOrdem(TipoNo* p);
        void PosOrdem(TipoNo* p);
        void Limpa();
        TipoNo *raiz = nullptr;
    private:
        void InsereRecursivo(TipoNo* &p, char item);
        char PesquisaRecursivo(TipoNo* p, char chave);
        
};


#endif
