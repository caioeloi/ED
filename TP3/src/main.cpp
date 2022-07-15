#include "HashLE.h"
#include <fstream>
#include <getopt.h>
#include <iostream>

using namespace std;


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
    ifstream arq;


    Hash_LE tab_hash;
    int tam_tab;
    int id_usuario;
    int id_email;
    int num_palavras;
    char entrada;
    string acao;
    string mensagem;
    Email e_aux;
    Arvore aux;
    string nomeEntrada = "entrada.txt";
    string nomeSaida = "saida.txt";
    string saida;
    arq.open(nomeEntrada);
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
                    saida += "OK: MENSAGEM " + to_string(id_email) + " PARA " + to_string(id_usuario) + " ARMAZENADA EM " + to_string(id_usuario % tam_tab) + '\n';

                }else{
                    cont = 1;
                    e_aux.id = id_email;
                    e_aux.mensagem = mensagem;
                    insere_Hash(&tab_hash, tam_tab, id_usuario, e_aux, cont);
                    saida += "OK: MENSAGEM " + to_string(id_email) + " PARA " + to_string(id_usuario) + " ARMAZENADA EM " + to_string(id_usuario % tam_tab) + '\n';
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
                        saida += "CONSULTA " + to_string(id_usuario) + ' ' + to_string(id_email) + ": MENSAGEM INEXISTENTE\n";
                    }else{
                        saida += "CONSULTA " + to_string(id_usuario) + ' ' + to_string(id_email) + ": " + e_aux.mensagem + '\n';
                    }
                }else{
                    saida += "ERRO: " + to_string(id_usuario) + ' ' + to_string(id_email) + ": USUARIO INEXISTENTE" + '\n';
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
                        saida += "ERRO: MENSAGEM INEXISTENTE\n";
                    }else{
                        hashing = id_usuario % tam_tab;
                        tab_hash.Tabela[hashing].Edita(id_usuario, e_aux, 2);
                        saida += "OK: MENSAGEM APAGADA\n";
                    }
                }else{
                    saida += "ERRO: " + to_string(id_usuario) + ' ' + to_string(id_email) + ": USUARIO INEXISTENTE" + '\n';
                }
                break;  
        }
    }
    ofstream fout(nomeSaida);
    fout << saida;
    arq.close();
    return 0;
}
