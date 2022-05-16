#include "Pessoa.h"

Pessoa::Pessoa(const string& nome, const int saldo){
    this->nome = nome;
    this->saldo = saldo;
}

int Pessoa::getSaldo() const{
    return this->saldo;
}

void Pessoa::setSaldo(const int saldo){
    this->saldo = saldo;
}