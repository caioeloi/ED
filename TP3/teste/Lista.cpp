#include "Lista.h"
#include "Arvore.h"

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
    if ( (pos > tamanho) || (pos <= 0) )
        throw "ERRO: Posicao Invalida!";
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


Arvore Lista::RemoveItem(int c) {;
    Arvore aux; TipoCelula *p, *q;
    // Posiociona p na célula anterior ao item procurado
    p = this->topo;
    while ( (p->prox!=nullptr) && (p->prox->item.chave != c) )
        p = p->prox;
    // remove a célula contendo o item, retornando-o
    if(p->prox == nullptr)
        throw "Erro: item não está presente";
    else {
        q = p->prox;
        p->prox = q->prox;
        aux = q->item;
        delete q;
        this->tamanho--;
        if(p->prox == nullptr) this->ultimo = p;
    }
    return aux;
};



void Lista::Limpa() {
    TipoCelula *p;
    p = topo->prox;
    while (p!=nullptr) {
        topo->prox = p->prox;
        delete p;
        p = topo->prox;
    }
    ultimo = topo;
    tamanho = 0;
};


Arvore Lista::GetItem(int pos){
    TipoCelula *p;
    p = Posiciona(pos);
    return p->item;
}


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