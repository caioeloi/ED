#include "HashLE.h"

int Hash_LE::Hash(int chave, int tam_tab){
    return chave % tam_tab;
}

void Hash_LE::Insere(Arvore item, int tam_tab){
    int pos;
    pos = Hash(item.chave, tam_tab);
    Tabela[pos].InsereFinal(item);
    
}

Arvore Hash_LE::Pesquisa(int chave, int tam_tab){
    int pos;
    Arvore item;
    pos = Hash(chave, tam_tab);
    item = Tabela[pos].Pesquisa(chave);
    return item;
}
