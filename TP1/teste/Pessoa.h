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
    string jogada;
public:
    Pessoa(const string& nome, const int saldo);
    //~Pessoa();
    string nome;
    int getSaldo() const;
    void setSaldo(const int saldo);
    Lista cartas;
    string getJogada();
    void ordenaCartas();
    
};



#endif
