#include <iostream>
#include <regex>
#include <fstream>
#include "Pessoa.h"
#include "msgassert.h"
#define Troca(A, B) {Pessoa c = A; A = B; B = c; }

bool isFirstLineValid(const string &str) {

    // Esperado: dois inteiros separados por um único espaço
    regex expectedFormat("\\d+\\s\\d+");
    return regex_match(str, expectedFormat);
}

void isFileValid(string &nomeArq){

    // Abre o arquivo
    ifstream arq;
    arq.open(nomeArq);  
    erroAssert(arq.is_open(), "Erro ao abrir arquivo!");

    // Teste a validade da primeira linha
    string firstLine;
    getline(arq, firstLine);
    erroAssert(isFirstLineValid(firstLine),
               "A 1ª linha do arquivo de entrada apresenta inconsistência");
    
    arq.close();

}



void determinaVencedor(Pessoa *jogadores, int numJogadores, int pote){
    int i = 0;
    int j = 0;
    int melhorMao = 0;
    int aux = 0;

    for ( i = 0; i < numJogadores; i++)
    {
        aux = jogadores[i].getValorJogada();
        if (aux > melhorMao)
        {
            melhorMao = aux;
        }
    }
    Pessoa retorno[numJogadores];
    int iterator = 0;


    for ( i = 0; i < numJogadores; i++)
    {
        if (jogadores[i].getValorJogada() == melhorMao)
        {
            retorno[iterator] = jogadores[i];
            iterator++;
        }
        
    }
    float ganhos = (float)(pote / iterator);
    
    for ( i = 0; i < iterator; i++)
    {
        retorno[i].setSaldo(retorno[i].getSaldo() + ganhos);
        
    }
    
    string nomeaux;
    for ( i = 0; i < numJogadores; i++)
    {
        nomeaux = jogadores[i].nome;
        for ( j = 0; j < iterator; j++)
        {
            if (nomeaux == retorno[j].nome)
            {
                jogadores[i] = retorno[j];
            }
            
        }
        
    }
    
    cout << iterator << " " << pote << " " << retorno[0].getJogada() << endl;

    for ( i = 0; i < iterator; i++)
    {
        cout << retorno[i].nome << endl;
    }
    
    

    

}




void ordenaJogadores(Pessoa *jogadores, int numJogadores){
    int i, j, Min;
    for (i = 0; i < numJogadores - 1; i++)
    {
        Min = i;
        for (j = i + 1 ; j < numJogadores; j++)
        {
            if (jogadores[j].getSaldo() > jogadores[Min].getSaldo())
                Min = j;
        }
        Troca(jogadores[i], jogadores[Min]);
    }
    
}



void realizaRodada(Pessoa *jogadores, ifstream& arq, int numJogadores, int numJogada, int saldoInicial){
    // variaveis de montagem
    int i = 0;
    int j = 0;
    int k = 0;
    Carta aux;
    string cartageral;
    int pingo = 0;
    int pote = 0;
    int jogadoresRodada = 0;
    Pessoa jogadorAux;

    // se for a primeira rodada...
    if (numJogada == 1)
    {
        arq >> pingo;
        for (i = 0; i < numJogadores; i++)
        {
            jogadores[i].setSaldo(saldoInicial);
            arq >> jogadores[i].nome >> jogadores[i].aposta;
            pote += jogadores[i].aposta + pingo;
            jogadores[i].setSaldo(jogadores[i].getSaldo() - jogadores[i].aposta - pingo);
            for (j = 0; j < 5; j++)
            {
                arq >> cartageral;
                if (cartageral.length() == 3)
                {
                    aux.numero = stoi(cartageral.substr(0,2));
                    aux.naipe = cartageral[2];
                }else{
                    //faz conversao do char para int :)
                    aux.numero = cartageral[0] - '0';
                    aux.naipe = cartageral[1];
                }
                if (j == 0)
                {
                    jogadores[i].cartas.InsereInicio(aux);
                }else{
                    jogadores[i].cartas.InsereFinal(aux);
                }
            }
            jogadores[i].ordenaCartas();
            jogadores[i].setJogada();
 
        }

        determinaVencedor(jogadores, numJogadores, pote);

        
        // limpa as cartas depois de tudo...
        for ( i = 0; i < numJogadores; i++)
        {
            jogadores[i].cartas.Limpa();
            jogadores[i].setJogada();
        }
        


    }else{
        arq >> jogadoresRodada >> pingo;
        pote += pingo * numJogadores;
        int saldoaux = 0;
        for ( i = 0; i < numJogadores; i++)
        {
            saldoaux = jogadores[i].getSaldo();
            if (saldoaux >= pingo)
            {
                jogadores[i].setSaldo(saldoaux - pingo);
            }
            
            
        }
        

        Pessoa pessoasRodada[jogadoresRodada];
        int achou = 0;

        for ( i = 0; i < jogadoresRodada; i++)
        {
            arq >> jogadorAux.nome;
            for ( j = 0; j < numJogadores; j++)
            {
                if (jogadores[j].nome == jogadorAux.nome)
                {
                    pessoasRodada[i] = jogadores[j];
                    arq >> pessoasRodada[i].aposta;
                    pote += pessoasRodada[i].aposta;
                    pessoasRodada[i].setSaldo(pessoasRodada[i].getSaldo() - pessoasRodada[i].aposta);

                    for (k = 0; k < 5; k++)
                    {
                        arq >> cartageral;
                        if (cartageral.length() == 3)
                        {
                            aux.numero = stoi(cartageral.substr(0,2));
                            aux.naipe = cartageral[2];
                        }else{
                            //faz conversao do char para int :)
                            aux.numero = cartageral[0] - '0';
                            aux.naipe = cartageral[1];
                        }
                        if (k == 0)
                        {
                            pessoasRodada[i].cartas.InsereInicio(aux);
                        }else{
                            pessoasRodada[i].cartas.InsereFinal(aux);
                        }
                        jogadores[j] = pessoasRodada[i];
                    }
                    jogadores[j].ordenaCartas();
                    jogadores[j].setJogada();
                    achou++;
                    break;
                }
            }
            if (achou == 0)
            {
                "Jogador Inexistente!";
                return;
            }

        }
        determinaVencedor(jogadores, numJogadores, pote);
        // limpa as cartas depois de tudo...
        for ( i = 0; i < numJogadores; i++)
        {
            for (j = 0; j < jogadoresRodada; j++)
            {
                if (jogadores[i].nome == pessoasRodada[j].nome)
                {
                    jogadores[i].cartas.Limpa();
                    jogadores[i].setJogada();
                }
                
            }
 
            
        }
        
        

    }

    
}

int main(int argc, char const *argv[])
{
    // verificacoes de arquivo
    string nomeArq = "entrada.txt";
    isFileValid(nomeArq);

    // variaveis para o jogo
    int numRodadas = 0;
    int numJogadores = 0;
    int jogadoresRodada = 0;
    int melhorMao = 0;
    int saldoInicial = 0;
    
    int pingo = 0;
    int i = 0;
    int j = 0;
    int numJogada = 1;
    Carta aux;
    string cartageral;

    // abre o arquivo
    ifstream arq;
    arq.open(nomeArq);
    arq >> numRodadas >> saldoInicial >> numJogadores;
    
    // faz a primeira jogada e define as infos dos jogadores
    Pessoa jogadores[numJogadores];




    for ( i = 0; i < numRodadas; i++)
    {
        realizaRodada(jogadores, arq, numJogadores, numJogada, saldoInicial);
        numJogada++;
    }


    cout << endl << "####" << endl;

    ordenaJogadores(jogadores, numJogadores);

    for ( i = 0; i < numJogadores; i++)
    {
        cout << jogadores[i].nome << " " << jogadores[i].getSaldo() << endl;
    }

    arq.close();

    return 0;
}
