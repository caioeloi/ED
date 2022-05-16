#ifndef PESSOA_H
#define PESSOA_H

#include <string>
using namespace std;

class Pessoa
{
private:
    int saldo;
public:
    Pessoa(const string& nome, const int saldo);
    //~Pessoa();
    string nome;
    int getSaldo() const;
    void setSaldo(const int saldo);
    
};



#endif
