#include "HashLE.h"

int Hash_LE::Hash(int chave, int tam_tab){
    return chave % tam_tab;
}

void Hash_LE::Insere(Email item, int tam_tab){
    int pos;
    pos = Hash(item.id_usuario, tam_tab);
    Tabela[pos].Insere(item);
    Tabela[pos].chave = 1;
}

Arvore Hash_LE::Pesquisa(int chave, int tam_tab){
    int pos;
    Arvore item;
    pos = Hash(chave, tam_tab);
    return Tabela[pos];
}

void Hash_LE::Remove(Email chave, int tam_tab){
    int pos;
    pos = Hash(chave.id_usuario, tam_tab);
    Tabela[pos].Remove(chave);
}