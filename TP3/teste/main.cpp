#include <iostream>
#include "HashLE.h"

int main(int argc, char const *argv[])
{
    Hash_LE tabela_hash;
    int usuario1_id = 1;
    int usuario2_id = 2;
    int usuario3_id = 3;
    int usuario4_id = 4;

    Email spam;
    spam.id = 1;
    spam.mensagem = "Voce foi hackeado!";

    Email spam2;
    spam2.id = 2;
    spam2.mensagem = "Voce foi hackeado dnv kk!";

    
    Arvore u1;
    Arvore u2;
    Arvore u3;
    Arvore u4;

    u1.chave = usuario1_id;
    u1.Insere(spam);
    u1.Insere(spam2);
    u2.chave = usuario2_id;
    u2.Insere(spam);
    u3.chave = usuario3_id;
    u3.Insere(spam);
    u4.chave = usuario4_id;
    u4.Insere(spam);

    u1.PreOrdem(u1.raiz);

    // tabela_hash.Insere(u1);
    // tabela_hash.Insere(u2);
    // tabela_hash.Insere(u3);
    // tabela_hash.Insere(u4);



    

    
    return 0;
}
