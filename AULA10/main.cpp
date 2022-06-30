#include <iostream>
#include <string>
using namespace std;


int espaco;
class TipoNo
{
    public:
        TipoNo(char item);
        private:
        char item;
        TipoNo *esq;
        TipoNo *dir;
        friend class ArvoreBinaria;
};

TipoNo::TipoNo(char item)
{
    item = '.';
    esq = nullptr;
    dir = nullptr;
}

class ArvoreBinaria
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



char ArvoreBinaria::Pesquisa(char chave) {
    return PesquisaRecursivo(raiz, chave);
}

char ArvoreBinaria::PesquisaRecursivo(TipoNo *no, char chave) {
    char aux;
    if (no == nullptr) {
        aux = '.'; // Flag para item não presente
        return aux;
    }
    if (chave < no->item)
        return PesquisaRecursivo(no->esq, chave);
    else if (chave>no->item)
        return PesquisaRecursivo(no->dir, chave);
    else
        return no->item;
}



void ArvoreBinaria::Insere(char item){
    InsereRecursivo(raiz,item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo* &p, char item){
    if(p==nullptr){
        p = new TipoNo(item);
        p->item = item;
    }
    else{
        if(item < p->item)
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}

void ArvoreBinaria::PreOrdem(TipoNo *p){
    if(p!=nullptr){
        if (espaco != 1)
        {
            cout << " " <<  p->item; 
        }else{
            cout << p->item; 
            espaco = 0;
        }
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }
}

void ArvoreBinaria::InOrdem(TipoNo *p){
    if(p!=NULL){
        InOrdem(p->esq);
        if (espaco != 1)
        {
            cout << " " <<  p->item; 
        }else{
            cout << p->item; 
            espaco = 0;
        }
        InOrdem(p->dir);
    }
    
}

void ArvoreBinaria::PosOrdem(TipoNo *p){
    if(p!=NULL){
        PosOrdem(p->esq);
        PosOrdem(p->dir);
        if (espaco != 1)
        {
            cout << " " <<  p->item; 
        }else{
            cout << p->item; 
            espaco = 0;
        }
    }
}



int main(int argc, char const *argv[])
{
    ArvoreBinaria arvore;
    string statement;
    char aux;
    while(getline(cin,statement)){

        if (statement == "INFIXA")
        {
            espaco = 1;
            arvore.InOrdem(arvore.raiz);
            cout << endl;
            continue;
        }
        else if (statement == "PREFIXA")
        {
            espaco = 1;
            arvore.PreOrdem(arvore.raiz);
            cout << endl;
            continue;
        }
        else if (statement == "POSFIXA")
        {
            espaco = 1;
            arvore.PosOrdem(arvore.raiz);
            cout << endl;
            continue;
        }
        else if (statement[0] == 'P')
        {
            aux = arvore.Pesquisa(statement[2]);
            if (aux == '.')
            {
                cout << statement[2] << " " << "nao existe" << endl;
            }else{
                cout << statement[2] << " " << "existe" << endl;
            }
            
            continue;
        }
        else if (statement[0] == 'I'){
            arvore.Insere(statement[2]);
            continue;
        }


    }
    return 0;
}
