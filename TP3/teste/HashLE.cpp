#include "HashLE.h"


int Hash_LE::Hash(int chave){
    return chave % this->M;
}


void Hash_LE::Insere(Arvore item){
    Arvore aux;
    int pos;
    aux = Pesquisa(item.chave);
    if(!aux.chave == -1)
        throw("Erro: Item já está presente");
    pos = Hash(item.chave);
    Tabela[pos].InsereFinal(item);
}

Arvore Hash_LE::Pesquisa(int chave){
    int pos;
    Arvore item;
    pos = Hash(chave);
    item = Tabela[pos].Pesquisa(chave);
    return item;
}

void Hash_LE::Remove(int chave){
    int pos;
    pos = Hash(chave);
    Tabela[pos].RemoveItem(chave);

}