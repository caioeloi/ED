#include "HashLE.h"
#include <fstream>
#include <getopt.h>
#include <iostream>

using namespace std;

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
    string nomeEntrada;
    string nomeSaida;
    nomeEntrada = argv[2]; 
    nomeSaida = argv[4];
    string saida;
    arq.open(nomeEntrada);
    arq >> tam_tab;
    tab_hash.Tabela = new Arvore[tam_tab];

    while (arq >> acao)
    {
        entrada = acao[0];
        switch (entrada)
        {
            case 'E':
                arq >> id_usuario >> id_email >> num_palavras;
                if (num_palavras < 0 || num_palavras > 200 || id_usuario < 0 || id_usuario > 1000000 || id_email < 0 || id_email > 1000000)
                {
                    break;
                }
                
                getline(arq, mensagem);
                mensagem = mensagem.substr(1, mensagem.length());
                aux = tab_hash.Pesquisa(id_usuario, tam_tab);
                // se a arvore não existir...
                if (aux.chave == -1)
                {
                    e_aux.id = id_email;
                    e_aux.mensagem = mensagem;
                    e_aux.id_usuario = id_usuario;
                    tab_hash.Insere(e_aux, tam_tab);
                    saida += "OK: MENSAGEM " + to_string(id_email) + " PARA " + to_string(id_usuario) + " ARMAZENADA EM " + to_string(id_usuario % tam_tab) + '\n';
                // se a arvore existir...
                }else{
                    e_aux.id = id_email;
                    e_aux.mensagem = mensagem;
                    e_aux.id_usuario = id_usuario;
                    if(aux.Pesquisa(e_aux).id != -1){
                        break;
                    }
                    tab_hash.Insere(e_aux, tam_tab);
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
                    if (e_aux.id == -1 || e_aux.id_usuario != id_usuario)
                    {
                        saida += "CONSULTA " + to_string(id_usuario) + ' ' + to_string(id_email) + ": MENSAGEM INEXISTENTE\n";
                    }else{
                        saida += "CONSULTA " + to_string(id_usuario) + ' ' + to_string(id_email) + ": " + e_aux.mensagem + '\n';
                    }
                }else{
                    break;
                }
                break;
                
            case 'A':
                arq >> id_usuario >> id_email;
                aux = tab_hash.Pesquisa(id_usuario, tam_tab);
                if (aux.chave != -1)
                {
                    e_aux.id = id_email;
                    e_aux.id_usuario = id_usuario;
                    e_aux = aux.Pesquisa(e_aux);
                    if (e_aux.id == -1 || e_aux.id_usuario != id_usuario)
                    {
                        saida += "ERRO: MENSAGEM INEXISTENTE\n";
                    }else{
                        tab_hash.Remove(e_aux, tam_tab);
                        saida += "OK: MENSAGEM APAGADA\n";
                    }
                }else{
                    break;
                }
                break;  
        }
    }
    ofstream fout(nomeSaida);
    fout << saida;
    arq.close();
    return 0;
}