#include <iostream>
#include "HashLE.h"
#include <fstream>

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
    arq.open("entrada.txt");

    while (arq >> acao)
    {
        entrada = acao[0];
        switch (entrada)
        {
            case 'E':
                cin >> id_usuario >> id_email >> num_palavras;
                break;
            
            
        }
    }
    
    arq.close();
    return 0;
}
