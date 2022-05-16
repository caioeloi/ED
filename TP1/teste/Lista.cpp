#include "Lista.h"

TipoCelula::TipoCelula(char valor){
    this->item = valor;
    this->prox = nullptr;
}

Lista::Lista()
{
    topo = new TipoCelula('1');
    ultimo = topo;

}

Lista::~Lista()
{
    Limpa();
    delete topo;
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




void Lista::InsereInicio(const char item)
{
    TipoCelula *nova;
    nova = new TipoCelula(item);
    nova->item = item;
    nova->prox = topo->prox;
    topo->prox = nova;
    tamanho++;
    if(nova->prox == NULL)
        ultimo = nova;
}

void Lista::InsereFinal(const char item)
{
    TipoCelula *nova;
    nova = new TipoCelula(item);
    nova->item = item;
    ultimo->prox = nova;
    ultimo = nova;
    tamanho++;
};

char Lista::Remove(char carta){;
    char aux;
    TipoCelula *current = topo;
    TipoCelula *previous = nullptr;

    while (current != nullptr){
        if (current->item == carta){
            if(previous == nullptr){
                topo = current->prox;
            }
            else if(current->prox == nullptr){
                previous->prox = nullptr;
                
            }else{
                previous->prox = current->prox;
                delete current;
            }
            return aux;
        }

        previous = current;
        current = current->prox;
    }
    return aux;
}


char Lista::RemovePosicao(int pos) {;
    char aux;
    TipoCelula *p, *q;
    if (tamanho == 0)
        throw "ERRO: Lista vazia!";
    // posiciona p na celula anterior à pos
    p = Posiciona(pos, true);
    q = p->prox;
    p->prox = q->prox;
    tamanho--;
    aux = q->item;
    delete q;
    if(p->prox == NULL)
        ultimo = p;
    return aux;
}






















void Lista::Imprime() {
    TipoCelula *p;
    p = topo->prox;
    while (p!=nullptr) {
        cout << p->item << " ";
        p = p->prox;
    }
    cout << endl;
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