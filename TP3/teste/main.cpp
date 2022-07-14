#include <iostream>
#include "HashLE.h"
#include <fstream>

void insere_Hash(Hash_LE *tab_hash ,int tam_tab, int chave, Email infos, int cont){
    Arvore aux;
    int hashiando = 0;
    if (cont == 0)
    {
        aux.chave = chave;
        aux.Insere(infos);
        tab_hash->Insere(aux, tam_tab);

    }else{
        hashiando = chave % tam_tab;
        tab_hash->Tabela[hashiando].Edita(chave, infos, 1);
    }
    
}

int main(int argc, char const *argv[])
{

    Hash_LE tab_hash;
    int tam_tab;
    int id_usuario;
    int id_email;
    int num_palavras;
    char entrada;
    string acao;
    ifstream arq;
    string mensagem;
    Email e_aux;
    Arvore aux;
    arq.open("entrada.txt");
    arq >> tam_tab;
    int hashing;
    int cont = 0;

    while (arq >> acao)
    {
        entrada = acao[0];
        switch (entrada)
        {
            case 'E':
                arq >> id_usuario >> id_email >> num_palavras;
                getline(arq, mensagem);
                mensagem = mensagem.substr(1, mensagem.length());
                aux = tab_hash.Pesquisa(id_usuario, tam_tab);
                if (aux.chave == -1)
                {
                    cont = 0;
                    e_aux.id = id_email;
                    e_aux.mensagem = mensagem;
                    insere_Hash(&tab_hash, tam_tab, id_usuario, e_aux, cont);
                    cout << "OK: MENSAGEM " << id_email << " PARA " << id_usuario << " ARMAZENADA EM " << id_usuario % tam_tab << endl;

                }else{
                    cont = 1;
                    e_aux.id = id_email;
                    e_aux.mensagem = mensagem;
                    insere_Hash(&tab_hash, tam_tab, id_usuario, e_aux, cont);
                    cout << "OK: MENSAGEM " << id_email << " PARA " << id_usuario << " ARMAZENADA EM " << id_usuario % tam_tab << endl;
                }
                break;

            case 'C':
                arq >> id_usuario >> id_email;
                aux = tab_hash.Pesquisa(id_usuario, tam_tab);
                if (aux.chave != -1)
                {
                    e_aux.id = id_email;
                    e_aux = aux.Pesquisa(e_aux);
                    if (e_aux.id == -1)
                    {
                        cout << "CONSULTA " << id_usuario << ' ' << id_email << ": MENSAGEM INEXISTENTE" << endl;
                    }else{
                        cout << "CONSULTA " << id_usuario << ' ' << id_email << ": " << e_aux.mensagem << endl;
                    }
                }else{
                    cout << "ERRO: " << id_usuario << ' ' << id_email << ": USUARIO INEXISTENTE" << endl;
                }
                break;
                
            case 'A':
                arq >> id_usuario >> id_email;
                aux = tab_hash.Pesquisa(id_usuario, tam_tab);
                if (aux.chave != -1)
                {
                    e_aux.id = id_email;
                    e_aux = aux.Pesquisa(e_aux);
                    if (e_aux.id == -1)
                    {
                        cout << "ERRO: MENSAGEM INEXISTENTE" << endl;
                    }else{
                        hashing = id_usuario % tam_tab;
                        tab_hash.Tabela[hashing].Edita(id_usuario, e_aux, 2);
                        cout << "OK: MENSAGEM APAGADA" << endl;
                    }
                }else{
                    cout << "ERRO: " << id_usuario << ' ' << id_email << ": USUARIO INEXISTENTE" << endl;
                }

                break;  
        }
    }
    arq.close();
    return 0;
}
