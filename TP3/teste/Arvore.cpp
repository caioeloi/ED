#include "Arvore.h"

TipoNo::TipoNo(Email item)
{
    item.id = -1;
    esq = nullptr;
    dir = nullptr;
}

Email Arvore::Pesquisa(Email chave) {
    return PesquisaRecursivo(raiz, chave);
}


Email Arvore::PesquisaRecursivo(TipoNo *no, Email chave) {
    Email aux;
    if (no == nullptr) {
        aux.id = -1; // Flag para item não presente
        return aux;
    }
    if (chave < no->item)
        return PesquisaRecursivo(no->esq, chave);
    else if (chave>no->item)
        return PesquisaRecursivo(no->dir, chave);
    else
        return no->item;
}

void Arvore::Insere(Email item){
    InsereRecursivo(raiz,item);
}

void Arvore::InsereRecursivo(TipoNo* &p, Email item){
    if(p==nullptr){
        p = new TipoNo(item);
        p->item = item;
    }
    else{
        if(item < p->item)
            InsereRecursivo(p->esq, item);
        else if(item > p->item)
            InsereRecursivo(p->dir, item);
        else{
            cout << "Item ja inserido." << endl;
        }
    }
}

void Arvore::PreOrdem(TipoNo *p){
    if(p!=nullptr){
        cout << p->item.mensagem << endl;
        PreOrdem(p->esq);
        PreOrdem(p->dir);
    }  
}


void Arvore::Antecessor(TipoNo *q, TipoNo* &r){
    if(r->dir != NULL) {
        Antecessor(q, r->dir);
        return;
    }
    q->item = r->item;
    q = r;
    r = r->esq;
    free(q);
}

void Arvore::Remove(Email chave) {
    return RemoveRecursivo(raiz, chave);
}

void Arvore::RemoveRecursivo(TipoNo* &no, Email chave){
    TipoNo *aux;
    if (no == nullptr) {
        throw("Item nao está presente");
    }
    if (chave < no->item)
        return RemoveRecursivo(no->esq, chave);
    else if (chave>no->item)
        return RemoveRecursivo(no->dir, chave);
    else {
        if (no->dir == nullptr) {
            aux = no;
            no = no->esq;
            free(aux);
        }
        else if(no->esq == NULL) {
            aux = no;
            no = no->dir;
            free(aux);
        }
        else
            Antecessor(no, no->esq);
    }
}