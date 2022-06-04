#include <iostream>
#include <regex>
#include <sstream>
#include <unistd.h>
#include <fstream>
#include "Pessoa.h"
#include "msgassert.h"


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
    int pote = 0;
    int pingo = 0;
    int i = 0;
    int j = 0;
    Carta aux;
    string cartageral;

    // abre o arquivo
    ifstream arq;
    arq.open(nomeArq);
    arq >> numRodadas >> saldoInicial;

    // faz a primeira jogada e define as infos dos jogadores
    arq >> numJogadores >> pingo;
    Pessoa jogadores[numJogadores];

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

    
    for ( i = 0; i < numJogadores; i++)
    {
        if (jogadores[i].getValorJogada() >= melhorMao)
        {
            melhorMao = i;
        }
    }

    jogadores[melhorMao].setSaldo(jogadores[melhorMao].getSaldo() + pote);
    cout << 1 << " " << pote << " " << jogadores[melhorMao].getJogada() << endl;
    pote = 0; 
    
    
   
    


    
    
    

    

    // for (i = 0; i < numRodadas -1; i++)
    // {
        
    // }
    


    arq.close();



    
    return 0;
}
