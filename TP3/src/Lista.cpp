#include "Lista.h"

TipoCelula::TipoCelula(Arvore valor){
    this->item = valor;
    this->prox = nullptr;
}

Lista::Lista()
{
    Arvore aux;
    topo = new TipoCelula(aux);
    ultimo = topo;

}

TipoCelula* Lista::Posiciona(int pos, bool antes=false){
    TipoCelula *p; int i;
    // Posiciona na célula anterior a desejada
    p = topo;
    for(i=1; i<pos; i++){
        p = p->prox;
    }
    // vai para a próxima
    // se antes for false
    if(!antes)
        p = p->prox;
    return p;
}

void Lista::InsereFinal(const Arvore item)
{
    TipoCelula *nova;
    nova = new TipoCelula(item);
    nova->item = item;
    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;
};

Arvore Lista::Pesquisa(int c) {
    Arvore aux; // construtor seta o item para -1;
    TipoCelula *p;
    p = this->topo->prox;
    while (p!=nullptr) {
        if (p->item.chave == c) {
            aux = p->item;
            break;
        }
        p = p->prox;
    }
    return aux;
};

void Lista::Edita(int c, Email e, int cont){
    TipoCelula *p;
    if (cont == 1)
    {
        p = this->topo->prox;
        while (p!=nullptr) {
            if (p->item.chave == c) {
                p->item.Insere(e);
            }
            p = p->prox;
        }
    }else{
        p = this->topo->prox;
        while (p!=nullptr) {
            if (p->item.chave == c) {
                p->item.Remove(e);
            }
            p = p->prox;
        }
    }
}