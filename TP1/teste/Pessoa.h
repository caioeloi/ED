#ifndef PESSOA_H
#define PESSOA_H
#include "Carta.h"
#include "Lista.h"

#include <string>
using namespace std;

class Pessoa
{
private:
    int saldo;
    int valorjogada;
    string jogada;
public:
    Pessoa(const string& nome, const int saldo);
    //~Pessoa();
    string nome;
    int getSaldo() const;
    void setSaldo(const int saldo);
    Lista cartas;
    void setJogada();


    bool RoyalStraightFlush();
    bool StraightFlush();
    bool FourOfAKind();
    bool FullHouse();
    bool Flush();
    bool Straight();
    bool ThreeOfAKind();
    bool TwoPairs();
    bool OnePair();
    bool HighCard();


    int getValorJogada();
    string getJogada();
    void ordenaCartas();
    
};



#endif
